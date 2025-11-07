int     main(void)
{
    int age;
    int     *pAge;
    age = 0;
    pAge = &age;

    __builtin_printf("Veuillez renseigner votre age: ");
    __builtin_scanf("%i", &*pAge);
    __builtin_printf("vous avez %i ans", *pAge);
    return(0);
}
