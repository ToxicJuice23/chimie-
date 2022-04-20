#include <vector>
#include <cmath>
#include "define.h"
using namespace std;

// constructor
Element::Element(string symboleAtomique_, string nomP, int nombreAtomique, int masseAtomique, int charge_) {
  // set properties of object
  nom = nomP;
  protons = nombreAtomique;
  neutrons = protons;
  // electrons de valence and electrons are init by init()
  charge = charge_;
  nombreAtomique_ = nombreAtomique;
  masseAtomique_ = masseAtomique;
  symboleAtomique = symboleAtomique_;
}

Element * Element::stabiliser() {
  // find which Gas Inerte is the closest and change the electrons to that
  vector<int> gaps;
  int nElectrons;
  for (int el : stable) {
    if (this->electrons - el > 0) {
      gaps.push_back(this->electrons - el);
    } else if (el - this->electrons > 0) {
      gaps.push_back(el - this->electrons);
    } else if (el - this->electrons == 0) {
      gaps.push_back(el - this->electrons);
    }
  }
  // get minimum gap and assign electron to the shortest item of stable
  int index = getMin(gaps);
  nElectrons = stable[index];
  Element* stable = new Element(this->symboleAtomique, "ion de " + this->nom, this->nombreAtomique_, this->protons + nElectrons, this->protons - this->electrons);
  stable->electrons = nElectrons;
  return stable;
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
void printValues(Element* element) {
  cout << "Nom: " << element->nom << "\n";
  cout << "Symbole atomique: " << element->symboleAtomique << "\n";
  cout << "Numero atomique: " << element->nombreAtomique_ << "\n";
  cout << "Nombres d'electrons: " << element->electrons << "\n";
  cout << "Nombres de protons: " << element->protons << "\n";
  cout << "Nombres de neutrons: " << element->neutrons << "\n";
  cout << "Charge: " << element->charge << "\n";
  cout << "Electrons de valence: " << element->electronsDeValence << "\n";
  cout << "Masse atomique: " << element->masseAtomique_ << "\n";
  cout << "Metal: " << boolalpha << element->metal << "\n" << "\n";
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

void init() {
  for (Element* element : all) {
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
      element->electrons = element->protons - element->charge;
    } else {
      element->electrons = element->protons;
    }
    // see if its a metal or not
    if (element->charge > 0) {
      element->metal = true;
    } else {
      element->metal = false;
    }
  }
}

Element* findElementByName(string name) {
  for (Element* element : all) {
    if (element->nom == name) {
      return element;
    }
  }
  return nullptr;
}

Element* findElementBySymbol(string symbol) {
  for (Element* element : all) {
  if (element->symboleAtomique == symbol) {
    return element;
  }
  }
  return nullptr;
}

string creerCompose(Element* metal, Element* non_metal) {
  if (metal->noCharge || non_metal->noCharge) {
    cout << "Un ou plusieurs des métaux sont invalide désolé \n";
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