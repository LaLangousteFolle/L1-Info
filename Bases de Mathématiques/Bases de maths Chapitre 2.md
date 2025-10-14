
## Chapitre 2 : Le langage ensembliste et les applications 

Le language de la théorie des assembles est basée sur 3 termes : ensemble, élément, appartenance

$x \in E$ un élément appartient à un ensemble 
L'écriture $E \in E$ est interdite 

Deux façons de définir un ensemble :
Par extension, on liste les objets qui lui appartiennent 
$E = \{1,2,4\}$ (entre deux accolades)

Par compréhension, à partir d'une assertion  $P(x)$ :
$E = \{x | P(x)\}$ 
Exemple : 
$E = \{x | x \in \mathbb R, (x-1)(x-2)(x-4) = 0\}$ 

#### Ensemble fini
Si une $E$ est un ensemble fini alors son cardinal est son nombre d'éléments 
Exemple : 
$E = \{1,2,4 \}$ est fini et Card(E) = 3
$E = \mathbb N$ n'est pas fini donc pas de Card (cardinal)
Mais il est dénombrable 

#### Comparaison d'ensemble 
Deux ensembles sont égaux si tout élément de $E$ appartient à $F$ 
$E = F \leftrightarrow (\forall x, (x \in E) \leftrightarrow (x \in F))$ 
Soit $E = \{x | x \in \mathbb R, (x-1)(x-2)(x-4) = 0\}$ 
Et $F = \{1,2,4\}$ , On justifie $E = F$
Soit x un élément 
$x \in E \Leftrightarrow x \in \mathbb  R$ et $(x-1)(x-2)(x-4) = 0$ 
$\Leftrightarrow x \in \mathbb R , (x-1 = 0 , x - 2 = 0 , x - 4 = 0)$ 
$\Leftrightarrow x \in \{1,2,4\} = F$  

Pour tout ensemble $E$ , $E = E$ 
Si $E$ et $F$ et que $E = F$ alors $F = E$ 
Si $E,F,G$ sont des ensembles si $E = F$ et $F = G$ alors $E = G$  (transitivité)
Soit deux ensembles fini $E$ et $F$ si $E = F$ alors $Card(E) = Card(f)$ 
Si $E = F$ et que $E$ est fini alors $F$ est fini aussi 

#### Inclusion
Soit deux ensembles $E$ et $F$ on dit que $E$ est inclus dans $F$ on le note $E \subset F$ se dit aussi :
$E$ est un sous ensemble
$E$ est une partie de $F$ 
Si $F = \{1,2,3,4\}$ , $E = \{2,3\}$ 
$E \subset F$ 
Pour tout ensemble $E$ , $E \subset E$ 
Si $E \subset F$ et $F \subset E$ alors $E = F$  (anti-symétrie)
SI $E,F,G$ sont des ensembles $E \subset F$ et $F \subset G$ alors $E \subset G$ 

Raisonnement par double inclusion 
Pour montrer que ensembles sont égaux on peux procéder par double inclusion c'est à dire que :
$E \subset F$ et $F \subset E$ 
Exemple :
Soit $E = \{n \in \mathbb Z | n-3 \in \mathbb N\}$ 
$F = \{n \in \mathbb Z | n \ge 3\}$ 
On montre que $E \subset F$ 
Soit $n \in Z$. On suppose que $n \in E$ 
On veut montrer que $n \in F$ 
Comme $n \in E$ , $n-3 \in N$, c'est à dire que $n - 3 \ge 0$ 
Or $n - 3 \ge 0 \Leftrightarrow n \ge 3$ donc $n \in F$ on a donc $E \subset F$ 

On montre $F \subset E$ 
Soit $n \in \mathbb Z$. On suppose que n appartient à $F$ 
Comme $n \in F$, $n \ge 3$ $\Leftrightarrow$ $n-3 \ge 0$
Donc $n - 3 \in E$ 
Donc $F \subset E$ par double inclusion $E = F$ 

Si $F$ est fini et $E \subset F$  $\Leftrightarrow Card(E) \le Card(F)$ 

#### L'ensemble vide
On le note $\emptyset$ 
Il n'y a qu'un seul ensemble vide donc si $E$ et $F$ sont des ensembles vides alors $E = F$ 
Tout ensemble contient l'ensemble vide 
Si $E \subset \emptyset$ $\Rightarrow E = \emptyset$ 

Convetions :
$\forall x \in \emptyset, P(x)$ est toujours vraie
$\exists x \in \emptyset, P(x)$ est toujours fausse

### Opérations binaires

#### Réunion 
L'union de $E$ et $F$ se note $E \cup F$ et correspond à $x \in F$ ou $x \in E$ 
Si $G$ est un autre ensemble
$E \cup F = F \cup E$  (commutativité)
$(E \cup F) \cup G = E \cup (F \cup G) = E \cup F \cup G$  (associativité) 
$E \subset E \cup F$ et $F \subset E \cup F$ 

Démonstration de l'associativité (voir cours):

$\forall x \in (E \cup F) \cup G \Leftrightarrow x \in E \cup (F \cup G)$ 
1er équivalent par définition
$\Leftrightarrow (x \in E \cup F) ou x \in G$
$\Leftrightarrow (x \in E ou x \in F) ou x \in G$ 
Suite de la démo sur le cours grâce à l'utilisation de la définition de $\cup$ et de l'associativité 

Si $E$ et $F$ sont deux ensemble finis alors $E \cup F$ est fini et
$Card(E \cup F) \le Card(E) + Card(F)$ 

#### Intersection
Ensemble des éléments qui appartiennent à $E$ et $F$ on note $E \cap F$ 
Pour $E = \{1,2,3,4,5\}$ et $F = \{0,2,4,8\}$ 
Alors $E \cap F = \{2,4\}$ 

Propriétés :
$E \cap F  = F \cap E$ 
$(E \cap F) \cap G = E \cap (F \cap G) = E \cap F \cap G$ 
$E \cap F \subset E$ et $E \cap F \subset F$ 

Soit x un élément
On suppose que $x \in  E \cap F$ 
Cela signifie que $x \in E, x \in F$ par définition de l'intersection
En particulier cela implique que $x \in E$ on a donc montré l'implication et l'assertion

Si $E \cap F = \emptyset$ donc $E$ et $F$ sont disjoints 
$E = \{0,1,2\}$ et $F = \{5,6,7,8\}$
$E \cap F = \emptyset$  

#### Réunions et intersections 
$E \cup (F \cap G) = (E \cup F) \cap (E \cup G)$
$E \cap (F \cup G) = (E \cap F) \cup (E \cap G)$ 

Démonstration de 1 : 
Soit x un élément 
$x \in E \cup (F \cap G) \Leftrightarrow x \in E \space ou \space x \in (F \cap G)$ 
Voir démo sur le cours 
Justification:
Ligne 1 = par définition de $\cup$ 
Ligne 2 = par définition de $\cap$ 
Ligne 3 = par distributivité du "ou" sur le "et"
Ligne 4 = par définition de $\cup$
Ligne 5 = par définition de $\cap$ 

#### Ensembles finis
SI $E$ et $F$ sont finies alors leur intersection est finie et $Card(E \cap F) \le Card(E)$ (marche aussi avec F)
Cardinal de la réunion
$Card(E \cup F) = Card(E) + Card(F) - Card(E \cap F)$ 
$E - F = E$ \ $F$ 

$E \Delta F$ = $(E \cup F)$ \ $(E \cap F)$ (différence symétrique)
La collection des sous-ensembles de E est un ensemble, appelée ensemble des parties de E et noté $P$(E)
On a toujours $\emptyset \in P(E)$ et $E \in P(e)$ 
$E = \{1,2,5\}$ 
$P(E)$ =$\{\emptyset , \{1\}, \{2\}, \{5\}, \{1,2\} , ..., \{1,2,5\}  \}$ 

$P(\emptyset)$ = $\{\emptyset \}$ 
Si $E$ un ensemble fini $P(E)$ est fini et $Card(P) = 2^{Card(E)}$ 
Si A appartient à P(E), le complémentaire de $A$ dans $E$ et ce qui appartient à $E$ mais pas à $A$

#### Propriétés de $P(E)$ 

1 - Le complémentaire d'une complémentaire est l'ensemble de départ
2 -  $(A \cup B)^c = A^c \cap B^c$  
3 -  $(A \cap B)^c = A^c \cup B^c$ 
4 - $E^c = \emptyset$ 
5 - $\emptyset ^c = E$ 

##### Couples d'objets 
$(x1,y1) = (x2, y2) \Leftrightarrow (x1 = x2) and (y1 = y2)$ 

Attention : Il ne faut pas confondre le couple (x,y) et l'ensemble $\{x,y\}$ 
S i$x \neq y$ l'ensemble {x,y}  est une paire 

Si E = {1, 2, 5} et F = {3, 6, 9, 12}
E x F = $\{(1,3), (1,6), (1,9),(1,12),(2,3),(2,6),(2,9),(2,12),(5,3),(5,6),(5,9),(5,12) \}$ 
On peux aussi le faire à l'aide d'un tableau à double entrée 

Si $E$ et $F$ sont finis alors $E \times F$ est fini et $Card(E \times F) = Card(E) \times Card(F)$ 

![[Pasted image 20251006102748.png]]
^ Cf : propriétés de la page 34 du cours

Exemple : A = {1, 2}, B = {3, 6}, 
C = {2, 5} et D = {6, 9, 12}

| E/F | 3     | 6                             | 9     | 12     |
| --- | ----- | ----------------------------- | ----- | ------ |
| 1   | (1,3) |                               |       |        |
| 2   |       | $(A \cap C)\times (B \cap D)$ | (2,9) |        |
| 5   |       |                               |       | (5,12) |
##### Plan cartésien :
Si $E = F = \mathbb R$ alors le produit E x F = $\mathbb R^2$ 
on associe à chaque couple (x, y) de $\mathbb R^2$  le point de coordonnées x, y du plan

### 3. Relations binaire

#### Relation, relation binaire
Soit E et F deux ensembles. On appelle relation de E vers F tout triplet (E, $\Gamma$ , F) ou $\Gamma$   est une partie du produit E x F.

$\Gamma = \{(1,3),(2,12)\}$ 
Si (x,y) $\in \Gamma$ on notera $x R y$  (x en relation avec y)
Si E et F sont deux ensembles finis, on peut représenter une relation par un diagramme (ou schéma) sagittal où on aligne verticalement les éléments de E sur la gauche, les éléments de F sur la droite et on dessine une flèche d’un élément x vers un élément y lorsque $xRy$ 

Une relation $R = (E, \Gamma,F)$ de $E$ vers $F$ est dite binaire si $F = E$ 
Donc si $(x,y) \in \mathbb Z \times \mathbb Q$ 

![[Pasted image 20251006105852.png]]
^ Cf: propriétés page 41

#### Relation d'équivalence
Une relation binaire $R$ est un relation équivalente si $R$ est réflexive, symétrique, transitive
Si E est l’ensemble des droites du plan, on définit // par D // D→ si et seulement si les droites D et D→ sont parallèles. Alors // est une relation d’équivalence
Réflexive une droite est parallèle à elle meme 
Si d // d1 alors d1 // d donc symétrique
Si d//d1 et d1//d2 alors d//d2 donc transitive

#### Classe d'équivalence
Soit R est une relation d’équivalence dans un ensemble E et x un élément de E. On appelle classe d’équivalence de x l’ensemble noté cl(x) des éléments de E en relation avec x
$cl(x) = \{y \in E | xRy\}$ 

Si E est l'ensemble des droites du plan, pour la relation //, si D est une droite du plan
$cl(D) = \{D' \in E | D // D'\}$ 

#### Relation d'ordre 

Définition : relation d'ordre si $R$ est réflexive, antisymétrique, transitive

$\forall A,B$ de P(E), $ARB \Leftrightarrow$ $A \subset B$ alors $R$ est réflexive, antisymétrique et transitive, relation d'ordre

Dans la relation $\mathbb Z$ noté $\le$ définie par :
$\forall (n,p) \in \mathbb Z^2, n \le p \Leftrightarrow p-n \in \mathbb N$ 

Réflexive ? $\forall n \in \mathbb Z, nRn$  Oui
Soit $n \in \mathbb N$. n-n = 0 donc $n-n \in \mathbb N$ 

Antisymétrique ? $\forall (n,p) \in \mathbb Z$ , ($nRp$ et $pRn$) $\implies$ n = p Oui
Soit (n,p) $\in \mathbb Z$ 
On suppose que $nRp \Leftrightarrow$ p-n appartient à N donc p-n $\ge$ 0
$pRn \Leftrightarrow n-p \ge 0$ 
Donc n-p = -(p-n) donc opposés
$a \ge 0$ donc p-n = 0 donc p = n

Transitivité 
$\forall (n,p,k) \in \mathbb Z^3$ $(nRp . pRk) \implies nRk$  
k - n = (k-p) + (p-n) 
donc $nRk$ la relation est transitive on a donc une relation d'ordre