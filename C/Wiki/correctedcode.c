#include <stdio.h>

void    displayBalance(double  current_balance)
{
    printf("Solde actuel : %lf euros\n", current_balance);
}

double  depositMoney(double  current_balance, double  amount)
{
    if (amount > 0)
    {
        current_balance = current_balance + amount;
        printf("+%lf euros effectué.\n", amount)
    }
    else
    {
        printf("Le montant doit être positif !\n");
    }

    return (current_balance);
}

double  withdrawMoney(double  current_balance, double  amount)
{
    if (amount <= 0)
    {
        printf("Le montant doit être positif !\n");
    }
    else if (amount > current_balance)
    {
        printf("Fonds insuffisants ! Solde : %lf euros\n", current_balance);
    }
    else
    {
        current_balance = current_balance - amount;
        printf("-%lf euros effectué.\n", amount);
    }

    return (current_balance);
}

int     main(void)
{
    double  current_balance;
    int     user_choice;
    double  amount;

    current_balance = 0.0;

    while (1)
    {
        printf("1. Afficher le solde\n");
        printf("2. Déposer de l'argent\n");
        printf("3. Retirer de l'argent\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");

        scanf("%d", &user_choice);

        if (user_choice == 1)
        {
            displayBalance(current_balance);
        }

        if (user_choice == 2)
        {
            printf("Montant à déposer : ");
            scanf("%lf", &amount);
            current_balance = depositMoney(current_balance, amount);
        }

        if (user_choice == 3)
        {
            printf("Montant à retirer : ");
            scanf("%lf", &current_balance);
            current_balance = withdrawMoney(current_balance, amount);
        }

        if (user_choice == 4)
        {
            printf("Au revoir !\n");
            break;
        }

        if (user_choice != 1 && user_choice != 2 && user_choice != 3 && user_choice != 4)
        {
            printf("Choix invalide ! Veuillez entrer 1, 2, 3 ou 4.\n");
        }
    }

    return (0);
}
