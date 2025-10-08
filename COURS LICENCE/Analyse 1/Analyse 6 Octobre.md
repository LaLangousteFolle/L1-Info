#### Fonctions monotones :

$f$ est croissante sur D si f(x+1) >= f(x) : f(x+1) > f(x) si stricte

$f$ est décroissante sur D si f(x) >= f(x+1)  : f(x) > f(x+1) si stricte

Raciné  carrée est strictement croissante sur $\mathbb R^+$ 
Soit $a,y \in \mathbb R$ On montre que $x < y \implies \sqrt x < \sqrt y$ 
On calcule $f(y) - f(x)$ et on trouve que la fonction est croissante

Une fonction affine est strictement croissante si $a > 0$ et décroissante stricte  si $a < 0$ 
La fonction $x \rightarrow x^3$ est strictement croissante
Soit $x < y$ 
On regarde le signe de $y^3 - x^3 = (y-x)(y^2 + xy + x^2)$ 
$(y -x) > 0$ et de meme pour l'autre membre de l'équation
Donc la fonction est strictement croissante

On étudie les variations d'une fonction $f$ avec un tableau de variation en renseignant le minimum et maximum s'ils existent

Avec $D$ une partie de $\mathbb R$ symétrique par rapport à 0 c'est à dire :
$\forall x \in D, -x \in D$ 

Une fonction $f : D \rightarrow \mathbb R$  est dite paire si $\forall x \in D, f(-x) = f(x)$  symétrie par l'axe des ordonnés 
Une fonction $f : D \rightarrow \mathbb R$ est dite impaire si $\forall x \in D, f(-x) = -f(x)$ symétrie par l'origine 

$f$ est T-périodique lorsque $f(x+T) = f(x)$ 

Remarque si $f$ est T-périodique:
$\forall x \in \mathbb R, f(x) = f(x+T) = f(x + kT), k \in \mathbb Z$ 
Exemple les fonction trigonométriques (sin(x) et cos(x)) $2\pi$ périodique
Fonction partie décimale : $\forall x \in [0,1], f(x) = x$ 
$f$ est périodique de période 1

#### Fonctions polynomiales et fonctions rationnelles

Soit $n \in \mathbb N$. On appelle une fonction polynomiale de degré $n$ toute fonction :
	$a_0 + a_1 x ... + a_n x$ 

La fonction $x \rightarrow 0$ a par convention $- \infty$ comme degré
Une fonction polynomiale de degré 2 est une fonction $f$ de type $f(x) = ax^2 + bx + c$ avec $a \neq 0$
Le sommet de la parabole est de coordonnées (-b/2a, $\Delta /4a$) 

Propriétés : la somme, la produit, la composition de deux fonction polynomiales sont des fonctions polynomiales

Si $f(x) = g(x)$ alors tout les coefficients sont les mêmes 
Preuve lorsque n = 2
Soit $f$ avec deg(f) <= 2 et $g(x)$ avec deg(g) <= 2
Supposons que $f(x) = g(x)$ 
$f(0) = g(0)$    $a_0 = b_0$
$f(1) = g(1)$    $a_0 + a_1 + a_2 = b_0 + b_1 + b_2$ 
$f(2) = g(2)$ 

Factorisation d'une fonction polynomiale de degré n. Si $f(\alpha) = 0$ 
Alors :$\forall x \in \mathbb R, f(x) = (x-\alpha)g(x)$  g(x) est de degré n-1

Exemple 1 : $f(x) = x^3 -1$
$f(x) = (x-1)(ax^2 +bx +c)$ = $ax^3 + (b-a)x^2 + (c-b)x -c$ 
$f(x) = (x-1)(x^2 + x + 1)$ 

On peut faire de même pour un polynôme de plus haut degré en faisant des factorisations successives 

##### Fonction rationnelles 

Soit $f$ est une fonction rationnelle si $f : x \rightarrow P(x)/Q(x)$  ces fonctions ne sont que très rarement définies sur $\mathbb R$ , on peux aussi les simplifiez 
1 - Déterminer l'ensemble de définition de la fonction
2 - Factoriser le numérateur et le dénominateur 
3 - Simplifier les facteurs partagés
4 - Egaliser sur le domaine de définition, la fonction rationnelle et l'expression simplifiée obtenue (on garde le domaine de définition du début)

