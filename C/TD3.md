Exercice 1
1) Une variable normale stock une valeur, et un pointeur stock un adresse memoire vers une valeur
2) L'operande & sert a obtenir la valeur de l'adresse memoire tandis que * sert a obtenir la valeur contenu a cettte adresse

### Exercice 2
```c
int *p1;
int *p2 = &p1;
```
```c
double f = 3.14; 
double *pf = &f; 
```
```cpp
int *p;
int x;
x = 5;
*p = &x
```
```cpp
int *p;
int x = 10;
*p = &x;
```
```cpp
int y = 18 ;
int *p4 = &y;
```
```cpp
double x = 13.25
double *q = &x ;
double **p9 = &q;
```


## Exercice 3
```c
int age;
int *pAge;
age = 42;
*p = &age;
```
```c
double temperature = 14.3;
double *pTemperature;
*pTemperature = &temperature;
```
### Exercice 4
```cpp
#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    double x = 2.5;
    double y = 4.0;
    bool flag = true;
     
    int *pa = &a;
    double *px = &x;
    bool *pf = &flag;
     
    *pa = *pa + 3;
    *px = *px * 2;
    *pf = !(*pf);
     
    int *pb = &b;
    *pb = *pa - 2;
     
    double z = *px + 1.5;

    printf("a = %d.\n", a);
    printf("b = %d.\n", b);
    printf("c = %d.\n", c);
    printf("x = %f.\n", x);
    printf("y = %f.\n", y);
    printf("flag = %d.\n", flag);
    printf("z = %f.\n", z);
}
```
8
6
erreur
5.0
4.0
0
6.5

### Exercice 6
```cpp

#include <stdio.h>

int main() {
    int a = 1;
    int *pa;
    
    *pa = &a;
    *pa = 2;
    
    printf("a = %d.\n", a);
}
```
```cpp
#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    int *pa = &a;
    int *pb = &b;
    
    *pa = a + b;
    
    printf("a = %d.\n", a);
    printf("b = %d.\n", b);
}
```
```cpp
#include <stdio.h>

int main() {
    int x = 7;
    int y = 3;
    int *px = &x;
    int *py = &y;
    
    *px = *py; 
    *py = &x;
    *py = -15; 
    
    printf("x = %d.\n", x);
    printf("y = %d.\n", y);
}
```

### Exercice 7
```c
int main(void)
{
int num;
int *pNum;
num = 10;
*pNum = &10
__builtin_pritf("%d", *pNum);
return(0);
}
```
```c
int main(void)
{
double price = 19.9;
double *pPrice= &price;

*price = 25.5;
return(0);
}
```
```c
int main(void)
{
bool flag = true;
bool *pFlag;
__builtin_printf("%d", *pFlag);
return(0);
}
```
### Exercice 8
```cpp
void swap ( int *a, int *b );

void addValue ( int * number, int value );

double *compareDoubles ( double *a, double *b );
void modifyDouble (double *value , double newValue);

void getOpposites ( int *a, int *b);
void getSumProduct ( int a, int b, int *sum, int *product );
```
### Exercice 9
```c
void celsiusToFarenheit(double *temp)
{
 *temp = ((*temp)*9/5) + 32;
}
int main(void)
{
double temp = 25.9;
double *pTemp = &temp;
celsiusToFarenheit(pTemp);
__builtin_printf("%lf", *pTemp);

return(0);
}
```