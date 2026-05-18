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
    info = ne.info;
        if (ne.fils != nullptr)
            fils = new Noeud(*ne.fils);
        else
            fils = nullptr;
        if (ne.frere != nullptr)
            frere = new Noeud(*ne.frere);
        else
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
void Arbre::addWord(const char *word)
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
    while (c != nullptr)
    {
        if (c->info == '\0')
            return true;
        c = c->frere;
    }
    return false;
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
    if (abr.racine != nullptr)
            racine = new Noeud(*abr.racine);
        else
            racine = nullptr;
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


int Noeud::totalWords(void){

    if(info == '\0')
    {
        if (frere)
            return(frere->totalWords() + 1);
         return(1);
    }
    if (frere)
        return(fils->totalWords()+frere->totalWords());
    return(fils->totalWords());
}

int Arbre::totalWords(void){
    if (racine && racine->fils)
            return racine->fils->totalWords();
        return 0;
}

int Noeud::longestWord(int depth)
{
    int res = 0;

    if (info == '\0')
        res = depth;

    if (info != '\0' && fils != nullptr)
    {
        int f = fils->longestWord(depth + 1);
        if (f > res)
            res = f;
    }

    if (frere != nullptr)
    {
        int f = frere->longestWord(depth);
        if (f > res)
            res = f;
    }

    return res;
}

int Arbre::longestWord(void)
{
    if (!racine || !racine->fils)
        return 0;
    return racine->fils->longestWord(0);
}

void Noeud::saveToFile(ofstream &F, string word)
{
    if (info == '\0')
        F << word << "\n";
    if (fils != nullptr)
        fils->saveToFile(F, word + info);
    if (frere != nullptr)
        frere->saveToFile(F, word);
}

void Arbre::saveToFile(string filename)
{
    ofstream F(filename);
    if (racine != nullptr && racine->fils != nullptr)
        racine->fils->saveToFile(F, "");
    F.close();
}

void Arbre::addSon(char *word)
{
    if (racine == nullptr)
        racine = new Noeud(word[0]);
    else
        racine->addSon(word[0]);
}
