#include <stdio.h>

int   main(void)
{
  int   n, i, j, k;

  printf("Veuillez entrer un entier : ");
  scanf("%i", &n);

  i = 0;
  while (i != n)
  {
    j = 0;
    while (j != n)
    {
      if (i == 0 || i == n)
      {
        printf("*");
        j++;
      }
      else 
      {
        while (k != n)
        {
          if (k == 0 || k == n)
            printf("*");
          else
            printf(" ");
        }
        j++;
      }
    }
    i++;
  }
}
