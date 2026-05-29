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
        delete fils;  // supprime recursivement les fils
    if (frere != nullptr)
        delete frere; // supprime recursivement les freres
}

Noeud::Noeud(Noeud &ne)
{
    info = ne.info;
        if (ne.fils != nullptr)
            fils = new Noeud(*ne.fils);
        else
            fils = nullptr;
        if (ne.frere != nullptr)
            frere = new Noeud(*ne.frere); // pareil pour le frere
        else
            frere = nullptr;
}

void Noeud::setBro(char bro)
{
    frere = new Noeud(bro);
}

// insere la lettre l parmi les fils, en ordre croissant.
void Noeud::addSon(char l)
{
    //safety verifs
    if (!fils)
    {
        fils = new Noeud(l);
        return;
    }
    if (l == fils->info)
        return;

    // vrai bails
    if (l < fils->info) // tant que la lettre l est alphabetiquement en dessous
    {
        Noeud *node = new Noeud(l);
        node->frere = fils;
        fils = node;
        return;
    }

    // si  fils deja la -> on check les frr

    Noeud *current = fils;
    while (current->frere != nullptr)
    {
        // verif
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

// descend dans l'arbre lettre par lettre et ajoute '\0' pour marquer la fin.
void Arbre::addWord(const char *word) // cf. ADDWORD.png
{
    int i = 0;
    Noeud *current = racine;
    while (word[i] != '\0') //verif fin de mot -> arret creation fils
    {
        current->addSon(word[i]); // insere la lettre si elle existe pas deja
        current = current->fils;
        while (current->info != word[i]) // tant que la lettre est pas la meme
            current = current->frere;    // on avance dans les freres
        i++;
    }
    current->addSon('\0'); // marque la fin du mot
}

// affiche récursivement tous les mots
void Noeud::displayAll(string word)
{
    if (info == '\0')
        cout << word << endl;
    if (fils != nullptr)
        fils->displayAll(word + info);  // descend en ajoutant  lettre courante
    if (frere != nullptr)
        frere->displayAll(word);        // explore le frere
}

void Arbre::display(void)
{
    if (racine != nullptr && racine->fils != nullptr)
        racine->fils->displayAll(""); // vrais noeuds -> prefixe vide
}

bool Arbre::search(const char *word)
{
    Noeud *c = racine->fils;
    int i = 0;
    while (word[i])
    {
        if (c == nullptr)
            return false; // prefixe pas dans l'arbre
        if (c->info == word[i])
        {
            i++;
            c = c->fils;  // descend dans l'arbre
        }
        else
            c = c->frere; // mauvaise lettre -> try frere
    }
    // on cherche '\0' parmi les freres
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
            racine = new Noeud(*abr.racine); // copie tout l'arbre via Noeud
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
        getline(F, str, '\n'); // lit ligne par ligne
        if (!str.empty())
            addWord(str.data()); // insere mot dans abr
    }
    F.close();
}

int Noeud::totalWords(void)
{
    if(info == '\0')
    {
        if (frere)
            return(frere->totalWords() + 1); // + les mots dans les freres
         return(1);
    }
    // noeud normal -> on compte dans les fils ET les freres
    if (frere)
        return(fils->totalWords()+frere->totalWords());
    return(fils->totalWords());
}

int Arbre::totalWords(void){
    if (racine && racine->fils)
            return racine->fils->totalWords(); // on part des vrais noeuds
        return 0;
}

// depth = nb de lettres traversees pour arriver ici
int Noeud::longestWord(int depth)
{
    int res = 0;

    if (info == '\0')   // fin de mot -> depth = longueur du mot
        res = depth;

    if (info != '\0' && fils != nullptr)
    {
        int f = fils->longestWord(depth + 1); // on descend -> +1 lettre
        if (f > res)
            res = f;
    }

    if (frere != nullptr)
    {
        int f = frere->longestWord(depth); // frere = meme niveau -> depth inchange
        if (f > res)
            res = f;
    }

    return res;
}

int Arbre::longestWord(void)
{
    if (!racine || !racine->fils)
        return 0;
    return racine->fils->longestWord(0); // on part a depth=0 pour pas compter la racine
}

// meme logique que displayAll mais ecrit dans un fichier
void Noeud::saveToFile(ofstream &F, string word)
{
    if (info == '\0')
        F << word << "\n";              // fin de mot -> ecrit dans le fild
    if (fils != nullptr)
        fils->saveToFile(F, word + info);  // descend en ajoutant la lettre
    if (frere != nullptr)
        frere->saveToFile(F, word);        // explore le frere avec le meme prefixe
}

void Arbre::saveToFile(string filename)
{
    ofstream F(filename);
    if (racine != nullptr && racine->fils != nullptr)
        racine->fils->saveToFile(F, "");
    F.close();
}

void Noeud::getSuggestions(string prefix, string current)
{
    if (info == '\0')
    {
        // fin de mot ET on a bien mange tout le prefixe -> mot valide
        if (current.length() >= prefix.length())
            cout << current << endl;
        if (frere != nullptr)
            frere->getSuggestions(prefix, current); // continue les freres du '\0'
        return;
    }
    if (current.length() < prefix.length())
    {
        if (info == prefix[current.length()])  // bonne lettre -> on descend
        {
            if (fils != nullptr)
                fils->getSuggestions(prefix, current + info);
        }
        else if (info < prefix[current.length()]) // lettre trop petite -> on try le frere
        {
            if (frere != nullptr)
                frere->getSuggestions(prefix, current);
        }
        else
            return; // lettre trop grande -> le prefixe existe pas
    }
    else // prefixe entierement mange -> on collecte tout
    {
        if (fils != nullptr)
            fils->getSuggestions(prefix, current + info);
        if (frere != nullptr)
            frere->getSuggestions(prefix, current);
    }
}

void Arbre::getSuggestions(string prefix)
{
    if (racine != nullptr && racine->fils != nullptr)
        racine->fils->getSuggestions(prefix, ""); // current vide au depart
}

// retourne true si le noeud peut etre supprime (plus de fils)
bool Noeud::deleteWord(const char *word)
{
    if (word[0] == '\0') //bout du mot -> cherche le '\0' parmi les fils
    {
        if (!fils)
            return false;
        if (fils->info == '\0') // directement le premier fils
        {
            Noeud *tmp = fils;
            fils = fils->frere;  // "decrochage"
            tmp->frere = nullptr;
            delete tmp;
            return fils == nullptr; // true si plus aucun fils -> noeud parent peut etre supprime
        }
        // on cherche dans les freres
        Noeud *cur = fils;
        while (cur->frere)
        {
            if (cur->frere->info == '\0')
            {
                Noeud *tmp = cur->frere;
                cur->frere = tmp->frere; // decroche le '\0'
                tmp->frere = nullptr;
                delete tmp;
                return false; // parce qu'il reste d'autres fils
            }
            cur = cur->frere;
        }
        return false;
    }
    if (!fils)
        return false; // lettre pas trouvee -> mot absent
    if (fils->info == word[0]) // bonne lettre en premier fils
    {
        bool del = fils->deleteWord(word + 1); // descend recursivement
        if (del)
        {
            Noeud *tmp = fils;
            fils = fils->frere;
            tmp->frere = nullptr;
            delete tmp;
        }
        return fils == nullptr;
    }
    // cherche la bonne lettre parmi les freres
    Noeud *cur = fils;
    while (cur->frere)
    {
        if (cur->frere->info == word[0])
        {
            bool del = cur->frere->deleteWord(word + 1);
            if (del)
            {
                Noeud *tmp = cur->frere;
                cur->frere = tmp->frere;
                tmp->frere = nullptr;
                delete tmp;
            }
            return false; // frr -> pas de delete en cascade
        }
        cur = cur->frere;
    }
    return false;
}

void Arbre::deleteWord(const char *word)
{
    if (racine)
        racine->deleteWord(word);
}
