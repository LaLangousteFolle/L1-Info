#include <stdlib.h>
#include <stdio.h>
/* 
void addExpense(int *tab, int depense, int day)
{
    tab[day] = tab[day] + depense;
}

void manageExpense(int *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        int jour, value;
        printf("Quel jour souhaitez vous modifier? : ");
        scanf("%d", &jour);
        printf("Quelle valeur souhaitez vous entrer? : ");
        scanf("%d", &value);
        addExpense(tab, value, jour);
    }
}

int     main(void)
{
    int size;
    printf("entrez la size : ");
    scanf("%d", &size);
    int *tab = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        printf("%d", tab[i]);
    free(tab);
    return(0);
}
*/

void bookSeat(int *seats_available, int *reservation)

{
    int section;
    
    printf("Quelle section? : ");
    scanf("%d", &section);
    
    if (seats_available > 0)
    {
        *seats_available --;
        reservation[section] += 1;
    }
}

void processBooking(void)
{
    int num_place;
    printf("Combien de places souhaitez vous prendre? : ");
    scanf("%d", &num_place);
    
}

int     main(void)
{
    int seats_available, num_section;
    printf("Combien de sections y'a-t-il? : ");
    scanf("%d", &num_section);
    int *reservations = malloc(sizeof(int) * num_section);
    for (int i  = 0; i < num_section;  i++)
        reservations[i] = 0;

    return(0);
}