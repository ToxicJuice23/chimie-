#include "game.h"
#include <stdlib.h>

Element* game::guess() {
  int index = rand() % 3 + 0;
  return elements[index];
}

Element* game::get_ui() {
  cout << "Fer, Oxygene ou Zinc?\n";
  string choix; cin >> choix;
  if (choix == "sortir") {
    return Carbone;
  }
  return Chimie::findElementByName(choix);
}

void game() {
  cout << "Started\n";
  while (true) {
    Element* computer = game::guess();
    Element* user = game::get_ui();
    if (user != nullptr) {
      if (user == Carbone) {
        break;
      }
      Chimie::printValues(computer);
      if (user->nom == "Oxygene" && computer->nom == "Fer" || user->nom == "Fer" && computer->nom == "Zinc" || user->nom == "Zinc" && computer->nom == "Oxygene") {
        // user wins
        cout << "Bravo!\n";
      } else if (user->nom == computer->nom) {
        // tie
        cout << "Egalitee\n";
      } else {
        // user loses
        cout << "Desole, tu as perdu\n";
      }
    } else {
      cout << "Nom d'element non-valide\n";
    }
  }
}