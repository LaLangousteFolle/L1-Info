
void    swap(int *pMin, int *pMax)
{
    int buff;

    buff = *pMin;
    *pMin = *pMax;
    *pMax = *pMin;
}

void    sort(int *a, int *b, int *c)
{
    if (*a < *b)
        swap(a, b);
    if (*b < *c)
        swap(b,c);
}
