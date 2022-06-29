#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int stable [7] = {2, 10, 18, 36, 54, 86, 118};
vector<pair<int, int> > familles = {make_pair(0, 0), make_pair(1, 1), make_pair(2, 2), make_pair(3, 3), make_pair(4, 4), make_pair(5, 5), make_pair(6, 6), make_pair(7, 7), make_pair(8, 8), make_pair(9, 9), make_pair(10, 10), make_pair(11, 1), make_pair(12, 2), make_pair(13, 3), make_pair(14, 4), make_pair(15, 5), make_pair(16, 6), make_pair(17, 7)};
vector<pair<int, vector<int>>> elementFamilies = {make_pair(0, vector<int> {0, 0, 0, 0}), make_pair(1, vector<int>{1, 3, 11, 19, 37, 55, 87}), make_pair(2, vector<int>{4, 12, 20, 38, 56, 88}), make_pair(3, vector<int>{21, 39, 57, 89}), make_pair(4, vector<int>{22, 40, 72, 104}), make_pair(5, vector<int>{23, 41, 73, 105}), make_pair(6, vector<int>{24, 42, 74, 106}), make_pair(7, vector<int>{25, 43, 75, 107}), make_pair(8, vector<int>{26, 44, 76, 108}), make_pair(9, vector<int>{27, 45, 77, 109}), make_pair(10, vector<int>{28, 46, 78, 110}), make_pair(11, vector<int>{29, 47, 79, 111}), make_pair(12, vector<int>{30, 48, 80, 112}), make_pair(13, vector<int>{5, 13, 31, 49, 81, 113}), make_pair(14, vector<int>{6, 14, 32, 50, 82, 114}), make_pair(15, vector<int>{7, 15, 33, 51, 83, 115}), make_pair(16, vector<int>{8, 16, 34, 52, 84, 116}), make_pair(17, vector<int>{9, 17, 35, 53, 85, 117}), make_pair(18, vector<int>{2, 10, 18, 36, 54, 86, 118})};

class Element {
public:
  // define constructor
  Element(string symboleAtomique_, string nomP, int nombreAtomique, int masseAtomique, int charge_, int valence=100);
  // define all the properties of the atom
  string nom;
  int electrons;
  int protons;
  int neutrons;
  int charge;
  int nombreAtomique_;
  int masseAtomique_;
  int famille;
  string symboleAtomique;
  bool metal;
  int electronsDeValence;
  bool noCharge;

  virtual Element * stabiliser();
  static int getMin(vector<int> v);
  virtual Element * trouver_gi_proche();
  // only call this method if the element isnt part of the 'all' vector
  virtual void init(Element* element);
};

void setCharge(Element* element) {
  element->charge = element->electrons - element->trouver_gi_proche()->electrons;
}

// i wanted to write Composé but cpp wont let me
class Compose {
public:
  vector<string> types = {"ionique", "moleculaire", "acide", "base"};
  int charge;
  string type;
  bool stable;
  string formule;
  void printCompose();

  Compose(Element* Element1, Element* Element2);
};
// define an element where the user el can be stored
Element* imported;
// define all elements
// symbole, NOM, nombre atomique, masse atomique, charge
Element* Useless = new Element("", "USED TO FILL INDEX 0 in vector", 0, 0, 0);
Element* Hydrogene = new Element("H", "Hydrogene", 1, 1, -1);
Element* Helium = new Element("He", "Helium", 2, 4, 0);
Element* Lithium = new Element("Li", "Lithium", 3, 7, 1);
Element* Beryllium = new Element("Be", "Beryllium", 4, 9, 2);
Element* Bore = new Element("B", "Bore", 5, 11, -3);
Element* Carbone = new Element("C", "Carbone", 6, 12, -4);
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
Element* Cesium = new Element("Cs", "Cesium", 55, 133, 1);
Element* Baryum = new Element("Ba", "Baryum", 56, 137, 2);
Element* Lanthane = new Element("La", "Lanthane", 57, 139, 3);
Element* Cerium = new Element("Ce", "Cerium", 58, 140, 4, 0);
Element* Praseodyme = new Element("Pr", "Praseodyme", 59, 141, 4, 0);
Element* Neodyme = new Element("Nd", "Neodyme", 60, 144, 3);
Element* Promethium = new Element("Pm", "Promethium", 61, 145, 3, 0);
Element* Samarium = new Element("Sm", "Samarium", 62, 150, 4, 0);
Element* Europium = new Element("Eu", "Europium", 63, 152, 3, 0);
Element* Gadolinium = new Element("Gd", "Gadolinium", 64, 157, 3, 0);
Element* Terbium = new Element("Tb", "Terbium", 65, 159, 4, 0);
Element* Dysprosium = new Element("Dy", "Dysporsium", 66, 160, 3, 0);
Element* Holmium = new Element("Ho", "Holmium", 67, 165, 3, 0);
Element* Erbium = new Element("Er", "Erbium", 68, 167, 3, 0);
Element* Thulium = new Element("Tm", "Thulium", 69, 169, 3, 0);
Element* Ytterbium = new Element("Yb", "Ytterbium", 70, 173, 3, 0);
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
Element* Actinium = new Element("Ac", "Actinium", 89, 227, 3, 0);
Element* Thorium = new Element("Th", "Thorium", 90, 232, 4, 0);
Element* Protactinium = new Element("Pa", "Protactinium", 91, 231, 5, 0);
Element* Uranium = new Element("U", "Uranium", 92, 238, 4, 0);
Element* Neptunium = new Element("Np", "Neptunium", 93, 237, 4, 0);
Element* Plutonium = new Element("Pu", "Plutonium", 94, 244, 4, 0);
Element* Americium = new Element("Am", "Americium", 95, 241, 4, 0);
Element* Curium = new Element("Cm", "Curium", 96, 247, 3, 0);
Element* Berkelium = new Element("Bk", "Berkelium", 97, 247, 4, 0);
Element* Californium = new Element("Cf", "Californium", 98, 251, 3, 0);
Element* Einsteinium = new Element("Es", "Einsteinium", 99, 252, 3, 0);
Element* Fermium = new Element("Fm", "Fermium", 100, 257, 3, 0);
Element* Mendelevium = new Element("Md", "Mendelevium", 101, 258, 3, 0);
Element* Nobelium = new Element("No", "Nobelium", 102, 259, 3, 0);
Element* Lawrencium = new Element("Lr", "Lawrencium", 103, 262, 3, 0);
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
vector<Element*> all = {Useless, Hydrogene, Helium, Lithium, Beryllium, Bore, Carbone, Azote, Oxygene, Fluor, Neon, Sodium, Magnesium, Aluminium, Silicium, Phosphore, Soufre, Chlore, Argon, Potassium, Calcium, Scandium, Titane, Vanadium, Chrome, Manganese, Fer, Cobalt, Nickel, Cuivre, Zinc, Gallium, Germanium, Arsenic, Selenium, Brome, Krypton, Rubidium, Strontium, Yttrium, Zirconium, Niobium, Molybdene, Technetium, Ruthenium, Rhodium, Palladium, Argent, Cadmium, Indium, Etain, Antimoine, Tellure, Iode, Xenon, Cesium, Baryum, Lanthane, Cerium, Praseodyme, Neodyme, Promethium, Samarium, Europium, Gadolinium, Terbium, Dysprosium, Holmium, Erbium, Thulium, Ytterbium, Lutecium, Hafnium, Tantale, Tungstene, Rhenium, Osmium, Iridium, Platine, Or, Mercure, Thallium, Plomb, Bismuth, Polonium, Astate, Radon, Francium, Radium, Actinium, Thorium, Protactinium, Uranium, Neptunium, Plutonium, Americium, Curium, Berkelium, Californium, Einsteinium, Fermium, Mendelevium, Nobelium, Lawrencium, Rutherfordium, Dubnium, Seaborgium, Bohrium, Hassium, Meithnerium, Darmstadtium, Roentgenium, Copernicium, Ununtrium, Flerovium, Ununpentium, Livermorium, Ununseptium, Ununoctium};
vector<Element*> gi = {Hydrogene, Neon, Argon, Krypton, Xenon, Radon, Ununoctium};

class Chimie {
  public:
    static string boolToFrench(bool ibool);
    static void loading(int millisecond);
    static vector<string> getValues(Element* element);
    static void init();
    static void createElementFile(Element* element);
    static void createFiles();
    static Element* findElementByName(string name);
    static Element* findElementBySymbol(string symbol);
    static string crop(string input, int start, int end=0);
    static Element* importElement(string filename);
    static void Init();
    static string getOsName();
    static int askQuestion(vector<pair<string, vector<string>>> questions, int times);
    static bool inVector(vector<int> vec, int number);
    static bool inVectorString(vector<string> vec, string number);
    static string lowerString(string input);
    static string getLewis(Element* element);
    static void downloadElement(Element* element, string filepath);
};

vector<pair<string, vector<string>>> easy = {make_pair("Quel est la particule subatomique avec un charge neutre?\n", vector<string> {"neutron", "neutrons"}),
make_pair("Quel est la propriete qui determine les electrons de valence?\n", vector<string> {"periode", "collone"}),
make_pair("Quel est la charge des gaz inhertes?\n", vector<string> {"0", "zero"}),
make_pair("Combiens d'element y a-il en total\n", vector<string> {"118"}),
make_pair("Quel particule subatomique a une charge negative?\n", vector<string> {"electron", "Electron", "electrons", "Electrons"}),
make_pair("Les electrons situe sur la couche externe d'electrons sont les electrons de _______\n", vector<string> {"valence", "Valence"}),
make_pair("Pour qu'un ion soit stable, il faut que sa couche de valence soit pleine ou ____\n", vector<string> {"vide", "Vide"}),
make_pair("pH veux dire puissance d'_________\n", vector<string> {"hydrogene", "Hydrogene"}),
make_pair("Quel est le le premier element du tableau périodique", vector<string> {"hydrogene", "Hydrogene"})};

vector<pair<string, vector<string>>> medium = {
make_pair("Combiens de carbone y a-il dans de l'heptane\n", vector<string> {"7", "sept"}),
make_pair("Quel est la formule chimique de l'Acide Iodhydrique (non stabilise)\n", vector<string> {"HI", "hi"}),
make_pair("Le MgOH est un acide ou une base?\n", vector<string> {"base", "Base"}),
make_pair("Une substance avec un pH de 1.2 est un(e) _____\n", vector<string> {"acide", "Acide"})};

vector<pair<string, vector<string>>> hard = {
  make_pair("HCl + NaOH -> NaCl + ___", vector<string> {"h20", "H20"}),
  make_pair("Quel est l'element numero 47", vector<string> {"Ag", "ag", "Argent", "argent"})
};