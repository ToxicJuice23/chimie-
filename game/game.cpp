#include "game.h"
#include <stdlib.h>

Element* game::guess() {
  int index = rand() % 3 + 0;
  return elements[index];
}

Element* game::get_ui() {
  cout << "Fer, Oxygene ou Zinc?\n";
  string choix; cin >> choix;
  return Chimie::findElementByName(choix);
}