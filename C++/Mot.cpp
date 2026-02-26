#include "Mot.h"

Mot::Mot(void)
{
    mot = "";
    nbs = 0;
    synonymes = nullptr;
}

Mot::Mot(string mot, string *synonymes, int nbs)
{
    this->mot = mot;
    this->nbs = nbs;

    if (nbs > 0)
    {
        this->synonymes = new string[nbs];
        for (int i = 0; i < nbs; i++)
        {
            this->synonymes[i] = synonymes[i];
        }
    }
    else
    {
        this->synonymes = nullptr;
    }
}

Mot::Mot(const Mot &M)
{
    mot = M.mot;
    nbs = M.nbs;

    if (nbs > 0)
    {
        synonymes = new string[nbs];
        for (int i = 0; i < nbs; i++)
        {
            synonymes[i] = M.synonymes[i];
        }
    }
    else
    {
        synonymes = nullptr;
    }
}

Mot::~Mot(void)
{
    delete[] synonymes; 
}

Mot &Mot::operator=(const Mot &M)
{

    mot = M.mot;
    nbs = M.nbs;

    if (nbs > 0)
    {
        synonymes = new string[nbs];
        for (int i = 0; i < nbs; i++)
        {
            synonymes[i] = M.synonymes[i];
        }
    }
    return *this;
}

void Mot::saisir()
{
    cout << "Entrez le mot: ";
    cin >> mot;

    cout << "Entrez le nombre de synonymes: ";
    cin >> nbs;

    if (nbs > 0)
    {
        synonymes = new string[nbs];
        for (int i = 0; i < nbs; i++)
        {
            cout << "Entrez le synonyme " << i + 1 << ": ";
            cin >> synonymes[i];
        }
    }
    else
    {
        synonymes = nullptr;
    }
}

void Mot::afficher() const
{
    cout << "Mot: " << mot << endl;
    cout << "Nombre de synonymes: " << nbs << endl;
    if (nbs > 0)
    {
        cout << "Synonymes: ";
        for (int i = 0; i < nbs; i++)
        {
            cout << synonymes[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Aucun synonyme." << endl;
    }
}

void Mot::ajout_Synonyme(const string &synonyme)
{
    string *newSynonymes = new string[nbs + 1];
    for (int i = 0; i < nbs; i++)
    {
        newSynonymes[i] = synonymes[i];
    }
    newSynonymes[nbs] = synonyme;

    delete[] synonymes;
    synonymes = newSynonymes;
    nbs++;
}

bool Mot::isSynonyme(const string &s) const
{
    for (int i = 0; i < nbs; i++)
    {
        if (synonymes[i] == s)
        {
            return true;
        }
    }
    return false;
}

bool Mot::isSynonyme(const Mot &m) const
{
    if (isSynonyme(m.mot))
    {
        return true;
    }

    for (int i = 0; i < m.nbs; i++)
    {
        if (isSynonyme(m.synonymes[i]))
        {
            return true;
        }
    }

    return false;
}
