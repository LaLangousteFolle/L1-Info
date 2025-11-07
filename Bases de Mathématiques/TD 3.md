[[Drawing 2025-11-05 11.36.51.excalidraw]]
Une relation d'equivalence est une relation $R$ sur $E$ telle que :
- reflexive $\forall x \in E, xR x$
- symetrique $\forall x,y\in E,xRx \Rightarrow yRx$
- transitive $\forall x,y,z\in E,\space _{xRz}^{xRx}\bigg\}\Rightarrow xRz$
<u>Rappel :</u> 
La classe d'equivalence de $x \in E$ pour $R_{2}$
est  $cl(x)=\{y\in E | yR_{2}x\}$
On a $cl(c)=\{y \in E | y R_{2}c\}=\{c\}$
$cl(a)=cl(b)=cl(d)$


### Ex 7
On a $R = (\mathbb Z, \mathbb Z, \Gamma)$ avec $\Gamma = \{(x,y)\in \mathbb Z^2|x+y \space\text{pair}\}$
$(\mathbb Z^2=\mathbb Z \times Z)$
<u>Reflexivite</u>
soit $x\in \mathbb Z$
$x+y = 2x$ est un entier pair
donc $xRx$ la relation est *réflexive*.

<u>Symetrie</u>
soit $x,y \in \mathbb Z$ que $xRy$
Alors $y+x = x+ y$ est pair par hypothèse
Donc $yRx$
La relation est *symétrique*

<u>Transitivité</u>
Soit $x,y,z \in \mathbb Z$ tels que $xRy$ et $yRz$
Alors $x+y$ et $y+z$ sont paires
Donc $x$ et $y$ ont même parité $y$ et $z$ on même parité.
ce qui entraîne $x$ et $z$ ont même parité et $x+z$ est pair.

Autre manière
si $x+y$ est pari, $x-y$  aussi, et on a:
$x+y=(x-y)+(x+z)$ est pair par somme d'entiers pairs.

Par conséquent, $xRz$
la relation est bien *transitive*

Conclusion:
C'est une relation équivalence.


2) Soit $x\in \mathbb Z$ on a :
$cl(x) = \{y\in \mathbb Z|yRx\}$
	$=\{y\in \mathbb Z | x+y \space \text{pair}\}$
	$cl(0)= \{y\in \mathbb Z | y \space \text{pair}\}$ ensemble des entiers pairs
	$=cl(x)$ pour tout $x$ entier pair.
	$cl(1) = \{z|in \mathbb Z |y+1\space \text{pair}\}$ensemble des entier impairs
	$=cl(x)$ pour tout $x$ entier impair.
$R$ a 2 classes équivalence : $cl(0)$ ensemble des entiers pairs et $cl(1)$ ensemble des entiers impairs.
	