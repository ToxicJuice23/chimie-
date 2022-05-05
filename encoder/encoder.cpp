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

bool User::login() {
  vector<string> users = this->Encoder->read(".users");
}

bool User::register_user() {
  this->Encoder->write(".users", this->email+this->username+this->password+"\n");
}