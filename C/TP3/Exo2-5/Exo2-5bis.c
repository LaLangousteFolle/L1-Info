#include <stdbool.h>

void    modify(double *pMin, double *pMax)
{
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

void    swap(double *pMin, double *pMax)
{
    double *buffer;
    double buff = 0.0;

    buffer = &buff;
    *buffer = *pMin;
    *pMin = *pMax;
    *pMax = *pMin;
}
