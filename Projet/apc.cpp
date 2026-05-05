#include "apc.h"


Noeud::Noeud(void)
{
    info = '\0';
    fils = nullptr;
    frere = nullptr;
}

Noeud::Noeud(char c)
{
    info = c;
    fils = nullptr;
    frere = nullptr;
}

Noeud::~Noeud(void)
{
    info = '\0';
    if(fils != nullptr)
        delete fils;
    if (frere != nullptr)
        delete frere;
}

Noeud::Noeud(Noeud& ne)
{
    if (this != &ne)
    {
        info = ne.info;
        fils = ne.fils;
        frere = ne.frere;
    }
}

void Noeud::setSon(char son)
{
    fils = new Noeud(son);
}

void Noeud::setBro(char bro)
{
    frere = new Noeud(bro);
}

// Insère la lettre l parmi les fils, en ordre croissant (pas de doublon).
void Noeud::addSon(char l)
{
    if (!fils)
    {
        fils = new Noeud(l);
        return;
    }
    if (l == fils->info)
        return;
    if (l < fils->info)
    {
        Noeud *node = new Noeud(l);
        node->frere = fils;
        fils = node;
        return;
    }
    Noeud *current = fils;
    while (current->frere != nullptr)
    {
        if (current->frere->info == l)
            return;
        if (l < current->frere->info)
        {
            Noeud *node = new Noeud(l);
            node->frere = current->frere;
            current->frere = node;
            return;
        }
        current = current->frere;
    }
    current->frere = new Noeud(l);
}

// Descend lettre par lettre et ajoute un noeud '\0' pour marquer la fin du mot.
void Arbre::addWord(char *word)
{
    int i = 0;
    Noeud *current = racine;
    while (word[i] != '\0')
    {
        current->addSon(word[i]);
        current = current->fils;
        while (current->info != word[i])
            current = current->frere;
        i++;
    }
    current->addSon('\0');
}

// Affiche récursivement tous les mots : un noeud '\0' signale la fin d'un mot.
void Noeud::displayAll(string word)
{
    if (info == '\0')
        cout << word << endl;
    if (fils != nullptr)
        fils->displayAll(word + info);
    if (frere != nullptr)
        frere->displayAll(word);
}

void Arbre::display(void)
{
    if (racine != nullptr && racine->fils != nullptr)
        racine->fils->displayAll("");
}

bool Arbre::search(char *word)
{
    Noeud *c = racine->fils;
    int i = 0;
    while (word[i])
    {
        if (c == nullptr)
            return false;
        if (c->info == word[i])
        {
            i++;
            c = c->fils;
        }
        else
            c = c->frere;
    }
    return c != nullptr;
}

Arbre::Arbre(void)
{
    racine = new Noeud('!');
}

Arbre::~Arbre(void)
{
    if (racine != nullptr)
        delete racine;
}

Arbre::Arbre(Arbre& abr)
{
    if (this != &abr)
        racine = abr.racine;
}

Arbre::Arbre(string file)
{
    racine = new Noeud('!');
    fstream F;
    F.open(file, ios::in);
    while (!F.eof())
    {
        string str;
        getline(F, str, '\n');
        if (!str.empty())
            addWord(str.data());
    }
    F.close();
}

void Arbre::addSon(char *word)
{
    if (racine == nullptr)
        racine = new Noeud(word[0]);
    else
        racine->addSon(word[0]);
}
