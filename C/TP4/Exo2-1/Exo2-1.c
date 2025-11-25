void initializeHundredCasu(int tab[])
{
    for (int i = 0; i < 100; i++)
        tab[i] = i;
}

void initializeHundredEven(int tab[])
{
    for (int i = 0; i < 100; i++)
        tab[i] = i * 2;
}

void    displayArray(int tab[], int size)
{
    for (int i = 0; i <=size; i++)
        __builtin_printf("%i ", tab[i]);
}
