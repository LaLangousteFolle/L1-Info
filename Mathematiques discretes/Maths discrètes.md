
Concerne les structures discrètes :
- les éléments sont isolés 
- éléments dénombrables

## Chapitre 1 : Logique et raisonnement

### Logique propositionnelle  :

Logique et langage 

Litéral -> variable ou sa négation
Monôme -> conjonction de literaux (et)
Clause -> disjonction de litéraux (ou)

Forme normale -> pas d'implication ni d'équivalence
Il est important de penser à simplifier en enlevant les éléments neutres

3SAT -> forme où F une formule normale conjonctive possède au plus 3 litéraux par clause
Il est toujours possible de se ramener à cette forme mais difficile

2-SAT -> forme où F une formule en forme normale conjonctive qui possède au plus 3 litéraux par clause, est-elle satisfaisable ? On peux y répondre facilement

#### Déduction

Argumentation valide :
Valide si les prémices sont vraies alors la conclusion est vraie

### Règles d'inférences :

Modus Ponens -> à partir des hypothèses (si on à p et que $p \Rightarrow q$ alors on à q)

Modus Tollens -> à partir de $\neg q$ et $p \Rightarrow q$ on en déduit $\neg p$

Syllogisme hypothétique -> à partir de $p \Rightarrow q$ et $q \Rightarrow r$ on en déduit $p \Rightarrow r$

Syllogisme disjonctif -> à partir de $p \lor q$ et $\neg p$ on en déduit $q$ 

Addition -> à partir de $p$ on en déduit $p \lor q$ 

Simplification -> $p \land q$ on en déduit $p$

Conjonction -> $p$ et $q$ on en déduit $p \land q$ 

Résolution -> $p \lor q$ et $\neg p \lor r$ on en déduit $q \lor r$ (c'est le résolvant)

Réduire un ensemble de clauses, on supprime les clauses vraies
On supprime les clauses qui en contiennent d'autres

#### Prédicats 
- Quantificateur universel $\forall$ (toutes les valeurs)
- Quantificateur existentiel $\exists$ (au mois une valeur)

Ordres de priorités :

- Parenthèses
- Opérations
- Relations
- Négations et quantificateurs
- Opérateurs logiques

Formules équivalentes :

- On peux échanger des quantificateurs identiques $\forall x, \forall y  \equiv \forall y, \forall x$  
- On peux distribuer le quantificateur universel sur la conjonction

Déduction :

- Instanciation universelle 
A partir de $\forall x P(x)$ on en déduit $P(c)$ avec c un élément arbitraire dans le domaine
- Transitivité universelle ($\forall$) de l'implication