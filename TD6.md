# Rappels
1) L'allocation dynamique permet de s'affranchir des portee des variable locale a un seul et meme bloc.
2) il s'agit de malloc et elle prend un parametre un entier specifiant l'espace a allouer
3) free()

# Exercice 1
```c
int *p;
*p = malloc(sizeof(bool));
```
```cpp
int *value = malloc( sizeof(int) );
```
```cpp
int* ptr = malloc(sizeof(int)); 
*ptr = 42;
```
```cpp
int* ptr = malloc(sizeof(int)); 
free(ptr);
ptr = malloc(sizeof(int) );
```
```cpp
int size = 5
int* ptr = malloc(sizeof(int) * size);
ptr[1] = 42;
```
```cpp
int* ptr = malloc(sizeof(int) );
*ptr = 16;
printf("%d", *ptr);
free(ptr);
prt = malloc(sizeof(int));
*ptr = 42;
```
```cpp
int size = 1;
int* array = malloc( size * sizeof(int) );
```

## Exercice 2
1)
```c
int *entier = malloc(sizeof(int));
```
2)
```c
bool *boolean = malloc(sizeof(bool));
free(boolean);
```
3)
```c
int size = 5;
int *tab = malloc(sizeof(int) * size);
```
4)
```c
int size;
__builtin_printf("saisissez la taille du tableau : ");
__builtin_scanf("%d, &size");
double *tab = malloc(sizeof(double) * size);
free(tab);
```
5)
```c
typedef struct
{
    int nbStudents;
    double * grades;
} MyStruct;
MyStruct a = malloc(sizeof(MyStruct));
```
```c

```
# Exercice 3
[[TD5 Ex3.png]]

# Exercice 4
```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    scanf("%d", &choice);
    if ( choice == 0)
    {
        double * pA = malloc( sizeof(int) );
        * pA = 8;
    }
    else 
    {
        double * pA = malloc( sizeof(int) );
        * pA = 16;
    }

    for (int i = 0; i ++; i < 10)
    {
        double *tmp = malloc( sizeof(double) );
        *tmp = *pA * i;
        printf("%lf", *tmp);
    }
}
```
```cpp
void createArray( int * array, int size)
{
    array = malloc( size * sizeof(int) );
}

int main()
{
    int * array;
    int size = 5;
    createArray( array , size);
}
```
```cpp
int sum(int a, int b)
{
    int result;
    result = a + b ;
    return result;
}

int main()
{
   int i = sum(sum(12 ,15), 13);
}
```
```cpp
void copy (int *array1, int *array2, int size)
{ 
    // elle copie les valeurs d'un tableau à un autre, nous supposons qu'elle est correcte. 
}

void add( int * array, int *currentSize, int maxSize, int value)
{
    if ( currentSize < maxSize)
    {
        array[currentSize] = value;
        currentSize = currentSize +1;
    }
    else
    {
        int * arrayCopy = malloc( maxSize * sizeof(int) );
        copy(array, arrayTmp, maxSize);
        
        array = malloc( (maxSize +20) * sizeof(int) );
        copy(arrayTmp, array, maxSize);
        maxSize = maxSize + 20;
        
        array[currentSize] = value;
        currentSize = currentSize +1;
    }
}

int main()
{
    int totalSize = 5;
    int * array = malloc( maxSize * sizeof(int) ); = {4,5,6,8};
    int size = 4;
    
    add(array, size, totalSize, 12);
    add(array, size, totalSize, 15);
    add(array, size, totalSize, 2);
}
```
# Exercice 5
```c
int *createDynamicArray(void)
{
    int size;
    __builtin_printf("Entrez la taille du tableau : ");
    __builtin_scanf("%d", &size);
    int *tab = malloc(sizeof(int)* size);
    return(tab);
}
```
# Exercice 6
```cpp
typedef struct
{
    int* data;
    int size;
} MyStruct;

int main(void)
{
    MyStruct * obj = malloc( sizeof(MyStruct) );;
    ...
    free(obj.data);
    free(obj);
    ...
}
