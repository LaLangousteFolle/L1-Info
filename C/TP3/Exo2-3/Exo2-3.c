void    modify(double *user_value)
{
    if (*user_value < 0)
        *user_value = *user_value * 3;
    else
        *user_value = *user_value / 2;
}
