#include <stdio.h>

/*
Exo 2.1
int   main(void)
{
  int   a;

  printf("Entrez un nombre entier : ");
  scanf("%i", &a);

  if (a > 10)
    printf("%i est superieur a 10", a);
  else 
    printf("%i n'est pas superieur a 10", a);
  return(0);
}
*/

/*
Exo 2.2
int   main(void)
{
  int   a;

  printf("Entrez un nombre pair : ");
  scanf("%i", &a);

  if (a % 2 == 0)
    printf("%i est pair\n", a);
  else
    printf("%i est impair\n", a);
  return(0);
}
*/

/*
Exo 2.3
int   main(void)
{
  int   a,b;

  printf("Entrez deux nombres entiers : \n");
  scanf("%i", &a);
  scanf("%i", &b);

  if ((a - b) > 0)
    printf("%i est plus grand que %i", a, b);
  else
    printf("%i est plus grand que %i", b, a);
  return(0);
}
*/

/*
Exo 2.4
int   main(void)
{
  int   a, b, ope, result;

  printf("Veuillez entrer la premiere valeure : ");
  scanf("%i", &a);
  printf("Veillez entrer la deuxeieme valeure : ");
  scanf("%i", &b);
  printf("Veuillez choisir une operation (1 : +, 2 : -, 3 : *, 4 : /) : ");
  scanf("%i", &ope);

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
  if (ope > 4 || ope < 1) 
  {
    printf("Mauvaise valeure d'operation");
    return(1);
  }
  printf("Resultat : %i", result);
  return(0);
}
*/
