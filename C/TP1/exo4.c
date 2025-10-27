#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int   main(void)
{
  srand(time(0));
  int   mysteryNumber, userValue, tryCount;
  
  tryCount = 1;
  mysteryNumber = rand() % 100 + 1;
  printf("Devinez le nombre mystere : ");
  while (userValue != mysteryNumber)
  {
    printf("Essai %i : ", tryCount);
    scanf("%i", &userValue);
    if (userValue > mysteryNumber)
      printf("Le  nombre mystere est plus petit que %i\n", userValue);
    if (userValue < mysteryNumber)
      printf("Le nombre mystere est plus grand que %i\n", userValue);
    if (userValue == mysteryNumber)
      printf("Le nombre mystere etait bien %i, et vous l'avez trouve en %i essais\n", mysteryNumber, tryCount);
    tryCount++;
  }
  return(0);
  
}

