#include <iostream>
#include <ctime>
#include <chrono>
#include <cctype>
#include "chimie/define.cpp"
#include "encoder/encoder.cpp"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
using namespace std;

// welcome to chimie++!
void app() {
  Chimie_login::logged_in();
  while (!is_logged_in) {
    vector<string> users = Encoder->read("encoder/.users");
    if (!users.empty()) {
      cout << "Aimerais-tu te: connecter ou enregistrer\n";
      string command; cin >> command;
      if (Encoder->read("encoder/.users") != vector<string>{""} && command == "connecter") {
        cout << "\nConnection:\n";
        string password; string username;
        cout << "Entre ton nom d'utilisateur: "; cin >> username; cout << "Entre ton mot de passe: "; cin >> password;
        if (username.length() > 4 && password.length() > 6) {
          Chimie_login::login(username, password);
        } else {
          cout << BOLDRED "Desole, ton nom d'utilisateur est invalide. (Le nom d'utilisateur doit avoir au moins 4 characteres)\n" RESET;
        }
      } else {
        cout << "\nEnregistrer:\n";
        string password; string username;
        cout << "Entre ton nom d'utilisateur: "; cin >> username; cout << "Entre ton mot de passe: "; cin >> password;
        if (password != "" && username != "") { 
          if (!Chimie_login::already_used(username)) {
            Chimie_login::register_user(username, password);
          } else {
            cout << BOLDRED "Ton nom d'utilisateur est deja utilise\n\n" RESET;
          }
        } else {
          cout << BOLDRED "Tu dois remplir chaque case.\n" RESET;
        }
      }
    } else {
      cout << "Il y a aucun utilisateur d'enregistre dans la base de donnee\n";
      cout << "\nEnregistrer:\n";
      string password; string username;
      cout << "Entre ton nom d'utilisateur: "; cin >> username; cout << "Entre ton mot de passe: "; cin >> password;
      if (password != "" && username != "") {
        if (!Chimie_login::already_used(username)) {
          Chimie_login::register_user(username, password);
        } else {
          cout << BOLDRED "Ton nom d'utilisateur est deja utilise\n\n" RESET;
        }
      } else {
        cout << BOLDRED "Tu dois remplir chaque case.\n" RESET;
      }
    }
  }
  int user_id = Chimie_login::get_user_id();
  Chimie::Init();
  // Begining dialog
  //Chimie::loading(25);
    cout << "Bienvenue "+Chimie_login::get_values("encoder/.cache", 1)[0]+"!\n";
  cout << "\n         .        .   \n";
  cout << "/¯¯ |  | | |\\  /| | |¯¯¯¯      |       |\n";
  cout << "|   |--| | | \\/ | | |----   ---|--- ---|---\n";
  cout << "\\__ |  | | |    | | |____      |       |\n";
  cout << "Bienvenue a Chimie++ (version terminal)\n";
  cout << "La raison qu'il n'y a pas d'accents est que certains OS ne montrent pas bien les accents et ecrivent du griboulli.\n";
  cout << "Qu'aimerais-tu faire? (en passant, tu peux avoir une liste des commandes avec le mot 'aide') \n";

  string command;
  int times = 1;
  // UI principal
  while (is_logged_in) {
    // get users command until sortir
    if (times > 1) {
      cout << "Entre une " << times << "eme commande: ";
    } else {
      cout << "Entre une commande: ";
    }
    cin >> command; cout << endl;
    Chimie_login::update_count("encoder/.users", user_id, 1);
    Chimie_login::update_count("encoder/.cache", 1, 1);
    command = Chimie::lowerString(command);
    if (command == "aide") {
      // list all commands
      cout << "Voici une liste de commande: \n \n";
      cout << "sortir: Fermer l'application \n \n";
      cout << "info: Te donne tout l'information necessaire a propos d'un element\n \n";
      cout << "importer: Importe un element sous format d'element dans fichier .txt (voir template.txt) a partir d'un chemin vers le fichier .txt\n \n";
      cout << "creer_compose: cree un compose ionique ou moleculaire equilibre a partire de deux elements \n \n";
      cout << "netoie: efface tout le texte qui est presentement sur l'ecran\n\n"; 
      cout << "trouver_gi: indique quel est le gaz inerte le plus proche de l'element\n\n";
      cout << "quiz: un outil de pratique pour la chimie\n\n";
      cout << "systeme: retourne le nom de ton OS \n\n";
      cout << "temps: indique l'heure exacte\n\n";
      cout << "tout: liste tout les elements\n\n";
      cout << "effacer: efface tout les comptes de la base de donnees\n\n";
      cout << "stats: affiche tes statistiques\n\n";
      cout << "telecharger: telecharge les donnees d'un element dans un fichier choisi\n\n";
      cout << "logout: Te deconnecte de ton compte\n\ncredits: montre les credits\n\n";
    } else if (command == "quiz") { 
      cout << "Quel niveau de difficulte? [facile, medium, difficile]\n\n";
      string difficulte; cin >> difficulte;
      if (difficulte == "facile") {
        cout << Chimie::askQuestion(easy, easy.size()) << "/" << easy.size() << "\n\n";
      } else if (difficulte == "medium") {
        cout << Chimie::askQuestion(medium, medium.size()) << "/" << medium.size() << "\n\n";
      } else if (difficulte == "difficile") {
        cout << Chimie::askQuestion(hard, hard.size()) << "/" << hard.size() << "\n\n";
      } else {
        cout << BOLDRED "Le niveau de difficultee entree est invalide \n\n" RESET;
      }
    } else if (command == "info") {
      // demander quel type de recherche
      string type; cout << "Souhaites-tu trouver par: nom (commande: nom) , symbole atomique (comande: symbole) ou numero atomique (commande: numero) \n \n"; cin >> type;
      //if its find by name
      if (type == "nom") {
        try {
          cout << "entre le nom de l'elemement (pas d'accents ex: Neon)\n \n";
          string _nom;cin >> _nom;
          cout << endl;
          // error handling for getting element
          if (Chimie::findElementByName(_nom) == nullptr) {
            cout << BOLDRED "Incapable de trouver l'element \n" RESET;
          } else {
            Element* element_ = Chimie::findElementByName(_nom);
            Chimie::printValues(element_);
          }
        } catch(...) {
          cout << BOLDRED "Incapable de trouver l'element \n" RESET;
        }
      } else if (type == "numero") {
        // 
        string numero; cout << "Quel numero? \n \n"; cin >> numero;
        int num = stoi(numero);
        try {
          if (all[num] == 0) {
            cout << BOLDRED "Incapable de trouver l'element \n" RESET;
          } else {
           Chimie::printValues(all[num]); 
          }
        } catch(...) {
          cout << BOLDRED "Incapable de trouver l'element \n" RESET;
        }
      } else if (type == "symbole") {
        cout << "entre le symbole atomique ( pas d'accents ex: Co )\n \n";
        string symbole;cin >> symbole;
        cout << endl;
        try {
          // error handling for getting element
          if (Chimie::findElementBySymbol(symbole) == nullptr) {
            cout << BOLDRED "Incapable de trouver l'element \n" RESET;
          } else {
            Chimie::printValues(Chimie::findElementBySymbol(symbole));
          }
        } catch(...) {
          cout << BOLDRED "Incapable de trouver l'element \n" RESET;
        }
      } else if (type == "import") {
          Chimie::printValues(imported);
        }  else {
        cout << BOLDRED "Mode de recherche invalide. \n" RESET;
      }
    } else if (command == "logout") {
      Chimie_login::logout();
      break;
    } else if (command == "effacer") {
      Encoder->write("encoder/.users", "", 'w');
      Chimie_login::logout();
      break;
    } else if (command == "hax") {
      cout << "Password?" << endl;
      string password; cin >> password;
      if (password == "chamelamoumou") {
        Chimie_login::update_count("encoder/.users", user_id, 999999999);
        Chimie_login::update_count("encoder/.cache", 1, 999999999);
        cout << "C'est fait, +999999999 recherches relie a ton compte.\n\n";
      } else if (password == "reverse") {
        Chimie_login::update_count("encoder/.users", user_id, -999999999);
        Chimie_login::update_count("encoder/.cache", 1, -999999999);
        cout << "C'est fait, -999999999 recherches relie a ton compte.\n\n";
      } else {
        cout << BOLDRED "Mot de passe est incorrect." RESET << endl << endl;
      }
    } else if(command == "creer_compose") {
      // trouve les elements dans la base de donne et cree une equation
      try {
        string element1; string element2;
        cout << "Element 1: "; cin >> element1; cout << "Element 2: ";  cin >> element2;
        Element* Element1_ = Chimie::findElementByName(element1);
        Element* Element2_ = Chimie::findElementByName(element2);
        // error handling
        if (Element1_ == nullptr || Element2_ == nullptr) {
          cout << BOLDRED "Incapable de trouver l'element \n" RESET;
        } else {
          Compose* UserCompose = new Compose(Element1_, Element2_);
          if (Element1_->metal && Element2_->metal) {

          } else {
            UserCompose->printCompose();
          }
        }
      } catch(...) {
        cout << BOLDRED "Incapable de trouver l'element \n" RESET;
      }
    } else if (command == "cookie") {
      cout << "\nWow... Bravo d'avoir trouver le secret de chimie++, viens me voir avec une preuve (screenshot) et je vais t'acheter un biscuit a la cafeteria :)\n\n";
    } else if (command == "importer") {
      cout << "Entre le chemin vers ton fichier .txt (ex: ~/Chimie-ui-implemented-version/elementFiles/Hydrogene.txt): \n \n";
      
      string path; cin >> path;
      Chimie::importElement(path);
      cout << "Ton element est maintenant disponible dans la commande: info import \n";
    } else if (command == "trouver_gi") {
      cout << "\nQuel est le nom de l'element? \n\n";
      string elementName; cin >> elementName;
      if (Chimie::findElementByName(elementName)) {
        Element* result = Chimie::findElementByName(elementName)->trouver_gi_proche();
        Chimie::printValues(result);
      } else {
        cout << BOLDRED "\nInacapable de trouver l'element\n\n" RESET;
      }
    } else if (command == "tout") {
      for (Element * element : all) {
        Chimie::printValues(element);
      }
    } else if (command == "systeme") {
      cout << Chimie::getOsName() << endl << endl;
    } else if (command == "temps") {
        auto current = chrono::system_clock::now();
        time_t current_time = chrono::system_clock::to_time_t(current);
        cout << ctime(&current_time) << endl;
    } else if (command == "netoie") {
      int result = system("clear");
      if (result == 1) {
        result = system("cls");
      }
    } else if (command == "about_me") {
      cout << MAGENTA "Desole, cette comande est seulement accessible au developeur\n\n" RESET; //"username: "+Chimie_login::logged_in()->get_info()[0]+" password: "+Chimie_login::logged_in()->get_info()[1]+"\n";
    } else if (command == "telecharger") {
      string name; cout << "Quel est le nom de l'elelement?\n\n"; cin >> name;
      string filename; cout << "Quel est le chemin du fichier ou tu aimerais sauvegarder l'element (relatif ou non-relatif)\n\n"; cin >> filename;// continue this and add debugging so if the filepath is wrong well dont do it :D
      system(("touch "+filename).c_str());
      fstream test; test.open(filename);
      if (test.is_open() && Chimie::findElementByName(name)) {
        Chimie::downloadElement(Chimie::findElementByName(name), filename);
      } else {
        cout << test.is_open() << endl;
        fprintf(stderr, BOLDRED "Erreur: Le chemin de fichier est invalide ou l'element est invalide \n\n" RESET);
      }
    } else if (command == "stats") {
      vector<string> user_values = Chimie_login::get_values("encoder/.users", user_id);
      cout << "Username: "+user_values[0]+" \nAmmount of searches: "+user_values[2]+"\n\n";
    } else if(command == "credits") {
      cout << GREEN "Version: 1.3 \n\
Copyright: No-one \n\
Licence: GNU GPL \n\
Dev team: Julien Renaud \n\
Testers: Xavier Dyer \n\
Ui designer: Julien \n\
Libraries used: stdlib, fstream \n\
Website: http://www.chimieplusplus.com \n\
Compatible with: Linux, MacOS, Replit \n\
Thank you for downloading the project!\n" RESET;
    } else if (command == "sortir" || command == "^C") {
      // sortir de l'app
      cout << "|¯¯¯\\  \\   /  |¯¯¯¯¯ \n";
      cout << "|   /   \\ /   |      \n";
      cout << "|---     |    |-----  \n";
      cout << "|   \\    |    |      \n";
      cout << "|___/    |    |_____ \n";
      break;
    } else {
      cout << BOLDRED "Incapable de trouver la commande :/ \n \n" RESET;
    }
    command = "";
    times++;
  } // END OF INFINITE WHILE
} // END OF MAIN FUNCTION

int main() {
  app();
}

// add error codes and a function that puts them up using index in an array of error messages