#include <stdio.h>

/*
Exo 3.1
int   main(void)
{
  int   i;

  i = 0;
  while(i != 10)
  {
    i++;
    printf("%i\n", i);
  }
  return(0);
}
*/

/*
Exo 3.1bis
int   main(void)
{
  int   i;

  i = 0;
  while(i != 10)
  {
    i++;
    printf("%i ", i);
  }
  return(0);
}
*/

/*
Exo 3.2
int   main(void)
{
  int   a, i, value;
  printf("Entrez un entier : ");
  scanf("%i", &a);
  while (i != a)
  {
    i++;
    value += i;
  }
  printf("La somme des entiers de 1 a %i est %i", a, value);
  return(0);
}
*/

/*
Exo 3.3
int   main(void)
{
  int a, i, value;
  printf("Entrez un entier : ");
  scanf("%i", &a);
  while (i != 10)
  {
    i++;
    printf("%i * %i = %i\n", a, i, a * i);
  }
  return(0);
}
*/


int   main(void)
{
  int   a, b, ope, result;

  printf("Veuillez entrer la premiere valeure : ");
  scanf("%i", &a);
  printf("Veillez entrer la deuxeieme valeure : ");
  scanf("%i", &b);
  printf("Veuillez choisir une operation (0 : quitter, 1 : +, 2 : -, 3 : *, 4 : /) : ");
  scanf("%i", &ope);

  while (ope != 0)
  {
    if (ope == 1)
      result = a + b;
    if (ope == 2)
      result = a - b;
    if (ope == 3)
      result = a * b;
    if (ope == 4)
    {
      if (b == 0)
      {
        printf("Division par 0 impossible");
        return(1);
      }
      else
      result = a / b;
    }
    if (ope == 0)
      printf("Au revoir");
    if (ope > 4 || ope < 0) 
    {
      printf("Mauvaise valeure d'operation");
      return(1);
    }
    printf("Resultat : %i\n", result);
    printf("Veuillez choisir une operation (0 : quitter, 1 : +, 2 : -, 3 : *, 4 : /) : ");
    scanf("%i", &ope);

  }
  return(0);
}
