Disclaimer:  N'ayant pas encore assiste au CM portant sur les pointeurs, j'ai ecrit cette page pour eclairer ceux qui ne veulent pas s'aventurer dans l'inconnu pour aborder cette notion complexe qu'est les pointeurs. Cependant cette page sera probablement en proie a des modifications/corrections.

Les pointeurs meme si leur nom est trompeur ne "pointent" pas a proprement parler vers une valeur. Les pointeurs sont des variables comme le sont des entiers, des doubles, ou bien des booleens. Ils sont stockes sur 8 octets comme les entier car il contienne une adresse memoire (en format exadecimal) qui correspond a une variable. Ils utilisent une syntaxe particuliere qu'est la suivante:
"inserer image"
Comme nous venons de le voir le poiteur contient diverses informations:
- Le type de la variable vers laquelle il pointe
- Le symbole "\*" indiquant qu'il s'agit d'un pointeur
- Le nom de la variable dans la quelle sera stocké l'adresse mémoire
Voici un récapitulatif de la syntaxe :
"inserer image"

Pour l'instant n'ayant pas encore apprit l'allocation dynamique nous utilisons uniquement la stack (la pile) c'est la ou sont stockes toutes les variables locales aux fonctions (dont nos pointeurs) lors de l'execution de ces dernieres. Ci-dessous un schema sommaire de la representation de la stack lors du stockage de variable locale a une meme fonction:

"inserer image"

Applications pratiques :

"inserer exos"

