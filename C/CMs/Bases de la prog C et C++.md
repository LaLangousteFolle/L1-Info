30% de la note est la présence aux TD de bases de prog et en AMS 

### 1 Algorithme, variables

Langage bas niveau : proche du langage machine
Langage haut niveau : proche du langage humain

Utilisation d'un compilateur :
 - Transformer le code source en langage machine
 - Optimiser le code
 - Analyse lexicale 

Le code est compilé pour la machine en particulier, un code compilé en 64 bits ne marcheras pas sur du 32 bits

### Les variables 

Doivent etres typés car chaque type a sa propre taille
Les entiers -> int
Les decimaux -> double
Les booleens -> bool

Conventions :
- en anglais minuscule
- commence par une lettre
- seulement underscore en symbole

Il est important  d'affecter une valeur 

Pour afficher quelque chose on utilise printf()

Pour afficher le contenu d'une variable :
Pour un entier "%d"
Pour un double "%f"
Pour un booléen "%d"

#### Enregistrer dans une variable la valeur saisie
scanf("%type", &nom_variable)
Pour un scan un double devient "%lf" 

Opérateurs logiques :
&& -> AND
|| -> OR
! -> NOT

for (int i = 0; i < 10; i++)
{
}
La mémoire :
Organisation LIFO (last in first out) pile
Mémoire rapide
Un nouveau bloc = une nouvelle zone
A la fin d'un bloc -> la zone est vidée

La portée 
Une variable dans un bloc a une portée locale 
    1









