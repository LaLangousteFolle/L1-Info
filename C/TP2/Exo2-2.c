#include <stdio.h>

int   max(int a, int  b)
{
  if(a > b)
    return(a);
  else
    return(b);
}
int     max(int  a, int  b, int  c)
{
    int temp1, temp2, result;
    temp1 = max(a,b);
    temp2 = max(temp1,c);
    return(temp2);
}

int   main(void)
{
    int     a, b, c, result;
    printf("Veuillez entrer la valeur 1 : ");
    scanf("%i", &a);
    printf("Veuillez entrer la valeur 2 : ");
    scanf("%i", &b);
    printf("Veuillez entrer la valeur 3 : ");
    scanf("%i", &c);

    result = max(a,b,c);
    printf("La plus grande valeur est : %i\n", result);
  return(0);
}
