#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Point.h"

using namespace std;

// =====================
// Classe Point
// =====================

// Ex. 4b : constructeur sans paramètres
Point::Point()
{
    x=0;
    y=0;
}

// Ex. 4a : constructeur avec paramètres
Point::Point(double x_, double y_)
{
    x=x_;
    y=y_;
}

// Ex. 1 : afficher
void Point::afficher() const
{
        std::cout << "(" << x << " , " << y << ")";
}

// Ex. 3 : saisir
void Point::saisir()
{
        std::cout << "Entrer x : ";
        std::cin >> x;
        std::cout << "Entrer y : ";
        std::cin >> y;
}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

// Ex. 8 : mutateurs
void Point::setX(double x_) { x = x_; }
void Point::setY(double y_) { y = y_; }

// Ex. 5 : distance (const Point& et méthode const)
double Point::distance(const Point& P) const
{
        double dx = x - P.x;
        double dy = y - P.y;
        return std::sqrt(dx * dx + dy * dy);
}

    // Ex. 9 : egale (distance < 0.0001)
bool Point::egale(const Point& P) const
{
        return distance(P) < 0.0001;
}

// Ex. 10 : nombre de points dans cercle de centre "le point courant"
int Point::compterPointsDansCercle(const Point* tab, int n, double R) const
{
        int cpt = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((*this).distance(tab[i]) <= R)
            {
                ++cpt;
            }
        }
        return cpt;
}

    // Ex. 11 : suppression des points hors cercle (centre = point courant), taille mise à jour
void Point::supprimerPointsHorsCercle(Point* tab, int n, double R) const
{
        int write = 0;
        for (int read = 0; read < n; ++read)
        {
            if ((*this).distance(tab[read]) <= R)
            {
                tab[write] = tab[read];
                ++write;
            }
        }
        n = write;
}

// Ex. 6 : afficher un tableau de points (pas obligé d'être dans la classe)
void afficherTableauPoints(const Point* tab, int n)
{
    std::cout << "[";
    for (int i = 0; i < n; ++i)
    {
        tab[i].afficher();
        if (i < n - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

// Ex. 7 : saisir un tableau de points
void saisirTableauPoints(Point* tab, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Point " << i << " :\n";
        tab[i].saisir();
    }
}

Cercle::Cercle(void)
{
    Cercle centre;
    double rayon;
}
Cercle::Cercle(Point a, double b)
{
    centre = a;
    rayon = b;
}
void Cercle::affichage(void)
{
    (*this).centre.afficher();
    cout << (*this).rayon;
}

double Cercle::surface(int N, Point tab[], int size)
{
    int nb_cercle;
    double square = rayon * 2;
    for (int i = 0; i < N;i++)
    {
        double x = (double) rand() / RAND_MAX * rayon;
        for (int j = 0; j < size;j++)
        {
            if (tab[i].distance(centre) <= rayon)
                nb_cercle++;
        }
    }
    return(((nb_cercle/N)* square * square)*4);
}

bool Cercle::isInCircle(Point tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if(tab[i].distance(centre)<=rayon)
            return(true);
        else;
        return(false);
    }
    return(false);
}

bool Cercle::cercleIntersection(Cercle c)
{
    if(rayon + c.rayon >=(*this).centre.distance(c.centre))
        return(true);
    else;
    return(false);
}
