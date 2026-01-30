#include "Point.h"
#include <iostream>

using namespace std;
int main()
{
    Point P(2,4);
    Point P1(3,17);
    Point P2(2,4);
    P.afficher();
    cout<<endl;
    P.distance(P1);
    P.egale(P2);
    P.compterPointsDansCercle(&P, 3, 3.14);
    P.supprimerPointsHorsCercle(&P, 3, 3.14);

}
