#include "Dico.h"
#include <algorithm>


Dico::Dico(int max_nbm)
{
    this->max_nbm = max_nbm;
    this->nbm = 0;
    this->D = new Mot[max_nbm];
}


Dico::~Dico()
{
    delete[] D;
}


bool Dico::chercherMot(const string &mot) const
{
    for (int i = 0; i < nbm; i++)
    {
        if (D[i].isSynonyme(mot))
        {
            return true;
        }
    }
    return false;
}


void Dico::ajouterMot(const Mot &m)
{
    if (chercherMot(m.mot))
    {
        cout << "Le mot \"" << m.mot << "\" existe déjà dans le dictionnaire." << endl;
        return;
    }

    if (nbm < max_nbm)
    {
        D[nbm] = m;
        nbm++;
    }
    else
    {
        cout << "Le dictionnaire est plein. Impossible d'ajouter un nouveau mot." << endl;
    }
}


void Dico::trier()
{
    sort(D, D + nbm, [](const Mot &a, const Mot &b) {
        return a.mot < b.mot;
    });
}


void Dico::afficher() const
{
    cout << "Dictionnaire (" << nbm << "/" << max_nbm << " mots):" << endl;
    for (int i = 0; i < nbm; i++)
    {
        cout << "Mot " << i + 1 << ":" << endl;
        D[i].afficher();
        cout << endl;
    }
}
