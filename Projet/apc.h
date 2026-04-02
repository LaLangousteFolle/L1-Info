#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Noeud;

class Arbre
{
  Noeud * racine;

  public:
  Arbre(void);
  ~Arbre(void);
  Arbre(string file);
  void addWord(char *word);

};

class Noeud
{
  friend class Arbre;
  char info;
  Noeud * fils, * frere;

  public:

  Noeud(void);
  Noeud(char c);
  void displayNoeud(void);
  void setSon(char son);
  void setBro(char bro);
};
