int     main(void)
{
    int  age;
    int *pAge;

    age = 12;
    pAge = &age;
    __builtin_printf("La valeur de age en direct %i\n",age);
    __builtin_printf("La valeur vers laquelle pointe age %i\n", *pAge);
    return(0);
}
