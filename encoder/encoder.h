#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#define p(x,y) make_pair(x,y)
using namespace std;

class User;

class encoder {
  private:
    vector<pair<char, char>> letters = {
      make_pair('a',char(1)), make_pair('b',char(3)), make_pair('c',char(2)), make_pair('d',char(5)), make_pair('d',char(6)), make_pair('e',char(4)), make_pair('f',char(7)), make_pair('g',char(9)), make_pair('h',char(11)), make_pair('i',char(29)), make_pair('j',char(8)), make_pair('k',char(129)), make_pair('l',char(12)), make_pair('m',char(14)), make_pair('n',char(15)), make_pair('o',char(16)), make_pair('p',char(17)), make_pair('q',char(20)), make_pair('r',char(19)), make_pair('s',char(18)), make_pair('t',char(24)), make_pair('u',char(22)), make_pair('v',char(23)), make_pair('w',char(21)), make_pair('x',char(26)), make_pair('y',char(25)), make_pair('z',char(27)), make_pair(char(32),char(28)), make_pair(char(44),char(44)), make_pair('A',char(29)), make_pair('B',char(31)), make_pair('C',char(30)), make_pair('D',char(32)), make_pair('E',char(33)), make_pair('F',char(35)), make_pair('G',char(34)), make_pair('H',char(36)), make_pair('I',char(37)), make_pair('J',char(38)), make_pair('K',char(39)), make_pair('L',char(41)), make_pair('M',char(40)), make_pair('N',char(42)), make_pair('O',char(43)), make_pair('P',char(45)), make_pair('Q',char(46)), make_pair('R',char(48)), make_pair('S',char(47)), make_pair('T',char(49)), make_pair('U',char(50)), make_pair('V',char(51)), make_pair('W',char(52)), make_pair('X',char(53)), make_pair('Y',char(54)), make_pair('Z',char(55)), make_pair('1',char(56)), make_pair('2',char(57)), make_pair('3',char(58)), make_pair('4',char(59)), make_pair('5',char(60)), make_pair('6',char(61)), make_pair('7',char(62)), make_pair('8',char(64)), make_pair('9',char(63)), make_pair('0',char(65)), make_pair('-',char(66)), make_pair('=',char(67)), make_pair('!',char(68)), make_pair(char(34),char(69)), make_pair('£',char(70)), make_pair('$',char(71)), make_pair('%',char(73)), make_pair('^',char(72)), make_pair('&',char(74)), make_pair('*',char(75)), make_pair('(',char(76)), make_pair(')',char(77)), make_pair('_',char(79)), make_pair('+',char(78)), make_pair(char(96),char(80)), make_pair('¬',char(81)), make_pair('¦',char(82)), make_pair(']',char(89)), make_pair('{',char(90)), make_pair('}',char(91)), make_pair(';',char(92)), make_pair('~',char(95)), make_pair('<',char(96)), make_pair('>',char(97)), make_pair('.',char(98)), make_pair('/',char(99)), make_pair('?',char(100)), make_pair('\\',char(101)), make_pair('|',char(102)), make_pair('@',char(103))
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
    encoder* Encoder = new encoder();
  public:
    User(string username, string password);
    bool logged_in = true;
    vector<string> get_info();
};
bool is_logged_in;
encoder* Encoder = new encoder();
class Chimie_login {
  public:
    static User* login(string username, string password);
    static User* register_user(string username, string password);
    static void logout();
    static User* logged_in();
    static bool already_used(string username);
    static bool has_char(string _string, char wanted);
    //static vector<string> get_values(string filename);
};