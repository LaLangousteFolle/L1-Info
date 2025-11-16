#include "Exo2-1.h"

int main() {

    int age;
    printf("Quel âge avez vous : ");
    scanf("%d", &age);
    age = addOne(age);
    printf("Votre âge l'an prochain : %d.\n", age);
}
