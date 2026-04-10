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
  Arbre(Arbre&);
  Arbre(string file);
  void addWord(char*);
  void display(void);
  bool search(char*);
};

class Noeud
{
  friend class Arbre;
  char info;
  Noeud * fils, * frere;

  public:

  ~Noeud(void);
  Noeud(void);
  Noeud(char c);
  Noeud(Noeud&);
  void displayAll(string);
  void setSon(char son);
  void setBro(char bro);
};
