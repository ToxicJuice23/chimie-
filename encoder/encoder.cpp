#include "encoder.h"

bool Chimie_login::has_char(string _string, char wanted) {
  for (char x : _string) {
    if (x == wanted) {
      return true;
    }
  }
  return false;
}

string encoder::vector_to_string(vector<char> v) { 
  string s(v.begin(), v.end());
  return s;
}

int encoder::write(string filename, string _string, char method='a') {
  if (method == 'a') {
    fstream file; file.open(filename, ios_base::app);
    file << _string;
    file.close();
  } else {
    fstream file; file.open(filename, ios::out);
    file << _string;
    file.close();
  }
  return 0;
}

string encoder::encode(string _string) {
  vector<char> _result;
  for (char character : _string) {
    for (pair<char, char> _pair : letters) {
      if (character == _pair.first) {
        _result.push_back(_pair.second);
        break;
      }
    }
  }
  return this->vector_to_string(_result);
}

string encoder::translate(string encoded) {
  vector<char> _result;
  int x = 0;
  for (char character : encoded) {
    for (pair<char, char> _pair : letters) {
      if (character == _pair.second) {
        _result.push_back(_pair.first);
        break;
      }
    }
    x++;
  }
  return this->vector_to_string(_result);
}

vector<string> encoder::read(string filename) {
  fstream file; file.open(filename, ios::in);
  string line;
  vector<string> lines;
  while (getline(file, line)) {
    lines.push_back(this->translate(line));
  }
  return lines;
}

User::User(string email, string password, string username) {
  this->email = this->Encoder->encode(email);
  this->password = this->Encoder->encode(password);
  this->username = this->Encoder->encode(username);
}

User* Chimie_login::login(string email, string password, string username) {
  vector<string> users = Encoder->read("encoder/.users");
  for (string x : users) {
    if (x == email+","+password+","+username) { 
      cout << "Bienvenue "+username+"!\n";
      Encoder->write("encoder/.cache", Encoder->encode(email+","+password+","+username), 'w');
      is_logged_in = true;
      return new User(email, password, username);
    }
    cout << "\nIl n'y existe pas de comptes avec ces donnees\n";
    return nullptr;
  }

  return nullptr;
}

User* Chimie_login::register_user(string email, string password, string username) {
  Encoder->write("encoder/.users", Encoder->encode(email)+","+Encoder->encode(password)+","+Encoder->encode(username)+"\n");
  is_logged_in = true;
  cout << "Bienvenue "+username+"!\n";
  Encoder->write("encoder/.cache", Encoder->encode(email+","+password+","+username), 'w');
  return new User(email, password, username);
}

void Chimie_login::logout() {
  Encoder->write("encoder/.cache", "", 'w');
  is_logged_in = false;
}

User* Chimie_login::logged_in() {
  vector<string> result = Encoder->read("encoder/.cache");
  vector<int> comma_locations;
  int index = 0;
  if (!result.empty()) {
    for (char x : result[0]) {
      if (x == ',') {
        comma_locations.push_back(index);
      }
      index++;
    }
    string email = result[0].substr(0, comma_locations[0]);
    string password = result[0].substr(comma_locations[0] + 1, comma_locations[1] - comma_locations[0] - 1);
    string username = result[0].substr(comma_locations[1] + 1, result[0].length() - comma_locations[1]);
    cout << "Bienvenue "+username+"!";
    is_logged_in = true;
    return new User(email, password, username);
  } else {
    cout << "Aucun utilisateur est connecte\n";
    is_logged_in = false;
    return NULL;
  }
}

vector<string> User::get_info() {
  return vector<string> {this->username, this->email};
}
