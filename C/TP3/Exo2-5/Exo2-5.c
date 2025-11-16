#include "Exo2-5.h"
void    modify(double min, double max)
{
    double *pMin;
    double *pMax;

    pMin = &min;
    pMax = &max;

    *pMin = *pMin * 2;
    *pMax = *pMax / 2;
}

bool    check(double min, double max)
{
    if (min > max)
        return(false);
    else
     return(true);
}
