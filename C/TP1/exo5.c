#include <stdio.h>

int   main(void)
{
  int   n, i, j;

  i = 0;
  printf("Veuillez saisir un nombre : ");
  scanf("%i", &n);
  while (n != i)
  {
    j = 0;
    while (j != i + 1)
    {
      printf("* ");
      j++;
    }
    i++;
    printf("\n");
  }
}
