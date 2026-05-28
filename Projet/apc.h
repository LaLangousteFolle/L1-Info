#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Noeud;

class Arbre
{
    Noeud *racine;

  public:
    Arbre(void);
    ~Arbre(void);
    Arbre(Arbre &);
    Arbre(string file);
    void addWord(const char *);
    void display(void);
    bool search(const char *);
    void deleteWord(const char *);
    int totalWords(void);
    int longestWord(void);
    void saveToFile(string filename);
    void getSuggestions(string prefix);
};

class Noeud
{
    friend class Arbre;
    char info;
    Noeud *fils, *frere;

  public:
    ~Noeud(void);
    Noeud(void);
    Noeud(char c);
    Noeud(Noeud &);
    int totalWords(void);
    void displayAll(string);
    void setBro(char bro);
    void addSon(char);
    void saveToFile(ofstream &F, string word);
    int longestWord(int depth);
    void getSuggestions(string prefix, string current);
    bool deleteWord(const char *);
};
