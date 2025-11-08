#include <stdio.h>
#include <stdbool.h>

void    modify(int min, int max)
{
    int     *modified_min;
    int     *modifier_max;
    modified_min = &min;
    modifier_max = &max;
    *modified_min = *modified_min * 2;
    *modifier_max = *modifier_max / 2;
}

bool    check(int *min, int *max)
{
    if (*min < *max)
        return(true);
    else
     return(false);
}

int     main(void)
{
    int     *min;
    int     *max;
    bool    user, user_tried;
    user_tried = false;
    while(user!= false)
    {
        user = check(min, max);
        if (user != true)
            printf("Vos nombres ne sont pas corrects /n");
            printf("Entrez le min : ");
            scanf("%i", min);
            printf("Entrez le max : ");
            scanf("%i", max);
    }

    return(0);
}
