#include "Mot.h"

class Dico
{
    Mot *D;         
    int nbm;        
    int max_nbm;    

public:
    Dico(int max_nbm); 
    ~Dico();           

    bool chercherMot(const string &mot) const; 
    void ajouterMot(const Mot &m);             
    void trier();                              
    void afficher() const;                     
};
