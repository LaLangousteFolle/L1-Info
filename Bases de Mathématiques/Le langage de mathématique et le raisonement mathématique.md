code cours : basesmaths_I1

 3 processus fondamentaux:
 - Objets mathématiques
	 - Nombres
	 - Opérations
	 - Formules
	 - Signes
	 - Droites
	 - Triangles
	- Fonctions  
 - Assertions
	 - Deux droites parallèles ne se rencontrent pas
	 - $2 < 3$
	 - La fonction $\mathbb{R}\to{x }$--> est décroissante 
- Démonstration
	- Vraie
	- Vraie
	- Fausse

**Axiome** = Assertion dont on décide qu'elle est vraie a priori
	1er axiome d'Euclide
		Par deux points passent une unique droite
		
**Théorème** =  
	Théorème de Thalès
	Inégalité de Bienaimée Tchebychev

**Tautologie** = une assertion qui est toujours vraie par les règles du calculs sur les assertions.

## Table de vérité
- Négation
- Conjonction = and logic gate
- Disjonction = or logic gate
- Implication = if/else statement
	- Implication de $Q \Rightarrow P$ est la **réciproque** de $P \Rightarrow Q$
	- Implication de $\overline{Q} \Rightarrow \overline{P}$ est la **contraposée** de $P \Rightarrow Q$
- Equivalence = les deux conditions doivent être vérifiée **ou** infirmées
	- commutativité du or et du and
	- associativité du or et du and
	- distributivité du or et du and
## Quantificateurs

L'assertion "pour tout x appartenant à l'ensemble A, P(x) est vraie"
est notée $\forall x \in A, P(x)$
L'assertion est vrai si et seulement si un nombre$x$ appartenant à $]-1, 2[$, on a $x² - x - 2$ est strictement négatif se foramlise mathématiquement en:
$\forall x \in ]-1, 2[, x² - x - 2 < 0$
L’assertion “il existe (au moins un) x appartenant à A tel que P(x) soit vraie” est notée
$\exists x \in \mathbb{R}, x²+5x +3=0$
- L'assertion il existe un unique $x$ appartenant a A tel que P(x) est vraie notée
##### Négation d'une assertion 
$non(∀ x ∈ A, P(x))$
deviens 
$\exists x\in A$ non$(P(x))$


P: $\exists x \in]-1, 2[, x²-x2<0$
non(P): $\exists x \in]-1, 2[, x^{2}-x-2\ge{0}$
Q: $\exists x\in \mathbb{R}, x²+5x+3=0$
non(Q): $\forall x\in\mathbb{R}, x²+5x+3\neq{0}$
Autre prop:
exemples:

$\Leftrightarrow(\forall x\in]-1,2[,x²-x-2<0)$ et $(\forall x \in]-1,2[,x\le{0})$

$\Leftrightarrow (\exists x \in <\mathbb{R},x²+5\times+3=0)$ ou $(\exists x\in\mathbb{R}, x\ge{0})$
##### Interversion des quantificateurs
Les assertions suivantes sont équivalentes:
$∀x ∈ A, ∀y ∈ B, P(x, y) \Leftrightarrow  ∀y ∈ B, ∀x ∈ A, P(x, y);$


Ex:
2
$\forall y \in \mathbb{R}, \forall x \in \mathbb{R}, x+y\in \mathbb Z$
4
$\exists y\in\mathbb{R}, \exists x\in\mathbb R,x+y\in \mathbb Z$

5$\not\Leftrightarrow$ 6
6 est vraie
soit $y\in\mathbb{R}$.
pour $x=-y$, on a bien $x+y=0$ donc $x+y \in \mathbb R$
5 est faux


## Raisonement mathématique
#### Raisonement direct (syllogisme)
Si les assertions P et (P ⇒ Q) sont vraies, alors l’assertion Q est vraie. L’assertion (P ⇒ Q) peut être, par exemple, sous la forme d’un théorème ou d’un corollaire.

Ex:
Réciproque du théorème de Pyhtagore
Si $ABC$ est un triangle tel que $AB² + AC² = BC²$ alors $ABC$ est rectangle en $A$.
Comme ici
$AB² + AC² = 3²+2² = 13 + BC²$
par la réciproque du théorème de Pythagore le triangle est rectangle en $A$.

#### Rédaction du raisonement direct
Pour montrer que (P ⇒ Q) est vraie, on fait l’hypothèse que l’assertion P est vraie, et on montre que l’assertion Q est vraie. Une d´emonstration de (P ⇒ Q) est introduite par l’expression “Supposons P” et se termine par “donc Q”

Ex:
Supposons que $x>2$.
Comme la fonction $x \Rightarrow x²$ est croissante sur $[0, +  \infty[$, est comme $x>2$, en particulier $x\ge 0$ on a donc $x²>2²$
càd $x²>4$

##### Démonstration d'une assertion
Pour montrer qu’une assertion de la forme (∀x ∈ A , Q(x)) est vraie, on écrit “’Soit x un élément de A” ou “Soit x ∈ A”, et on montre que Q(x) est vraie.

Ex:

$∀ n ∈ \mathbb Z, n^2 − 6n + 9 ∈ \mathbb N.$
Soit $n\in\mathbb Z.$
On sait que $n^2-6n+9\in\mathbb Z$
Il s'agit de montrer que $n^2-6n+9\ge{0}$
Or $n^2-6n+9=(n-3)^2$
Donc $(n-3)^{2}\ge{0}, n^{2}-6n+9\ge{0}$
L'assertion est vraie: $\forall n\in \mathbb Z$

## Raisonement par séparation des cas (ou disjonction des cas)
Il s’applique losqu’on veut démontrer une assertion de la forme ((P1 ou P2) ⇒ Q). Pour cela, on montre successivement que si P1 est vraie, alors Q est vraie et que si P2 est vraie, alors Q est vraie.

Ex:
Démontrer l’assertion suivante : “pour tout nombre réel $x, |x − 2| < x^2 − 2x + 3$”.
$\forall x \in \mathbb  R, |x-2|<x^2-2x+3$
Soit $x\in\mathbb R$

On sait que $|x-2| = x-2$ si $x-2 \ge{0}$
					ou $-(x-2)$ si $x-2 <0$
Or $x^2-3x+5$ a pour discriminant
$=3^{2}- 4\times{1}\times 5<0$
donc $x^2-3+5$ est du signe de delta donc strictement positif
L'affirmation étant vraie pour $x\ge_{2}$ et $x < 2$, $\forall x\in\mathbb R, |x-2| < x^2-2x+3.$

### Raisonement par contraposé
On a vu dans la Section 2: (P ⇒ Q) est équivalente à sa contraposée (non Q ⇒ non P). Donc, raisonner par contraposée pour montrer que l’assertion (P ⇒ Q) est vraie, c’est d´emontrer que l’assertion (nonQ ⇒ nonP) est vraie.

Ex:
Soit x un nombre réel. Démontrer l’assertion suivante $(x \neq 2) ⇒ x^2 − 4x + 10 \neq 6).$

$x^2-4x+10=6\Rightarrow x =2$
Supposons aue $x^{2}-4x+10=6$
$x^{2}-4x+10=6 \Leftrightarrow x^{2}-4x+4=0$
$\Leftrightarrow(x-2)^{2}=0$
$\Leftrightarrow x-2 =0$
$\leftrightarrow x = 2$
la contraposée est démontrée.

#### Raisonement par l'absurde
Pour montrer qu’une assertion Q est vraie, on fait l’hypothèse qu’elle est fausse, c’est-à-dire que non Q est vraie. On en déduit qu’une certaine assertion R (à déterminer) est à la fois vraie et fausse, ce qui est impossible: on dit que c’est une contradiction ou que c’est contradictoire.

Ex: Démontrer, en raisonnant par l’absurde, que “pour tout nombre réel $x$, $x^2 − 2x + 2 \neq 0$”.
Soit $x\in\mathbb{R}$
On suppose ==par l'absurde== que $x^{2}-2x+2 = 0$
Le discriminant de $X^{2}-2X+2$ est 
delta = $2^{2}-4 \times 1\times 2= -4<0$
Donc $X^{2}-2X+2$ n'a pas de zéro: contradiction avec $x^{2} -2x=0$
Conclusion:
$\forall x \in \mathbb R, x^{2}$
