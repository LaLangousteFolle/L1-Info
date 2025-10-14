Clef cours = I1

# Algèbre de Boole (Georges)

< {0, 1}, NON, OU, ET >

### NON (l'opposé !)

**Opération Unaire : 1 seul opérande**
 NON 0 = 1
 NON 1 = 0
 Table de vérité de NON

|     | NON |
| :-: | :-: |
|  1  |  0  |
|  0  |  1  |

### OU (+)

*Opération binaire*

|  a  |  b  | a ou b |
| :-: | :-: | :----: |
|  0  |  0  |   0    |
|  0  |  1  |   1    |
|  1  |  0  |   1    |
|  1  |  1  |   1    |


### ET (.)

*Opération binaire*

|  a  |  b  | a et b |
| :-: | :-: | :----: |
|  0  |  0  |   0    |
|  0  |  1  |   0    |
|  1  |  0  |   0    |
|  1  |  1  |   1    |
### Expressions booléenne
$0 + 1 . x + 1 + 0 + \bar y . 0 . 1$ 

Priorité :
- NON
- ET
- OU
*calcul de la gauche vers la droite*
$a + bc + a \bar c$ 


| $a$ | $b$ | $c$ | $\bar c$ | $a . \bar c$ | $b . c$ | $a + b . c$ | $(a + b . c) + a . \bar c$ |
| :-: | :-: | :-: | :------: | :----------: | :-----: | :---------: | :------------------------: |
|  0  |  0  |  0  |    1     |      0       |    0    |      0      |             0              |
|  0  |  0  |  1  |    0     |      0       |    0    |      0      |             0              |
|  0  |  1  |  0  |    1     |      0       |    0    |      0      |             0              |
|  0  |  1  |  1  |    0     |      0       |    1    |      1      |             1              |
|  1  |  0  |  0  |    1     |      1       |    0    |      1      |             1              |
|  1  |  0  |  1  |    0     |      0       |    0    |      1      |             1              |
|  1  |  1  |  0  |    1     |      1       |    0    |      1      |             1              |
|  1  |  1  |  1  |    0     |      0       |    1    |      1      |             1              |

## Propriétés

##### Idempotence :
- OU $a + a = a$
- ET $a . a = a$
##### Involution :
$\bar{a} = a$

##### Commutativité:

- OU $a + b = b + a$
- ET $a . b = b . a$

##### Complémentarité

- $a + \bar{a} = 1$
- $a . \bar{a} = 0$

##### Associativité

- OU $(a + b) + c = a + (b + c) = a + b + c$
- ET $(a . b) . c = a . (b . c) = a . b . c$

##### Distributivité
- de ET sur OU ${a . (b + c) = a . b + a . c}$
- de OU sur ET $a + b . c = (a + b) . (a + c)$

##### Règle de Morgan

- $\overline{(a + b)}$ = $\bar{a}  . \bar{b}$
- $\overline{(a . b)}$ = $\bar{a} + \bar{b}$
- $\overline{(a + b + c)}$ = $\bar{a} + \bar{b} + \bar{c}$
- $\overline{(a . b . c)}$ = $\bar{a} . \bar{b} . \bar{c}$
##### Existence d'un élément neutre
- OU $a + 0 = 0 + a = a$
- ET $a . 1 = 1 . a = a$

##### Existence d'un élément absorbant
OU $a + 1 = 1 + a = 1$
ET $a . 0 = 0 . a = 0$

##### Autres opérateurs
	OU exclusif XOR
	

|  a  |  b  | a XOR b | a NOR b | a NAND b |
| :-: | :-: | :-----: | :-----: | :------: |
|  0  |  0  |    1    |    1    |    1     |
|  0  |  1  |    0    |    0    |    1     |
|  1  |  1  |    O    |    1    |    0     |
|     |     |         |         |          |

|  a  | a + b |
| :-: | :---: |
|  0  |   b   |
|  1  |   1   |

|  a  | a . b |
| :-: | :---: |
|  0  |   0   |
|  1  |  *b*  |
```python
if (cond1 or cond2)
```
```python
if (cond1 and cond2)
```
```python
while 1 <= N and T[i] != 0
```
##### Démonstration

| $a$ | $a + a$ | $a . a$ | $\bar{a}$ | $\bar{\bar{a}}$ |
| :-: | :-----: | :-----: | :-------: | :-------------: |
|  0  |    0    |    0    |     1     |        0        |
|  1  |    1    |    1    |     0     |        1        |



