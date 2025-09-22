Code cours: Analyse1_I1

[[CM Chapitre 1.pdf]] 
# Intro
##### Entiers naturels $\mathbb{N}$= {0, 1, 2, 3, …}
$\mathbb{N}^*$ = 0 exclus
- Addition
- Multiplication

##### Entiers relatifs $\mathbb{Z}$ = {…, -3, -2, -1, 0, 1, 2, 3, …}
$\mathbb{Z}^*$ = 0 exclus

##### Nombres rationnel $\mathbb{Q}$= résultat de la division du quotient de deux nombres entier relatifs
##### Nombres décimaux $\mathbb{D}$ = nombre fini de décimales 

*cf. [vidéo "nombres rationnels"](https://youtu.be/NCWWVven9Cs)*

## Un nombre rationnel est relationnel si et seulement si il admet une écriture décimale périodique ou finie.

*cf. [[CM Chapitre 1.pdf#page=33|CM Chapitre 1, p.31]]*
	Si $x$ est un nombre réel positif il existe un unique réel positif y tel que $y²$ = $x$. Ce réel est alors appelé la racine carré de $x$ est noté $\sqrt(x)$

Propriétés
	*cf. [démonstration en vidéo](https://youtu.be/83z7Bpz7Fzo)*
#### Ensemble des nombres réel $\mathbb{R}$ (comporte $\mathbb{Q}$, $\mathbb{D}$, $\mathbb{Z}$, $\mathbb{N}$)
$\mathbb{N} \in{\mathbb{Z}}\in{\mathbb{D}}\in{\mathbb{Q}}\in{\mathbb{R}}$ 
Les nombres rationnels ont un développement décimal qui n'est pas périodique.

![[{211EAA98-59B4-4B49-B44B-B623B2909C49}.png]]

$ln$ = logarithme népérien
$e =$ constante d'Euler
$e \approx 2.718$
	*cf. [constante d'Euler](https://fr.wikipedia.org/wiki/Constante_d%27Euler-Mascheroni)*

# Propriétés de $\mathbb{R}$

##### Propriété algébriques = opération multiplication et addition

**ADDITION**
- Commutative = ordre sans importance
- Associative = ordre des opérations sans importance
- élément neutre 0 = aucune altération de calcul
 - $-x$ opposé de $x$

*cf. [vidéo Raisonnement par contraposé](https://youtu.be/B-I5yZd0Wbk?list=PL8CE6188299CCFA23&t=237)*


**MULTIPLICATION**

- Commutative
- Associative
- Elément neutre $= 1$
- $x⁻¹$ inverse de $x$
- Distributive contrairement à l'addition

##### Propriétés de l'ordre
relation de comparaison 
$<$ | $>$ | $\ge$ | $\le$
- réflexive = pour tout $x \in{\mathbb{R}}$ on a $x <= x$
- antisymétrique =  pour tout $x, y \in{\mathbb{R}}$ on a $( x \le$ et $y \le x)\ge x = y$
- transitive = pour tout $x, y, z \in{\mathbb{R}}$ on a $( x\le y$ et $y \le z) \ge x\le z$

##### Prorpiété d'Archimède
$\mathbb{R}$ est archimédien ce:
	"Pour tout réel $x$, il existe un entier naturel $n$ tel aue $n \ge x$"
	autrement $\forall x \in{\mathbb{R}} , \exists{\mathbb{N}}, n > x$ 
Definition:
	On appelle partie entière d’un réel x l’unique entier relatif noté E(x) tel que $E(x) ⩽ x < E(x) + 1$.
Exemples:
	$E(x) = 3 \Leftrightarrow 3 ⩽ x < 4$
	$E(\sqrt{17})$
Remarques:
	Si $x \in{\mathbb{Z}}, E(x) = x$
	Supposons $x \notin{\mathbb{z}}$ Alors $E(-x)=-E(x)+1$
	En effet $E(x)\le x < E(x)+1$
		$-E(x)-1<-x\le-E(x)$
cf. [fonction partie entière]()

## Valeur absolue d'un réel

Propriété:

Le maximum de deux reels a et b est le reel defini par:
$$
max(a,b)=
\begin{cases} 
a\space \text{si}\space a\ge b \\
b\space \text{si}\space b>a\\
\end{cases} 
$$

- $|x| = 0 \Leftrightarrow x = 0$
- $|-x| = |x|$
- $|x-y| = |y-x|$
- $|x+y| \le |x| + |y|$ **(inégalité triangulaire)**
- $\sqrt{x²}=|x|$
- $|xy|=|x||y|$
- si $y\neq0, |\frac{x}{y}| = \frac{|x|}{|y|}$
Remarque
Si $r ⩾ 0$, on a : 
	$|x| ⩽ r \Leftrightarrow −r ⩽ x ⩽ r$ 
	$|x| < r \Leftrightarrow −r < x < r$
# Densité de $\mathbb{Q}$ dans $\mathbb{R}$
Definition:
	Pour tous réels a et b, on appelle segment d’extrémités a et b la partie de $\mathbb{R}$ formée des réels compris entre a et b.

On appelle intervalle de $\mathbb{R}$ toute partie $I$ de $\mathbb{R}$ telle que pour tout a, b dans $I$ et tout $x$ dans $\mathbb{R}$, on a : $a ⩽ x ⩽ b ⇒ x ∈ I$.

Attention, certaines parties de $\mathbb{R}$ ne sont pas des intervalles.
Exemple: $\mathbb{Z}$ n'est pas un intervalle; $\mathbb{Z*}$ n'est pas un intervalle
[liste de tous les intervalles(slide20)]
cf. [introduction aux intervalles](https://www.youtube.com/watch?v=_2bkI2H_vow)

### Densité
$\mathbb{Q}\in\mathbb{R}; \mathbb{Q}\neq \mathbb{R}$
Théorème de densité 
Q est dense dans R, c’est-à-dire que **tout intervalle ouvert non vide de R contient au moins un rationnel.** Autrement dit, si $a<b$ dans $\mathbb{R}$, il existe $r\in \mathbb{Q}$ tel que $a< r< b$
De mˆeme, R\Q est dense dans R, c’est-a-dire : tout intervalle ouvert non vide de R contient au moins un irrationnel.

PREUVE: soit a et b deux réels tesl aue a<b. On montre au'il existe un  nombre rationel r tel que: a <r<b.
On pose $n =  E\frac{1}{b-a} +1$ et $r = \frac{1}{n}(E(na)+1)$
Alors $n\in\mathbb{N}$ et $r \in\mathbb{Q}$ Il reste donc à montrer aue $a<r<b$
Par définition de partie entière:
$n-1 \le \frac{1}{b-a}<n$
$E(na) \le na <E(na)+1$
Comme $\frac{1}{n}> 0$, il vient: $\frac{1}{n}E(na)\le a<\frac{1}{n}(E(na)+1)=r$

### Minorant, majorant, parties bornées
##### Définitions:
- Le réel M est un majorant de A si : $∀a ∈ A, a ⩽ M$
	La partie A est majorée si elle admet au moins un majorant. 
		Remarque: Si M est un majorant de A, tout réel  $M' \ge M$ est encore un majorant de A:

- Le réel m est un minorant de A si : $∀a ∈ A, a ⩾ m$. 
	La partie A est minorée si elle admet au moins un minorant. 
		Remarque: Si m est minorant de A tout réel $m'\leq m$ est encore un minorant de A

- La partie A est bornée si elle est simultanément majorée et minorée càd $\exists m,M\in \mathbb{R}, ∀$
### Maximum minimum
- Le réel M est le plus grand élément, ou le maximum de A si M est un majorant de A et M appartient à A. Quand il existe on le note max $A$ ou max $x$ quand $x\in A$ :

- Le réel m est le plus petit élément, ou le minimum de A si m est un minorant de A et m appartient à A. Quand il existe on le note min $A$ ou min $x$ quand $x∈A$ :
# Propriété de la borne supérieure

