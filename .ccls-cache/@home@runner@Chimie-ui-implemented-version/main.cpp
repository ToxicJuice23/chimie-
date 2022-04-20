#include <iostream>
#include "chimie/define.cpp"
using namespace std;
int main() {
  init();
  // Begining dialog
  cout << "         .        .   \n";
  cout << "/¯¯ |  | | |\\  /| | |¯¯¯¯      |       |      • \\|/\n";
  cout << "|   |--| | | \\/ | | |----   ---|--- ---|---      c )\n";
  cout << "\\__ |  | | |    | | |____      |       |      • /|\\  \n";
  cout << "Bienvenue à Chimie++ \n";
  cout << "Ceci est la version console de Chimie++ car je n'ai pas encore trouvé une bonne bibliothèque de GUI pour C++ \n";
  cout << "Qu'aimerais-tu faire? (en passant, tu peux tourours avoir une liste des commandes avec le mot 'aide') \n";

  string command;
  int times = 1;
  // UI principal
  while (true) {
    // get users command until sortir
    if (times > 1) {
      cout << "Entre une " << times << "ème commande: ";
    } else {
      cout << "Entre une commande: ";
    }
    cin >> command; cout << endl;
    if (command == "aide") {
      // list all commands
      cout << "Voici une liste de commande: \n \n";
      cout << "sortir: Fermer l'application \n \n";
      cout << "info: Te donne tout l'information necessaire à propos d'un element\n \n";
      cout << "creer_compose: crée un composé ionique ou moléculaire équilibré à partire de deux éléments \n \n";
    } else if (command == "info") {
      // demander quel type de recherche
      string type; cout << "Souhaites-tu trouver par: nom (commande: nom) , symbole atomique (comande: symbole) ou numero atomique (commande: numero) \n \n"; cin >> type;
      //if its find by name
      if (type == "nom") {
        try {
          cout << "entre le nom de l'élemement (pas d'accents ex: Neon)\n \n";
          string _nom;cin >> _nom;
          cout << endl;
          // error handling for getting element
          if (findElementByName(_nom) == nullptr) {
            cout << "Incapable de trouver l'élément \n";
          } else {
            Element* element_ = findElementByName(_nom);
            printValues(element_);
          }
        } catch(...) {
          cout << "Incapable de trouver l'élément \n";
        }
      } else if (type == "numero") {
        // 
        string numero; cout << "Quel numero? \n \n"; cin >> numero;
        int num = stoi(numero);
        try {
          if (all[num] == 0) {
            cout << "Incapable de trouver l'élément \n";
          } else {
           printValues(Hydrogene); 
          }
        } catch(...) {
          cout << "Incapable de trouver l'élément \n";
        }
      } else if (type == "symbole") {
        cout << "entre le symbole atomique (pas d'accents ex: Co)\n \n";
        string symbole;cin >> symbole;
        cout << endl;
        try {
          // error handling for getting element
          if (findElementBySymbol(symbole) == nullptr) {
            cout << "Incapable de trouver l'élément \n";
          } else {
            printValues(findElementBySymbol(symbole));
          }
        } catch(...) {
          cout << "Incapable de trouver l'élément \n";
        }
      } else {
        cout << "Mode de saisie invalide. \n";
      }
    } else if(command == "creer_compose") {
      // trouve les elements dans la base de donné et crée une equation
      try {
        string element1; string element2;
        cout << "Element 1: "; cin >> element1; cout << "Element 2: ";  cin >> element2;
        Element* metal = findElementByName(element1);
        Element* non_metal = findElementByName(element2);
        // error handling
        if (metal == nullptr || non_metal == nullptr) {
          cout << "Incapable de trouver l'élément \n";
        } else {
          cout << creerCompose(metal, non_metal) << endl << endl;
        }
      } catch(...) {
        cout << "Incapable de trouver l'élément \n";
      }
    } else if (command == "sortir") {
      // sortir de l'app
      cout << "|¯¯¯\\  \\   /  |¯¯¯¯¯ \n";
      cout << "|   /   \\ /   |        • \\|/ \n";
      cout << "|---     |    |-----      c ) \n";
      cout << "|   \\    |    |        • /|\\ \n";
      cout << "|___/    |    |_____ \n";
      break;
    } else {
      cout << "Incapable de trouver la commande :/ \n \n";
    }
    command = "";
    times++;
  } // END OF INFINITE WHILE
} // END OF MAIN FUNCTION