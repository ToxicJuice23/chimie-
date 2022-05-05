#include "encoder.h"

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

User* Chimie_login::login() {
  vector<string> users = Encoder->read(".users");
  cout << "Enter your username? ";
  string username; cin >> username;
  cout << "\nEnter your email? ";
  string email; cin >> email;
  cout << "\nEnter your password? ";
  string password; cin >> password;
  for (string x : users) {
    if (x == email+","+password+","+username) { 
      cout << "Lets gooooo\n";
      Encoder->write(".cache", Encoder->encode(username+","+email+","+password), 'w');
      return new User(email, password, username);
    } else {
      cout << email+","+password+","+username << " vs " << x;
    }
  }

  return nullptr;
}

User* Chimie_login::register_user(string email, string password, string username) {
  Encoder->write(".users", Encoder->encode(email)+","+Encoder->encode(password)+","+Encoder->encode(username)+"\n");
  return new User(email, password, username);
}

void Chimie_login::logout() {
  Encoder->write(".cache", "", 'w');
}

vector<string> split(string _string, char delimiter) {
  vector<string> result;
  int index = 0;
  string current_part;
  for (char x : _string) {
    if (x == delimiter) {
      
    }
    index++
  }
}

User* Chimie_login::logged_in() {
  vector<string> result = Encoder->read(".cache");
  if (result != "") {
    return new User()
  }
}