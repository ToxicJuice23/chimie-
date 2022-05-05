#include "encoder.cpp"

int main() {
  encoder* Encoder = new encoder();
  /*General->register_user("jujur","hehe","toxicjuice");
  vector<string> result = Encoder->read(".users");
  for (string x : result) {
    cout << x << "\n";
  }*/
  User* user = Chimie_login::login();
}