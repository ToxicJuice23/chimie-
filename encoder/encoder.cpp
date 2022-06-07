#include "encoder.h"
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

void printVector(vector<int> vec) {
  for (int x : vec) {
    cout << x << endl;
  }  
}

void printVector(vector<string> vec) {
  for (string x : vec) {
    cout << x << endl;
  }  
}

void printVector(vector<double> vec) {
  for (double x : vec) {
    cout << x << endl;
  }  
}

void printVector(vector<bool> vec) {
  for (bool x : vec) {
    cout << x << endl;
  }  
}

void printVector(vector<char> vec) {
  for (char x : vec) {
    cout << x << endl;
  }  
}

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

string exec(const char* cmd) {
    array<char, 128> buffer;
    string result;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

vector<string> Chimie_login::get_values(string filename, int line) {
  // command to get whats on the line (works fine)
  string tmp = "head -"+to_string(line)+" "+filename;
  // execute the command (works)
  string all = exec(tmp.c_str());
  // translate encoded into regular text
  string regular = Encoder->translate(all);
  vector<int> comma_locations = {-1};
  int index = 0;
  if (!regular.empty()) {
    for (char x : regular) {
      if (x == ',') {
        comma_locations.push_back(index);
      }
      index++;
    }
    comma_locations.push_back(regular.length());
    // printVector(comma_locations);
    vector<string> final;
    // WORKS UNTIL HERE :(
    for (int x = 0; x < comma_locations.size() - 1; x++) {
      final.push_back(regular.substr(comma_locations[x] + 1, comma_locations[x+1] - comma_locations[x] - 1));
    }
    return final;
    } else {
      cout << "Il n'y a pas de valeur sur cette ligne\n";
      return vector<string> {};
    }
}

void Chimie_login::update_count(string filename, int line, int value) {
  vector<string> before = get_values(filename, line);
  string new_ = before[0]+","+before[1]+","+to_string(stoi(before[2]) + value);
  fstream ifile; ifile.open(filename, ios::in); string line_; vector<string> lines;
  while(getline(ifile, line_)) {
    lines.push_back(line_);
  }
  lines.erase(lines.begin() + (line - 1));
  lines.insert(lines.begin() + (line - 1), Encoder->encode(new_));
  system(("> " + filename).c_str());
  for (string tmp : lines) {
    system(("echo '"+tmp+"' >> "+filename).c_str());
  }
}

int Chimie_login::get_user_id() {
  string logged_in = Encoder->read("encoder/.cache")[0];
  vector<string> all_users = Encoder->read("encoder/.users");
  int line = 0;
  for (string user : all_users) {
    line++;
    if (user == logged_in) {
      return line;
    }
  }
  return 0;
}

bool Chimie_login::already_used(string username) {
  vector<string> res = Encoder->read("encoder/.users");
  for (string x : res) {
    int length = username.length();
    string registered = x.substr(0, length);
    if (registered == username) {
      return true;
    }
  }
  return false;
}

User::User(string username, string password) {
  this->password = password;
  this->username = username;
}

User* Chimie_login::login(string username, string password) {
  vector<string> users = Encoder->read("encoder/.users");
  int current_line = 1;
  for (string x : users) {
    vector<string> user = get_values("encoder/.users", current_line);
    if (user[0]+","+user[1] == username+","+password) { 
      Encoder->write("encoder/.cache", Encoder->encode(username+","+password+","+user[2]), 'w');
      is_logged_in = true;
      return new User(username, password);
    }
    current_line++;
  }
  cout << "\nIl n'y existe pas de comptes avec ces donnees\n";
  return nullptr;
}

User* Chimie_login::register_user(string username, string password) {
  Encoder->write("encoder/.users", Encoder->encode(username)+","+Encoder->encode(password+","+to_string(0))+"\n");
  is_logged_in = true;
  Encoder->write("encoder/.cache", Encoder->encode(username+","+password+","+to_string(0)), 'w');
  return new User(username, password);
}

void Chimie_login::logout() {
  Encoder->write("encoder/.cache", "", 'w');
  is_logged_in = false;
}

User* Chimie_login::logged_in() {
  vector<string> user = get_values("encoder/.cache", 1);
  if (!user.empty()) {
    string username = user[0];
    string password = user[1];
    is_logged_in = true;
    return new User(username, password);
  } else {
    cout << "Aucun utilisateur est connecte\n";
    is_logged_in = false;
    return NULL;
  }
}

vector<string> User::get_info() {
  return vector<string> {this->username, this->password};
}