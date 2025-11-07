1) Une fonction sert a effectuer des operation, leurs presences sert a simplifier le code et ca comprehension.
2) Les differentes parties de la fonctions:
- Le type renvoye par la fonction
- Le nom de la fonctions
- Ses eventuels arguments
1) Il s'agit du fait que la valeur entree en parametre n'est pas la reelle valeur de la variable, mais une copie
2) Elles sont locales (propres a la fonction)
## Exercice 2
1) mean
2) entier (total; nbElements)
3) Un nombre decimal
## Exercice 3
```c
int    add(int a , int b); 
int multiplyByCoeff ( int value, double coeff );
int multiply ( int x , int y );
int substract (int a, int b);
```
## Exercice 4
```c
double calculMoy(int a, int b);
bool isEven(int nbr);
double calculMax(double a, double b, double c);
bool isPresent(int nbr, int nbr_max int nbr_max);
void isPos(int nbr);
```
## Exercice 5
```cpp
#include <stdbool.h>
bool isEven (int number)
{ 
    if (number % 2 == 0) 
    { 
        return true; 
    }
    else
    { 
        return false; 
    } 
} 
```
```cpp
bool isInRange ( int value, int min, int max) 
{ 
    if (value >= max && value <= min) 
    { 
        return true;
    } 
    else
    {
        return false;
    }
} 
```
## Exercice 6
```cpp
#include <stdio.h>
bool isPositive ( int number) 
{ 
    if (number >= 0) 
    {
        return(true); 
    } 
    else 
    { 
        return(false); 
    } 
}

int main(void)
{ 
	int  nombre; 
    printf("Entrez un nombre :);
    scanf("%d", &nombre);
    bool result = isPositive (nombre) ;
    if ( result == false ) 
    { 
        printf("Le nombre n'est pas positif.\n");
    }
    else
    { 
        printf("Le nombre est positif.\n"); 
    }
    return(0);
} 
```
## Exercice 7
```cpp
#include <stdio.h>

int calcToN(int n)
{
	int sum,i;
	for (i = 1;i <= n; i++)
		sum = sum + i;
	return(sum)
}
int main(void)
{ 
    int n, result; 
    printf("Entrez un nombre entier positif: ");
    scanf("%d",&n);
    result = calcToN(n);
    printf("La somme des nombres de 1 à %d est: %d.\n",n,result); 
    return(0); 
} 
```
```cpp
#include <stdio.h>
int    calcMean(int grade1, int grade2, int grade3)
{
	double mean;
    
    mean = (grade1 + grade2+ grade3) / 3.0;
    return(mean);
}

void   isMeanSufficient(int mean)
{
	double limit = 10.0; 
    if (mean >= limit)
    { 
        printf("La moyenne est suffisante: %f.\n", mean);
    }
    else
    {
        printf("La moyenne n'est pas suffisante: %f.\n", mean);
    }
}
int main()
{ 
	double grade1;
    double grade2;
    double grade3;
    
    printf("Entrez la première note: ");
    scanf("%f", &grade1);
    printf("Entrez la deuxième note: ");
    scanf("%f", &grade2);
    printf("Entrez la troisième note: ");
    scanf("%f", &grade3);
	isMeanSufficient(calcMean(grade1, grade2, grade3));
    return(0);
} 
```
## Exercice 9
