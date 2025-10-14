
| a   | b   | $\overline {a+b}$ | $\overline {b+a}$ |
| --- | --- | ----------------- | ----------------- |
| 0   | 0   | 1                 | 1                 |
| 0   | 1   | 0                 | 0                 |
| 1   | 0   | 0                 | 0                 |
| 1   | 1   | 0                 | 0                 |
Nor est donc commutatif 
$\forall a,b \in \{0,1\} \space \overline {a+b} = \overline {b+a}$  

#### Associativité 
$\forall a,b \in \{0,1\}$ 
$\overline { \overline{(a+b)}+c} = \overline {a+ \overline {(b+c)}}$ ? 


| a   | b   | c   | $\overline {a+b}$ | $\overline {\overline {a+b}+c}$ | $\overline {a+b}$ | $\overline {\overline {b+c}+a}$ |
| --- | --- | --- | ----------------- | ------------------------------- | ----------------- | ------------------------------- |
| 0   | 0   | 0   | 1                 | 0                               | 1                 | 0                               |
| 0   | 0   | 1   | 1                 | 0                               | 0                 | 1                               |

$\exists a,b \in \{0,1\}$ tel que $\overline {\overline {a+b}+c} \neq$ $\overline {a+\overline {b+c}}$
Donc pas associatif 

#### Implication : 

| $a$ | $b$ | $a \implies b$ | $b \implies a$ |
| --- | --- | -------------- | -------------- |
| 0   | 0   | 1              | 1              |
| 0   | 1   | 1              | 0              |
| 1   | 0   | 0              | 1              |
| 1   | 1   | 1              | 1              |
#### Opérateur/ groupe d'opérateurs complet

$\{ou \space et \space non \}$  est un groupe complet
{et, non} est il complet ? Oui
$\forall a,b \in \{0,1\}$ a et b = a et b
$\forall a \in \{0,1\}$ $\bar a = \bar a$
$\forall a,b \in \{0,1\}$ $a + b = \overline{\overline{a+b}} = \overline{\overline {a} \space et \space \overline {b}}$   

#### Fonctions logiques ou booléennes :

$f_1(x,y,z) = x \space et \space \bar y + x \space et \space z + \bar z \space et \space (z \space et  \space \bar y +x)$  


| $x$ | $y$ | $z$ | $\bar y$ | $x \space . \space \bar y$ | $x . z$ | $\bar z$ | $z . \bar y$ | $z \bar y + x$ | $\bar z . (z \bar y + x)$ | $f_1$ |
| --- | --- | --- | -------- | -------------------------- | ------- | -------- | ------------ | -------------- | ------------------------- | ----- |
| 0   | 0   | 0   | 1        | 0                          | 0       | 1        | 0            | 0              | 0                         | 0     |
| 0   | 0   | 1   | 1        | 0                          | 0       | 0        | 1            | 1              | 0                         | 0     |
| 0   | 1   | 0   | 0        | 0                          | 0       | 1        | 0            | 0              | 0                         | 0     |
| 0   | 1   | 1   | 0        | 0                          | 0       | 0        | 0            | 0              | 0                         | 0     |
| 1   | 0   | 0   | 1        | 1                          | 1       | 1        | 0            | 1              | 1                         | 1     |
| 1   | 0   | 1   | 1        | 1                          | 1       | 0        | 1            | 1              | 0                         | 1     |
| 1   | 1   | 0   | 0        | 0                          | 0       | 1        | 0            | 1              | 1                         | 1     |
| 1   | 1   | 1   | 0        | 0                          | 0       | 0        | 0            | 1              | 0                         | 1     |
####  Egalité de fonctions

$f(a,b,c) = \bar a \bar c + \bar b \bar c + ac$ 
$g(a,b,c) = \bar a b \bar c + a \bar b + ac + \bar a \bar b \bar c$ 


| $a$ | $b$ | $c$ | $f$ | $g$ |
| --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 1   | 1   |
| 0   | 0   | 1   | 0   | 0   |
| 0   | 1   | 0   | 1   | 1   |
| 0   | 1   | 1   | 0   | 0   |
| 1   | 0   | 0   | 1   | 1   |
| 1   | 0   | 1   | 1   | 1   |
| 1   | 1   | 0   | 0   | 0   |
| 1   | 1   | 1   | 1   | 1   |
$f = g$ 

#### Normalisation de l'écriture d'une fonction

Formule normale (Disjonctive ou Conjonctive)
	Les opérateurs  (NON) ne portent que sur des variables
	Les variables sont regroupées en termes en (ET pour la forme disjonctive et OU pour la forme conjonctive)
	Les termes sont regroupée avec des (OU pour la forme disjonctive et ET pour la forme conjonctive) 

$f_2(a,b,c) = (a + \bar b + \bar c) . (a + \bar) . (\bar a + \bar b +c)$ 