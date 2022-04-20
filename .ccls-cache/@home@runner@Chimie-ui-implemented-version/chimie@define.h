#include <iostream>
using namespace std;

int stable [7] = {2, 10, 18, 36, 54, 86, 118};

class Element {
public:
  // define constructor
  Element(string symboleAtomique_, string nomP, int nombreAtomique, int masseAtomique, int charge_);
  // define all the properties of the atom
  string nom;
  int electrons;
  int protons;
  int neutrons;
  int charge;
  int nombreAtomique_;
  int masseAtomique_;
  string symboleAtomique;
  bool metal;
  int electronsDeValence;
  bool noCharge;

  virtual Element * stabiliser();
  static int getMin(vector<int> v);
  virtual Element * trouver_gi_proche();
};

void printValues(Element* element);
void setCharge(Element* element) {
  element->charge = element->electrons - element->trouver_gi_proche()->electrons;
}

// define all elements
// symbole, NOM, nombre atomique, masse atomique, charge
Element* Useless = new Element("", "USED TO FILL INDEX 0 in vector", 0, 0, 0);
Element* Hydrogene = new Element("H", "Hydrogene", 1, 1, 1);
Element* Helium = new Element("He", "Helium", 2, 4, 0);
Element* Lithium = new Element("Li", "Lithium", 3, 7, 1);
Element* Beryllium = new Element("Be", "Beryllium", 4, 9, 2);
Element* Bore = new Element("B", "Bore", 5, 11, 3);
Element* Carbone = new Element("C", "Carbone", 6, 12, 4);
Element* Azote = new Element("N", "Azote", 7, 14, -3);
Element* Oxygene = new Element("O", "Oxygene", 8, 16, -2);
Element* Fluor = new Element("F", "Fluor", 9, 16, -1);
Element* Neon = new Element("Ne", "Neon", 10, 20, 0);
Element* Sodium = new Element("Na", "Sodium", 11, 23, 1);
Element* Magnesium = new Element("Mg", "Magnesium", 12, 24, 2);
Element* Aluminium = new Element("Al", "Aluminium", 13, 27, 3);
Element* Silicium = new Element("Si", "Silicium", 14, 28, 4);
Element* Phosphore = new Element("P", "Phosphore", 15, 31, -3);
Element* Soufre = new Element("S", "Soufre", 16, 32, -2);
Element* Chlore = new Element("Cl", "Chlore", 17, 35, -1);
Element* Argon = new Element("Ar", "Argon", 18, 40, 0);
Element* Potassium = new Element("K", "Potassium", 19, 39, 1);
Element* Calcium = new Element("Ca", "Calcium", 20, 40, 2);
Element* Scandium = new Element("Sc", "Scandium", 21, 45, 3);
Element* Titane = new Element("Ti", "Titane", 22, 48, 4);
Element* Vanadium = new Element("V", "Vanadium", 23, 51, 5);
Element* Chrome = new Element("Cr", "Chrome", 24, 52, 3);
Element* Manganese = new Element("Mn", "Manganese", 25, 55, 3);
Element* Fer = new Element("Fe", "Fer", 26, 56, 3);
Element* Cobalt = new Element("Co", "Cobalt", 27, 59, 3);
Element* Nickel = new Element("Ni", "Nickel", 28, 59, 3);
Element* Cuivre = new Element("Cu", "Cuivre", 29, 64, 2);
Element* Zinc = new Element("Zn", "Zinc", 30, 65, 2);
Element* Gallium = new Element("Ga", "Gallium", 31, 70, 3);
Element* Germanium = new Element("Ge", "Germanium", 32, 73, 4);
Element* Arsenic = new Element("As", "Arsenic", 33, 75, -3);
Element* Selenium = new Element("Se", "Selenium", 34, 79, -2);
Element* Brome = new Element("Br", "Brome", 35, 80, -1);
Element* Krypton = new Element("Kr", "Krypton", 36, 84, 0);
Element* Rubidium = new Element("Rb", "Rubidium", 37, 85, 1);
Element* Strontium = new Element("Sr", "Strotnium", 38, 88, 2);
Element* Yttrium = new Element("Y", "Yttrium", 39, 89, 3);
Element* Zirconium = new Element("Zr", "Zirconium", 40, 91, 4);
Element* Niobium = new Element("Nb", "Niobium", 41, 93, 5);
Element* Molybdene = new Element("Mo", "Molybdene", 42, 96, 3);
Element* Technetium = new Element("Tc", "Technetium", 43, 98, 7);
Element* Ruthenium = new Element("Ru", "Ruthenium", 44, 102, 4);
Element* Rhodium = new Element("Rh", "Rhodium", 45, 103, 4);
Element* Palladium = new Element("Pd", "Palladium", 46, 106, 4);
Element* Argent = new Element("Ag", "Argent", 47, 108, 1);
Element* Cadmium = new Element("Cd", "Cadmium", 48, 112, 2);
Element* Indium = new Element("In", "Indium", 49, 115, 3);
Element* Etain = new Element("Sn", "Etain", 50, 119, 4);
Element* Antimoine = new Element("Sb", "Antimoine", 51, 122, 5);
Element* Tellure = new Element("Te", "Tellure", 52, 128, -2);
Element* Iode = new Element("I", "Iode", 53, 127, -1);
Element* Xenon = new Element("Xe", "Xenon", 54, 131, 0);
Element* Cesium = new Element("Cs", "Césium", 55, 133, 1);
Element* Baryum = new Element("Ba", "Baryum", 56, 137, 2);
Element* Lanthane = new Element("La", "Lanthane", 57, 139, 3);
Element* Cerium = new Element("Ce", "Cérium", 58, 140, 4);
Element* Praseodyme = new Element("Pr", "Praseodyme", 59, 141, 4);
Element* Neodyme = new Element("Nd", "Neodyme", 60, 144, 3);
Element* Promethium = new Element("Pm", "Promethium", 61, 145, 3);
Element* Samarium = new Element("Sm", "Samarium", 62, 150, 4);
Element* Europium = new Element("Eu", "Europium", 63, 152, 3);
Element* Gadolinium = new Element("Gd", "Gadolinium", 64, 157, 3);
Element* Terbium = new Element("Tb", "Terbium", 65, 159, 4);
Element* Dysprosium = new Element("Dy", "Dysporsium", 66, 160, 3);
Element* Holmium = new Element("Ho", "Holmium", 67, 165, 3);
Element* Erbium = new Element("Er", "Erbium", 68, 167, 3);
Element* Thulium = new Element("Tm", "Thulium", 69, 169, 3);
Element* Ytterbium = new Element("Yb", "Ytterbium", 70, 173, 3);
Element* Lutecium = new Element("Lu", "Lutecium", 71, 175, 3);
Element* Hafnium = new Element("Hf", "Hafnium", 72, 178, 4);
Element* Tantale = new Element("Ta", "Tantale", 73, 181, 5);
Element* Tungstene = new Element("W", "Tungstene", 74, 184, 6);
Element* Rhenium = new Element("Re", "Rhenium", 75, 186, 7);
Element* Osmium = new Element("Os", "Osmium", 76, 190, 4);
Element* Iridium = new Element("Ir", "Iridium", 77, 192, 4);
Element* Platine = new Element("Pt", "Platine", 78, 195, 4);
Element* Or = new Element("Au", "Or", 79, 197, 3);
Element* Mercure = new Element("Hg", "Mercure", 80, 200, 2);
Element* Thallium = new Element("Tl", "Thallium", 81, 204, 3);
Element* Plomb = new Element("Pb", "Plomb", 82, 207, 4);
Element* Bismuth = new Element("Bi", "Bismuth", 83, 209, 5);
Element* Polonium = new Element("Po", "Polonium", 84, 209, 4);
Element* Astate = new Element("At", "Astate", 85, 210, -1);
Element* Radon = new Element("Rn", "Radon", 86, 222, 0);
Element* Francium = new Element("Fr", "Francium", 87, 223, 1);
Element* Radium = new Element("Ra", "Radium", 88, 226, 2);
Element* Actinium = new Element("Ac", "Actinium", 89, 227, 3);
Element* Thorium = new Element("Th", "Thorium", 90, 232, 4);
Element* Protactinium = new Element("Pa", "Protactinium", 91, 231, 5);
Element* Uranium = new Element("U", "Uranium", 92, 238, 4);
Element* Neptunium = new Element("Np", "Neptunium", 93, 237, 4);
Element* Plutonium = new Element("Pu", "Plutonium", 94, 244, 4);
Element* Americium = new Element("Am", "Americium", 95, 241, 4);
Element* Curium = new Element("Cm", "Curium", 96, 247, 3);
Element* Berkelium = new Element("Bk", "Berkelium", 97, 247, 4);
Element* Californium = new Element("Cf", "Californium", 98, 251, 3);
Element* Einsteinium = new Element("Es", "Einsteinium", 99, 252, 3);
Element* Fermium = new Element("Fm", "Fermium", 100, 257, 3);
Element* Mendelevium = new Element("Md", "Mendelevium", 101, 258, 3);
Element* Nobelium = new Element("No", "Nobelium", 102, 259, 3);
Element* Lawrencium = new Element("Lr", "Lawrencium", 103, 262, 3);
Element* Rutherfordium = new Element("Rf", "Rutherfordium", 104, 261, 4);
Element* Dubnium = new Element("Db", "Dubnium", 105, 262, 0);
Element* Seaborgium = new Element("Sg", "Seaborgium", 106, 266, 0);
Element* Bohrium = new Element("Bh", "Bohrium", 107, 264, 0);
Element* Hassium = new Element("Hs", "Hassium", 108, 269, 0);
Element* Meithnerium = new Element("Mt", "Meithnerium", 109, 268, 0);
Element* Darmstadtium = new Element("Ds", "Darmastadium", 110, 281, 0);
Element* Roentgenium = new Element("Rg", "Roentgenium", 111, 280, 0);
Element* Copernicium = new Element("Uub", "Ununbium", 112, 285, 0);
Element* Ununtrium = new Element("Uut", "Unutrium", 113, 284, 0);
Element* Flerovium = new Element("Uuq", "Ununquadium", 114, 289, 0);
Element* Ununpentium = new Element("Uup", "Ununpentium", 115, 288, 0);
Element* Livermorium = new Element("Uuh", "Ununhexium", 116, 293, 0);
Element* Ununseptium = new Element("Uus", "Ununseptium", 117, 291, 0);
Element* Ununoctium = new Element("Uuo", "Ununoctium", 118, 294, 0);
// define a vector of all elements :(
vector<Element*> all = {Useless, Hydrogene, Helium, Lithium, Beryllium, Bore, Carbone, Azote, Oxygene, Fluor, Neon, Sodium, Magnesium, Aluminium, Silicium, Phosphore, Soufre, Chlore, Argon, Potassium, Calcium, Scandium, Titane, Vanadium, Chrome, Manganese, Fer, Cobalt, Nickel, Cuivre, Zinc, Gallium, Germanium, Arsenic, Selenium, Brome, Krypton, Rubidium, Strontium, Yttrium, Zirconium, Niobium, Molybdene, Technetium, Ruthenium, Rhodium, Palladium, Argent, Cadmium, Indium, Etain, Antimoine, Tellure, Iode, Xenon, Cesium, Baryum, Lanthane, Cerium, Praseodyme, Neodyme, Promethium, Samarium, Europium, Gadolinium, Terbium, Dysprosium, Holmium, Erbium, Thulium, Ytterbium, Lutecium, Hafnium, Tantale, Tungstene, Rhenium, Osmium, Iridium, Platine, Or, Mercure, Thallium, Plomb, Bismuth, Polonium, Astate, Radon, Francium, Radium, Radium, Actinium, Thorium, Protactinium, Uranium, Neptunium, Plutonium, Americium, Curium, Berkelium, Californium, Einsteinium, Fermium, Mendelevium, Nobelium, Lawrencium, Rutherfordium, Dubnium, Seaborgium, Bohrium, Hassium, Meithnerium, Darmstadtium, Roentgenium, Copernicium, Ununtrium, Flerovium, Ununpentium, Livermorium, Ununseptium, Ununoctium};
vector<Element*> gi = {Hydrogene, Neon, Argon, Krypton, Xenon, Radon, Ununoctium};