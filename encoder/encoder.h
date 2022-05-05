#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#define p(x,y) make_pair(x,y)
using namespace std;

class encoder {
  private:
    vector<pair<char, char>> letters = {
      make_pair('a',char(1)), make_pair('b',char(3)), make_pair('c',char(2)), make_pair('d',char(5)), p('d',char(6)), p('e',char(4)), p('f',char(7)), p('g',char(9)), p('h',char(11)), p('i',char(10)), p('j',char(8)), p('k',char(13)), p('l',char(12)), p('m',char(14)), p('n',char(15)), p('o',char(16)), p('p',char(17)), p('q',char(20)), p('r',char(19)), p('s',char(18)), p('t',char(24)), p('u',char(22)), p('v',char(23)), p('w',char(21)), p('x',char(26)), p('y',char(25)), p('z',char(27)), p(' ',char(28))
    };
  public:
    string encode(string _string);
    string translate(string encoded);
    string vector_to_string(vector<char> v);
    int write(string filename, string _string, char method);
    vector<string> read(string filename);
};

class User {
  private:
    string username;
    string password;
    string email;
    encoder* Encoder = new encoder();
  public:
    User(string email, string password, string username);
    bool logged_in = false;
    bool login();
    bool register_user();
};