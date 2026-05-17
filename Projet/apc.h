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
  void addSon(char*);
  bool search(char*);
  void deleteWord(char*);
  int totalWords(void);
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
  int totalWords(void);
  void addWord(char*);
  void displayAll(string);
  void addSon(char);
  void setSon(char son);
  void setBro(char bro);
};
