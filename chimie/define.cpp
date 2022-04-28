#include <vector>
#include <cmath>
#include <string>
#include <chrono>
#include <thread>
#include "define.h"
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

string Chimie::boolToFrench(bool ibool) {
  if (ibool) {
    return "Oui";
  } else if (!ibool) {
    return "Non";
  }
  return "?";
}

bool Chimie::inVector(vector<int> vec, int number) {
  for (int x : vec) {
    if (number == x) {
      return true;
    }
  }
  return false;
}

bool Chimie::inVectorString(vector<string> vec, string number) {
  for (string x : vec) {
    if (number == x) {
      return true;
    }
  }
  return false;
}

void Chimie::loading(int millisecond) {
  long long oneMillisec = 1000000;
  for(int x = 0; x < 101; x++) {
    sleep_for(nanoseconds(millisecond * oneMillisec));
    int result = system("clear");;
    std::cout << "Chargement "<< x << "%\n";
  }
  std::cout << "Fini de charger!\n";
}

// constructor
Element::Element(string symboleAtomique_, string nomP, int nombreAtomique, int masseAtomique, int charge_, int valence) {
  // set properties of object
  nom = nomP;
  electrons = nombreAtomique;
  // electrons de valence, neutrons and protons are init by init()
  // set the electrons de valence property
  if (valence == 100) {
    for (pair<int, vector<int>> electrons_fams : elementFamilies) {
      bool done = false;
      for (int y : electrons_fams.second) {
        if (y == nombreAtomique) {
          famille = familles[electrons_fams.first].first;
          electronsDeValence = familles[electrons_fams.first].second;
          done = true;
          break;
        }
      }
      // end loop if done is true
      if (done) {break;}
    }
  } else {
    electronsDeValence = valence;
  }

  charge = charge_;
  nombreAtomique_ = nombreAtomique;
  masseAtomique_ = masseAtomique;
  symboleAtomique = symboleAtomique_;
}

Element * Element::stabiliser() {
  /*if (this->electrons <= 2) {
    int charge = this->electrons - 2;
    int full_el_gap = 2 - this->electronsDeValence;
    if (electrons < full_el_gap) {
      Element* result = new Element(this->symboleAtomique, this->nom, no_el_gap, no_el_gap);
      result->init();
      return result;
    } else {
      
    }
  }
*/
  return nullptr;
}

// Do this when you are done with stabiliser
Element* Element::trouver_gi_proche() {
  vector<int> gaps;
  for (Element * element : gi) {
    if (element->electrons - this->electrons > 0) {
      gaps.push_back(element->electrons - this->electrons);
    } else if (this->electrons - element->electrons > 0) {
      gaps.push_back(this->electrons - element->electrons);
    } else {
      gaps.push_back(this->electrons - element->electrons);
    }
  }
  int index = getMin(gaps);
  return gi[index];
}

// define a func to print all values of an element
void Chimie::printValues(Element* element) {
  cout << "Nom: " << element->nom << "\n";
  cout << "Symbole atomique: " << element->symboleAtomique << "\n";
  cout << "Numero atomique: " << element->nombreAtomique_ << "\n";
  cout << "Nombres d'electrons: " << element->electrons << "\n";
  cout << "Nombres de protons: " << element->protons << "\n";
  cout << "Nombres de neutrons: " << element->neutrons << "\n";
  cout << "Charge: " << element->charge << "\n";
  cout << "Electrons de valence: " << element->electronsDeValence << "\n";
  cout << "Masse atomique: " << element->masseAtomique_ << "\n";
  cout << "Metal: " /*<< boolalpha*/ << Chimie::boolToFrench(element->metal) << "\n" << "\n";

  cout << "|¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n";
  cout << "| " << element->electrons << "        " << element->charge << "  | \n";
  cout << "|      " << element->symboleAtomique << "      |\n";
  cout << "|              |\n";
  cout << "|    " << element->nom << "   |\n";
  cout << "|              |\n";
  cout << "|      " << element->masseAtomique_ << "      |\n";
  cout << "|______________|\n";
}

// definir une methode pour trouver le min car c++ est epais
int Element::getMin(vector<int> v) {
  int current_min = v[0];
  int index = 0;
  int final_index = 0;
  for (int number : v) {
    if (number < current_min) {
      current_min = number;
      final_index = index;
    }
    index++;
  }
  return final_index;
}

void Chimie::init() {
  for (Element* element : all) {
    // check if synth
    if (element->nombreAtomique_ > 104) {
      element->noCharge = true;
    } else {
      element->noCharge = false;
    }
    // if the element is synth then assing the electrons to proton value lol
    if (!element->noCharge) {
      element->protons = element->electrons + element->charge;
    } else {
      element->protons = element->electrons;
    }
    // see if its a metal or not
    if (element->charge > 0) {
      element->metal = true;
    } else {
      element->metal = false;
    }
    // if Hydrogene set gaz
    if (element->nom == "Hydrogene") {
      element->metal = false;
    }
    element->neutrons = element->masseAtomique_ - element->electrons;
  }
}

void Chimie::createElementFile(Element* element) {
  fstream elementFile;
  elementFile.open("elementFiles/" + element->nom + ".txt", ios::out); // open in write mode
  elementFile << "Nom: " << element->nom << endl;
  elementFile << "Symbole: " << element->symboleAtomique << endl;
  elementFile << "Electrons: " << element->electrons << endl;
  elementFile << "Protons: " << element->protons << endl;
  elementFile << "Neutrons: " << element->neutrons << endl;
  elementFile << "Charge: " << element->charge << endl;
  elementFile << "Numero atomique: " << element->nombreAtomique_ << endl;
  elementFile << "Masse atomique: " << element->masseAtomique_ << endl;
  elementFile << "Electrons de valence: " << element->electronsDeValence << endl;
  elementFile.close();
}

void Chimie::createFiles() {
  for (Element* element : all) {
    if (element->symboleAtomique != "") {
      Chimie::createElementFile(element);
    }
  }
}
void Element::init(Element* element) {
    // set the electrons de valence property
    if (element->charge < 0 && element->electrons > 2) {
      element->electronsDeValence = 8 - element->charge;
    } else if (element->charge > 0) {
      element->electronsDeValence = element->charge;
    }
    // check if synth
    if (element->nombreAtomique_ > 104) {
      element->noCharge = true;
    } else {
      element->noCharge = false;
    }
    // if the element is synth then assing the electrons to proton value lol
    if (!element->noCharge) {
      element->protons = element->electrons + element->charge;
    } else {
      element->electrons = element->protons;
    }
    // see if its a metal or not
    if (element->charge > 0) {
      element->metal = true;
    } else {
      element->metal = false;
    }
    // if Hydrogene set gaz
    if (element->nom == "Hydrogene") {
      element->metal = false;
    }
    element->neutrons = element->masseAtomique_ - element->electrons;
}

Element* Chimie::findElementByName(string name) {
  for (Element* element : all) {
    if (element->nom == name) {
      return element;
    }
  }
  return nullptr;
}

Element* Chimie::findElementBySymbol(string symbol) {
  for (Element* element : all) {
  if (element->symboleAtomique == symbol) {
    return element;
  }
  }
  return nullptr;
}

// lighter version of the class Compose (string format)
string creerCompose(Element* metal, Element* non_metal) {
  if (metal->noCharge || non_metal->noCharge) {
    cout << "Un ou plusieurs des metaux sont invalide desole \n";
  } else {
    int nMetal;
    int nNon_metal;
    nMetal = sqrt(pow(non_metal->charge, 2));
    nNon_metal = metal->charge;
    // if statement to make sure the equation doesnt contain the number 1 or 0
    if (nMetal <= 1) {
      if (nNon_metal <= 1) {
        return metal->symboleAtomique + non_metal->symboleAtomique;
      } else if (nNon_metal > 1) {
        return metal->symboleAtomique + non_metal->symboleAtomique + to_string(nNon_metal);
      }
    } else if(nMetal > 1) {
      if (nNon_metal <= 1) {
        return metal->symboleAtomique + to_string(nMetal) + non_metal->symboleAtomique;
      } else if (nNon_metal > 1) {
        return metal->symboleAtomique + to_string(nMetal) + non_metal->symboleAtomique + to_string(nNon_metal);
      }
    }
  }
  return nullptr;
}

// Compose class part -----------------------------------------
Compose::Compose(Element* Element1, Element* Element2) {
  // make sure this isnt 2 metals
  if (Element1->metal && Element2->metal) {
    cout << "Desole, tu ne peux pas avoir 2 Metaux \n";
  } else {
      charge = Element1->charge + Element2->charge;
      if (Element1->nom == "Hydrogene" && !Element2->metal) {
        type = types[2];
      } else if (Element1->metal == true && Element2->metal == false) {
          type = types[0];
        } else {
          type = types[1];
        }
      // make sure u dont get {element}1
      int nEle2 = sqrt(pow(Element1->charge, 2));
      int nEle1 = sqrt(pow(Element2->charge, 2));
      // set the charge too while u have amnt of every el in compose
      charge = Element1->charge * nEle1 + Element2->charge * nEle2;
      if (charge == 0) {
        stable = true;
      } else {
        stable = false;
      }
    
      if (nEle1 <= 1) {
        if (nEle2 <= 1) {
          formule = Element1->symboleAtomique + Element2->symboleAtomique;
        } else {
          formule = Element1->symboleAtomique + Element2->symboleAtomique + to_string(nEle2);
        }
      } else {
        if (nEle2 <= 1) {
          formule = Element1->symboleAtomique + to_string(nEle1) + Element2->symboleAtomique;
        } else {
          formule = Element1->symboleAtomique + to_string(nEle1) + Element2->symboleAtomique + to_string(nEle2);
        }
      }
  }
}

// define a method to print all the values of a compose
void Compose::printCompose() {
  cout << endl;
  cout << "Charge: " << this->charge << endl;
  cout << "Type: " << this->type << endl;
  cout << "Formule: " << this->formule << endl << endl;
}

string Chimie::crop(string input, int start, int end) {
  if (end == 0) {
    end=input.length();
  }
  string result;
  for (int x = start; x < end; x++) {
    result += input[x];
  }
  return result;
}

Element* Chimie::importElement(string filename) {
  fstream file;
  file.open(filename, ios::in);
  string line;
  vector<string> text;
  while (std::getline(file, line)) {
    text.push_back(line);
  }
  string nom = Chimie::crop(text[0], 5);
  string symbole = Chimie::crop(text[1], 9);
  int numeroAtomique = stoi(Chimie::crop(text[2], 11));
  int masseAtomique = stoi(Chimie::crop(text[7], 16));
  int charge = stoi(Chimie::crop(text[5], 8));
  imported = new Element(symbole, nom, numeroAtomique, masseAtomique, charge);
  imported->init(imported);
  return imported;
}

void Chimie::Init() {
  Chimie::init();
  Chimie::createFiles();
}

string Chimie::getOsName()
{
    #ifdef _WIN32
    return "Windows 32-bit";
    #elif _WIN64
    return "Windows 64-bit";
    #elif __APPLE__ || __MACH__
    return "Mac OSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #elif __unix || __unix__
    return "Unix";
    #else
    return "Other";
    #endif
}   

int Chimie::askQuestion(vector<pair<string, vector<string>>> questions, int times) {
  int total = 0;
  vector<int> usedQ;
  for (int x = 0; x < times; x++) {
    cout << endl;
    int index;
    do {
      index = rand() % questions.size(); // get random question
    } while (inVector(usedQ, index));
    pair<string, vector<string>> question = questions[index];
    cout << question.first << "\n\n"; // ask the question
    string answer; cin >> answer; // get user answer
    cout << endl;
    if (Chimie::inVectorString(question.second, answer)) {
      total += 1;
    } else {
      total += 0;
    }
    usedQ.push_back(index);
    cout << "\n";
  }
  return total;
}

/*
Version: 1.3
Copyright: No-one
Licence: GNU GPL
Dev team: Julien Renaud
Testers: Xavier Dyer
Ui designer: Julien
External libraries used: iostream, fstream
Website: http://www.chimieplusplus.com
Compatible with: Linux, MacOS, Replit
Thank you for downloading the project!
*/

