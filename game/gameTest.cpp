#include "game.cpp"

void Game() {
  //game::greet(); 
  cout << "Started\n";
  while (true) {
    Element* computer = game::guess();
    Element* user = game::get_ui();
    if (user->nom == "Oxygene" && computer->nom == "Fer" || user->nom == "Fer" && computer->nom == "Zinc" || user->nom == "Zinc" && computer->nom == "Oxygene") {
      // user wins
      cout << "W\n";
    } else if (user->nom == computer->nom) {
      // tie
      cout << "egalite\n";
    } else {
      // user loses
      cout << "perdu\n";
    }
  }
}

int main() {
  cout << "Started\n";
  while (true) {
    Element* computer = game::guess();
    Element* user = game::get_ui();
    if (user->nom == "Oxygene" && computer->nom == "Fer" || user->nom == "Fer" && computer->nom == "Zinc" || user->nom == "Zinc" && computer->nom == "Oxygene") {
      // user wins
      cout << "W\n";
    } else if (user->nom == computer->nom) {
      // tie
      cout << "egalite\n";
    } else {
      // user loses
      cout << "perdu\n";
    }
  }
  //game();
}