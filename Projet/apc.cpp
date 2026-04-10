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
    
}
/* 
 VALVE PLEASE FIX
void Noeud::addWord(char *word)
{
    if (! word)
        return;
    new Noeud(word[0]);
}
*/

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
    if (frere != nullptr)
        frere -> displayAll(word);
}

void Arbre::display(void)
{
    if (racine != nullptr)
        racine->displayAll("");
}

/* ss
void Arbre::deleteWord(char* word)
{
    Noeud *c = racine->fils;
    Noeud *star_destroyer = racine->fils;
    Noeud *c_bro= racine->fils
    if (search(word))
    {
        int i = 0;
        while (word[i])
        {
            c_bro = c->fils->frere;
            if (word[i] == c->info)
            {
                i++;
                c = c ->fils;

                if (c->fils->frere != nullptr)
                    star_destroyer = c;
            }
            else
                c = c->frere;
        }
        if(star_destroyer->fils->fils != nullptr)
            delete star_destroyer->fils->fils;
        else
        {
         star_destroyer->fils->frere =
        }
    }
}
*/
