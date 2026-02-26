#include <iostream>
#include <string>
using namespace std;

class Mot
{
    int nbs;          
    string *synonymes; 

public:
    string mot;       
    Mot(void); 
    Mot(string mot, string *synonymes, int nbs); 
    Mot(const Mot &M); 
    ~Mot(void); 

    Mot &operator=(const Mot &M); 

    void saisir(); 
    void afficher() const; 
    void ajout_Synonyme(const string &synonyme); 
    bool isSynonyme(const string &s) const; 
    bool isSynonyme(const Mot &m) const; 
};
