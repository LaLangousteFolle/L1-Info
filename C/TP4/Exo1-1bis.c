int     main(void)
{
    int grades[5] = {13, 9, 16, 15, 19};
    for (int i = 0; i <= 4; i++)
        __builtin_printf("%i\n", grades[i]);
    return(0);
}
