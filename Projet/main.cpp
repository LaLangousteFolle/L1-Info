#include "apc.h"

int main(void)
{
    Arbre abr =  Arbre();
    string str = "viande";
    char* c = str.data();
    Arbre abr2 = Arbre(c);
    return(0);
}