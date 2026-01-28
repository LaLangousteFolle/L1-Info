VAL: Unité Arithmétique et Logique

propriété $\rightarrow$ fonctions $\rightarrow$ table de vérité $\rightarrow$ simplification $\rightarrow$ circuit
## Simplification:
#### Fonctions incomplètes 

|  a  |  b  |  c  | $f$ | $g$ | $g_{1}$ | $g_{2}$ |
| :-: | :-: | :-: | :-: | :-: | ------- | ------- |
|  0  |  0  |  0  |  0  |  1  | 1       | 1       |
|  0  |  0  |  1  |  1  |  0  | 0       | 0       |
|  0  |  1  |  0  |  1  | $x$ | 1       | 0       |
|  0  |  1  |  1  |  1  |  1  | 1       | 1       |
|  1  |  0  |  0  |  0  |  1  | 1       | 1       |
|  1  |  0  |  1  |  1  | $x$ | 0       | 0       |
|  1  |  1  |  0  |  0  |  0  | 0       | 0       |
|  1  |  1  |  1  |  1  | $x$ | 0       | 1       |


*Tableau de Kernaugh*

|      $g$      | $\overline{a}\overline{b}$ | $\overline a b$ | $ab$ | $a \overline b$ |
| :-----------: | :------------------------: | :-------------: | :--: | :-------------: |
| $\overline c$ |             1              |       $x$       |  0   |        1        |
|      $c$      |             0              |        1        | $x$  |       $x$       |
$g_{1} = \overline b. \overline c + \overline a. b$
$g_{2}=\overline b.\overline c+b.c$


![[Pasted image 20260128120537.png]]
 E: nb de 1 = nb de 0
 M: 1 si majorité de 1
    0 si majorité de 0


| $v_{1}$ | $v_{2}$ | $v_{3}$ | $v_{4}$ |  E  |  M  |
| :-----: | :-----: | :-----: | :-----: | :-: | :-: |
|    0    |    0    |    0    |    0    |  0  |  0  |
|    0    |    0    |    0    |    1    |  0  |  0  |
|    0    |    0    |    1    |    0    |  0  |  0  |
|    0    |    0    |    1    |    1    |  1  | $x$ |
|    0    |    1    |    0    |    0    |  0  |  0  |
|    0    |    1    |    0    |    1    |  1  | $x$ |
|    0    |    1    |    1    |    0    |  1  | $x$ |
|    0    |    1    |    1    |    1    |  0  |  1  |
|    1    |    0    |    0    |    0    |  0  |  0  |
|    1    |    0    |    0    |    1    |  1  | $x$ |
|    1    |    0    |    1    |    0    |  1  | $x$ |
|    1    |    0    |    1    |    1    |  0  |  1  |
|    1    |    1    |    0    |    0    |  1  | $x$ |
|    1    |    1    |    0    |    1    |  0  |  1  |
|    1    |    1    |    1    |    0    |  0  |  1  |
|    1    |    1    |    1    |    1    |  0  |  1  |

### Tableau de Karnaugh

|                                             | $\overline{_{v1}}$ $\overline{_{v_{2}}}$ | $\overline{_{v1}}$ $v_2$ | $v_1 v_2$ | $v_{1}\overline{_{v_{2}}}$ |
| :-----------------------------------------: | ---------------------------------------- | ------------------------ | --------- | -------------------------- |
| $\overline{_{v_{3}}}$ $\overline{_{v_{4}}}$ | 0                                        | 0                        | $x$       | 0                          |
|          $\overline{_{v3}} v_{4}$           | 0                                        | $x$                      | 1         | $x$                        |
|                  $v_3 v_4$                  | $x$                                      | 1                        | 1         | 1                          |
|            $v3 \overline{_{v1}}$            | 0                                        | $x$                      | 1         | $x$                        |
$M_1 = v1.v2+v3.v4$
$M_2 = v2.v4+v1.v3$
$M_3 = v1.v4+v2.v3$

## Codage

### Binary Coded Decimal (code BCD)

code seulement les (10) chiffres.


### Code de Aiken

- Podere
- BCDique
- Refelchi
- Auto-complementaire

|     |  2  |  4  |  2  |  1  |
| :-: | :-: | :-: | :-: | :-: |
|  0  |  0  |  0  |  0  |  0  |
|  1  |  0  |  0  |  0  |  1  |
|  2  |  0  |  0  |  1  |  0  |
|  3  |  0  |  0  |  1  |  1  |
|  4  |  0  |  1  |  0  |  0  |
|  5  |  1  |  0  |  1  |  1  |
|  6  |  1  |  1  |  0  |  0  |
|  7  |  1  |  1  |  0  |  1  |
|  8  |  1  |  1  |  1  |  0  |
|  9  |  1  |  1  |  1  |  1  |
## Non-Pondere
### Code excedent 3 (+3)
- BCDique

|     |     |     |     |     |
| :-: | :-: | :-: | :-: | :-: |
|  0  |  0  |  0  |  1  |  1  |
|  1  |  0  |  1  |  0  |  0  |
|  2  |  0  |  1  |  0  |  1  |
|  3  |  0  |  1  |  1  |  0  |
|  4  |  0  |  1  |  1  |  1  |
|  5  |  1  |  0  |  0  |  0  |
|  6  |  1  |  0  |  0  |  1  |
|  7  |  1  |  0  |  1  |  0  |
|  8  |  1  |  0  |  1  |  1  |
|  9  |  1  |  1  |  0  |  0  |

### Code de GRAY
- Commence a 0
- Inverse le bit le plus a droite (qui ne donne pas une valeur commune)

|  0  |  0  |  0  |  1  |
| :-: | :-: | :-: | :-: |
|  0  |  0  |  0  |  0  |
|  0  |  0  |  1  |  1  |
|  0  |  0  |  1  |  0  |
|  0  |  1  |  1  |  0  |
|  0  |  1  |  1  |  1  |
|  0  |  1  |  0  |  0  |
|  0  |  1  |  0  |  1  |
|  1  |  1  |  0  |  0  |
|  1  |  1  |  0  |  1  |
|  1  |  1  |  1  |  1  |
|  1  |  1  |  1  |  0  |
|  1  |  0  |  1  |  0  |
|  1  |  0  |  1  |  1  |
|  1  |  0  |  0  |  1  |
|  1  |  0  |  0  |  0  |
