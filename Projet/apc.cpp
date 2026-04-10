#include "apc.h"


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

void Noeud::setSon(char son)
{
    fils = new Noeud(son);
}

void Noeud::setBro(char bro)
{
    frere = new Noeud(bro);
}

bool Arbre::search(char *word)
{
    Noeud *c = racine->fils;
    int i = 0;
    while (word[i])
    {
        if (c == nullptr)
                return(false);
        
        if (c->info == word[i])
        {
            i++;
            c = c->fils;
        }
    }
    c = c->frere;
    return(true);
}

Arbre::~Arbre(void)
{
    if (racine != nullptr)
        delete racine;
}

Arbre::Arbre(void)
{
    racine = new Noeud('!');
}

void Arbre::addWord(char *word)
{
    Noeud *curseur = racine->fils;
    Noeud *deepnest = racine->fils;
    int i = 0;
    if (racine->frere == nullptr || racine->frere->info > word[i])
    {
        racine = new Noeud(word[i]);
        racine->frere = curseur;
        i++;
    }
    while(word[i] != '\0')
    {
        while(curseur->frere != nullptr && curseur->frere->info < word[i])
        {
            curseur = curseur -> frere;
        }
        Noeud *temp = curseur->frere;
        curseur->frere= new Noeud(word[i]);
        curseur->frere->frere=temp;
        i++;
        deepnest = deepnest ->fils;

    }
}
Arbre::Arbre(string file)
{
    racine = new Noeud('!');
    fstream F;
    F.open(file, ios::in);

    while(! F.eof())
    {

        string str;
        getline(F,str,'\n');

        char *cstr = str.data();//change string to char*
        addWord(cstr);
    }
    F.close();
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

Arbre::Arbre(Arbre& abr)
{
    if (this != &abr)
        {
            racine = abr.racine;
        }
}

void Noeud::displayAll(string word)
{
    if(this->info =='\0')
        cout << word << endl;
    if (fils != nullptr)
        fils -> displayAll(word + info);
    if (fils != nullptr)
        frere -> displayAll(word + info);
}   

void Arbre::display(void)
{
    if (racine != nullptr)
        racine->displayAll("");
}