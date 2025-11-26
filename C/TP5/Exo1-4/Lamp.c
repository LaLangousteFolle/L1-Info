#include <stdio.h>
#include "Lamp.h"

Lamp createLamp1(void)
{
    Lamp lamp;
    lamp.isOn = false;
    lamp.color = 0;

    return lamp;
}

Lamp createLamp( bool isOn)
{
    Lamp lamp = {isOn}; //avec initialisation sélective, la deuxième valeur est mise à 0 automatiquement
    return lamp;
}

Lamp createLamp2(int color, bool isOn)
{
    if (color > 5)
        color = 0;
    Lamp lamp = {color,isOn};
    return lamp;
}
void isOn(Lamp *lamp)
{
    if ((*lamp).isOn)
        printf("La lampe est allumee\n");
    else
        printf("La lampe est eteinte\n");
}

void printColor(Lamp * lamp)
{
    if( (*lamp).color == 0)
    {
        printf("Couleur blanche\n");
    }
    else if ( (*lamp).color == 1)
    {
        printf("Couleur rouge\n");
    }
    else if ( (*lamp).color == 2)
    {
        printf("Couleur vert\n");
    }
    else if ( (*lamp).color == 3)
    {
        printf("Couleur jaune\n");
    }
    else if ( (*lamp).color == 4)
    {
        printf("Couleur bleu\n");
    }
    else if ( (*lamp).color == 5)
    {
        printf("Couleur violet\n");
    }
}
