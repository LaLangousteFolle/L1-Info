#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

// Exercice 1:
void Point::afficher(void)
{
    cout <<"(" << (*this).x << ","<< (*this).y << ")";
}
//Exercice 2:
void Point::saisir(void)
{
    cout << "Saisir la valeur de x :\n";
    cin >> x;
    cout << "Saisir la valeur de y:\n";
    cin >> y;
}
//Exercice 4:
Point::Point(double a, double b)
{
    (*this).x = a;
    (*this).y = b;
}
//Exercice 5;
double Point::distance(const Point& P)const
{

    return(sqrt(((*this).x - P.x) * ((*this).x - P.x) + ((*this).y - P.y) * ((*this).y - P.y)));
}
//Exercice 6:
void printTab( Point tab[], int size)
{
    for (int i = 0;i < size; i++)
    {
        tab[i].afficher();
    }
}
//Exercice 7:
void createTab(Point *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        tab[i].saisir();
    }
}
//Exercice 8:
double Point::getX(void)const
{
    return((*this).x);
}
double Point::getY(void)const
{
    return((*this).y);
}
void Point::setX(double x)
{
    (*this).x = x;
}
void Point::setY(double y)
{
    (*this).y = y;
}


int main(void)
{
// Exercice 2:

    Point x, y;

    x.afficher();
    y.afficher();

// Exercice 3:

    Point x1, y1;

    x.saisir();
    y.saisir();

    x.afficher();
    y.afficher();

//Exercice 4:
    Point P(5.2,3.8);
    Point P1;

    return(0);
}
