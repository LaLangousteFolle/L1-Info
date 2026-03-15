#include <iostream>
using namespace std;

class Carte
{
friend class Jeu;
int valeur;
int couleur;
Carte *suiv;

    public:
        Carte(void);
        Carte(int value, int color);
        ~Carte(void);
        void afficher(void);
        bool operator==(Carte& je);
        bool operator<(Carte& je);
        bool operator<=(Carte& je);
        bool operator>=(Carte& je);
        bool operator>(Carte& je);
};

class Jeu
{
Carte * tete;
Carte *queue;

    public:
        Jeu(void);
        ~Jeu(void);
        Jeu(int nb_cards);
        Jeu(Jeu &jeu);
        void afficher(void);
        Jeu& operator=(Jeu& jeu);
        Carte* dehors(void);
        void dedans(Carte* carte);
};

Carte::Carte(void)
{
couleur = 0;
valeur = 0;
suiv = nullptr;
}xp

Carte::Carte(int value, int color)
{
    valeur = value;
    couleur = color;
    suiv = nullptr;
}

Carte::~Carte(void)
{
    suiv = nullptr;
}

Jeu::Jeu(void)
{
    tete = nullptr;
    queue = nullptr;
}

Jeu::Jeu(int nb_cards)
{
    if (nb_cards == 52)
    {
        Carte *current = nullptr;
        for (int active_couleur = 0; active_couleur < 4; active_couleur++)
        {
            for (int active_value = 0; active_value < 15; active_value++)
            {
                if (active_value == 2 && active_couleur == 0)
                {
                    tete = new Carte(active_value, active_couleur);
                    current = tete;
                }
                else if (active_value == 14 && active_couleur == 3)
                {
                    queue = new Carte(active_value, active_couleur);
                    if (current != nullptr)
                    {
                        current->suiv = queue;
                    }
                }
                else
                {
                        current->suiv = new Carte(active_value, active_couleur);
                        current = current->suiv;
                }

            }
        }
    }
    else {

        Carte *current = nullptr;
        for (int active_couleur = 0; active_couleur < 4; active_couleur++)
        {
            for (int active_value = 7; active_value < 15; active_value++)
            {
                if (active_value == 7 && active_couleur == 0)
                {
                    tete = new Carte(active_value, active_couleur);
                    current = tete;
                }
                else if (active_value == 14 && active_couleur == 3)
                {
                    queue = new Carte(active_value, active_couleur);
                    if (current != nullptr)
                    {
                        current->suiv = queue;
                    }
                }
                else
                {
                        current->suiv = new Carte(active_value, active_couleur);
                        current = current->suiv;
                }

            }
        }
    }
}

Jeu::Jeu(Jeu &jeu)
{
    (*this).tete = jeu.tete;
    Carte *jeux = new Carte();

    Carte *je = jeu.tete;

    jeux = (*this).tete;
    while(je->suiv != nullptr)
    {
        jeux -> couleur = je -> couleur;
        jeux -> valeur = je -> valeur;
        jeux -> suiv = je  -> suiv;
    }
}


Jeu::~Jeu()
{
    Carte *je= new Carte();
    Carte *jeux= new Carte();
    je = tete;
    jeux = tete;
    while (jeux != nullptr)
    {
        jeux = je->suiv;
        je->suiv->~Carte();
    }
    queue = nullptr;
}

void Carte :: afficher(void)
{
    string couleur_str;
    if(couleur == 0)
        couleur_str = "Treffles";
    if (couleur == 1)
        couleur_str = "Carreaux";
    if (couleur == 2)
        couleur_str = "Coeurs";
    if (couleur == 3)
        couleur_str = "Piques";

    if(valeur == 11)
        cout << "Valet de " << couleur_str << endl;
    else if (valeur == 12)
        cout << "Dame de " << couleur_str << endl;
    else if (valeur == 13)
        cout << "Roi de " << couleur_str << endl;
    else if (valeur == 14)
        cout << "As de " << couleur_str << endl;
    else
        cout << valeur << " de " << couleur_str << endl;
}

void Jeu :: afficher(void)
{
    Carte *je = new Carte();
    while(je != nullptr)
    {
        je->afficher();
        je = je->suiv;
    }
}

Jeu& Jeu::operator=( Jeu& jeu)
{
    if (this == &jeu)
        return(*this);

    (*this).tete = jeu.tete;
    (*this).queue = jeu.queue;
    return(*this);
}

bool Carte :: operator==(Carte& je){
    return((*this).valeur == je.valeur);}

bool Carte :: operator>(Carte& je){
    return((*this).valeur > je.valeur);}

bool Carte ::operator>=(Carte& je){
    return((*this).valeur >=je.valeur);}

bool Carte ::operator<(Carte& je){
    return((*this).valeur <je.valeur);}

bool Carte ::operator<=(Carte& je){
    return((*this).valeur <=je.valeur);}

Carte *Jeu::dehors(void)
{
   Carte* je = new Carte();
   je = tete;
   tete= tete->suiv;
   return(je);
}

void Jeu::dedans(Carte* carte)
{
    queue->suiv = carte;

}

int main(void)
{
    return(0);
}
