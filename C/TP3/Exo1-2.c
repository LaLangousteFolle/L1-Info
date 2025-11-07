int     main(void)
{
    int age;
    int     *pAge;
    age = 18;
    pAge = &age;
    *pAge = 25;
    __builtin_printf("age = %i", age);
    return(0);
}
