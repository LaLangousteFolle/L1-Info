#include "apc.h"


Noeud::Noeud(char c)
{
    info = c;
    fils = nullptr;
    frere = nullptr;
}

void Noeud::setSon(char son)
{
    fils = new Noeud(son);
}

void Noeud::setBro(char bro)
{
    frere = new Noeud(bro);
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

        char *cstr = str.data();//return char*
        addWord(cstr);
    }
    F.close();
}

void Noeud::displayNoeud(void)
{

}
