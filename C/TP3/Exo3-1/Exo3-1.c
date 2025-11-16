void    arithmetic(double *a, double *b)
{
    double buff_a,buff_b;

    buff_a = *a;
    buff_b = *b;
    *a = buff_b + buff_a;
    *b = buff_a * buff_b;
}
