#include <stdio.h>
int addOne ( int number )
{
    return(number = number +1);
}

int main() {

    int age;
    printf("Quel âge avez vous : ");
    scanf("%d", &age);
    age = addOne(age);
    printf("Votre âge l'an prochain : %d.\n", age);
}
