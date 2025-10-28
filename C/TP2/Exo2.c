#include <stdio.h>

int    addGrade(void)
{
    int     grade;
   printf("Entrez une note : ");
    scanf("%i", &grade);
    return(grade);
}
void    mean(int nbGrades)
{
    int     i;
    float   moy;
    i = 0;
    while (i < nbGrades)
    {
      moy += addGrade();
      i++;
    }
  moy = moy / nbGrades;
  printf("La moyenne est : %f", moy);
}

int   main(void)
{
  int   value;
  printf("Entrez le nombre de notes : ");
  scanf("%i", &value);
  mean(value);
  return(0);
}
