#include <stdio.h>
void afficher_solde(double s){
    printf("Solde actuel : %lf euros\n",&s);
}
double deposer(double sa, double m){
    if(m>0){
        sa=sa+m;
        printf("+%lf euros effectué.\n",m)
    } else
        printf("Le montant doit être positif !\n");
    return sa;
}
double retirer(double sa,double m){
    if(m<=0)
        printf("Le montant doit être positif !\n");
    else if(m>sa)
        printf("Fonds insuffisants ! Solde : %lf euros\n",sa);
    else{
        sa=sa-m;
        printf("-%lf euros effectué.\n",m);
    }
    return sa;
}
int main(){
    double s=0.0;
    int c;
    double m;
    while (1){
        printf("1. Afficher le solde\n");
        printf("2. Déposer de l'argent\n");
        printf("3. Retirer de l'argent\n");
        printf("4. Quitter\n");
        printf("Votre choix :");
        scanf("%lf",&c);
        if (c==1)
            afficher_sold(s);
        if (c==2){
            printf("Montant à déposer :");
            scanf("%lf", &m);
            s=deposer(s,m);
        }
        if (c==3){
            printf("Montant à retirer :");
            scanf("%lf",&s);
            s=retirer(s,m);
        }
        if (c==4){
            printf("Au revoir !\n");
            break;
        }
        if (c!=1&&!=2&&!=3&&!=4)
            printf("Choix invalide ! Veuillez entrer 1, 2, 3 ou 4.\n");
    }
}
