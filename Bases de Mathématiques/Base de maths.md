1) 

| P   | Q   | P et Q | non(P et Q) | non P | non Q | non P ou non Q |
| --- | --- | ------ | ----------- | ----- | ----- | -------------- |
| V   | V   | V      | F           | F     | F     | F              |
| V   | F   | F      | V           | F     | V     | V              |
| F   | V   | F      | V           | V     | F     | V              |
| F   | F   | F      | V           | V     | V     | V              |
Les tables non(P et Q ) et (non P ou Q) sont identiques, donc les assertions sont equivalentes non(P et Q) $\Leftrightarrow$ (non P ou non Q).

2) $(P \Rightarrow Q) et (Q \Rightarrow R) et (P \Rightarrow R)$

|  P  |  Q  |  R  | $P \Rightarrow Q$ | $Q \Rightarrow R$ | $(P \Rightarrow Q) et (Q \Rightarrow R)$ | $P \Rightarrow R$ | $((P\Rightarrow Q )et(Q\Rightarrow R))\Rightarrow (P\Rightarrow R)$ |
| :-: | :-: | :-: | :---------------: | :---------------: | :--------------------------------------: | :---------------: | :-----------------------------------------------------------------: |
|  V  |  V  |  V  |         V         |         V         |                    V                     |         V         |                                  V                                  |
|  V  |  V  |  F  |         V         |         F         |                    F                     |         V         |                                  V                                  |
|  V  |  F  |  V  |         F         |         V         |                    F                     |         F         |                                  V                                  |
|  V  |  F  |  F  |         F         |         V         |                    F                     |         F         |                                  V                                  |
|  F  |  V  |  V  |         V         |         V         |                    V                     |         V         |                                  V                                  |
|  F  |  V  |  F  |         V         |         F         |                    F                     |         V         |                                  V                                  |
|  F  |  F  |  V  |         V         |         V         |                    V                     |         V         |                                  V                                  |
|  F  |  F  |  F  |         V         |         V         |                    V                     |         V         |                                  V                                  |
La derniere colone ne contient que des vrais, donc l'implication est vraie.

3) 

| P   | Q   | $P\Rightarrow Q$ | $non(P\Rightarrow Q)$ | non Q | P et non Q |
| --- | --- | ---------------- | --------------------- | ----- | ---------- |
| V   | V   | V                | F                     | F     | F          |
| V   | F   | F                | V                     | V     | V          |
| F   | V   | V                | F                     | F     | F          |
| F   | F   | V                | F                     | V     | F          |
Les tqbles de non(P$\Rightarrow$Q) et de (P et non Q) sont identiques, donc les 2 assertions sont equivqlentes: non(P$\Rightarrow$Q)$\Leftrightarrow$ (P et non Q) est vraie.

## Exercice 2

1) non(non(P) ou Q) $\Leftrightarrow$ (P et non Q)
2)  non(P ou (Q ou R)) $\Leftrightarrow$ non P et(non Q et non R)
3) non(P et (Q ou R))  $\Leftrightarrow$ non P ou (non Q et non R)
4) non((P et Q)$\Rightarrow$ (R $\Rightarrow$ S)) $\Leftrightarrow$ non((P et Q) $\Rightarrow$ (R $\Rightarrow$ S)) $\Leftrightarrow$ ((P et Q) et non (R$\Rightarrow$ S)) $\Leftrightarrow$ ((P et Q) et (R et non S)) $\Leftrightarrow$ (P et Q et R et non S)

==Rappel de cours==
non(A $\Rightarrow$ B) $\Leftrightarrow$ (A et non B)
##### Remarque: Par associativite du "ou" et du "et"
(P ou (Q ou R)) $\Leftrightarrow$ ((Pou Q) ou R)
$\Leftrightarrow$ (P ou Q ou R)
pareil en remplacant "ou" par "et"

## Exercice 3

1) 
Sachant que P $\Leftrightarrow$ Q, P et Q ont meme table d'ou

| P   | Q   | non Q | non P |
| --- | --- | ----- | ----- |
| V   | V   | F     | F     |
| F   | F   | V     | V     |
Les deux tables non P et non Q sont identiques, donc non P $\Leftrightarrow$ non Q est vraie

2) Sachant que P et Q sont equivalentes

| P   | Q   | R   | P $\Rightarrow$ R | Q $\Rightarrow$ R |
| --- | --- | --- | ----------------- | ----------------- |
| V   | V   | V   | V                 | V                 |
| V   | V   | F   | F                 | F                 |
| F   | F   | V   | V                 | V                 |
| F   | F   | F   | V                 | V                 |
Les deux tables P $\Rightarrow$ R et Q $\Rightarrow$ R sont identiques, donc les 2 assertions sont equivalentes (P $\Rightarrow$ R) $\Leftrightarrow$ (Q $\Rightarrow$ R) est vraie.

3) Sachant que P et Q sont equivalentes

| P   | Q   | R   | R $\Rightarrow$ P | R $\Rightarrow$ Q |
| --- | --- | --- | ----------------- | ----------------- |
| V   | V   | V   | V                 | V                 |
| V   | V   | F   | V                 | V                 |
| F   | F   | V   | F                 | F                 |
| F   | F   | F   | V                 | V                 |
Les deux tables R $\Rightarrow$ P et R $\Rightarrow$ Q sont identiques, donc les 2 assertions sont equivalentes (R $\Rightarrow$ P) $\Leftrightarrow$ (R $\Rightarrow$ Q) est vraie.

4) Sachant que P et Q sont equivalentes


| P   | Q   | R   | (P et R) | (Q et R) |
| --- | --- | --- | -------- | -------- |
| V   | V   | V   | V        | V        |
| V   | V   | F   | F        | F        |
| F   | F   | V   | F        | F        |
| F   | F   | F   | F        | F        |
Les deux tables (P et R) et (Q et R) sont identiques, donc les 2 assertions sont equivalentes (P et R) $\Leftrightarrow$ (Q et R) est vraie.



## Exercice 4
1) ((P et Q)$\Rightarrow$P)$\Leftrightarrow$ (non(P et Q)ou P)$\Leftrightarrow$((non P ou non Q)ou P)$\Leftrightarrow$ ((non P ou P)ou non Q)
*par associativite et commutativite*

2) (P $\Rightarrow$(Q$\Rightarrow$R))$\Leftrightarrow$((P et Q)$\Rightarrow$R) $\Leftrightarrow$ (non P ou (Q $\Rightarrow$ R))$\Leftrightarrow$ (non P ou (non Q ou R))$\Leftrightarrow$ ((non P ou non Q)ou R)
*par associativite du "ou"*
$\Leftrightarrow$ (non(P et Q) ou R) $\Leftrightarrow$((P et Q)$\Rightarrow$ R)

3) En utilisant la question precedentem on a vu que (P $\Rightarrow$(Q$\Rightarrow$R))$\Leftrightarrow$(non P ou ( Q $\Rightarrow$ R)) et (non P ou (Q$\Rightarrow$R))$\Leftrightarrow$((P et Q)$\Rightarrow$)
## Exercice 5
1) $\forall n \in\mathbb{N}, -n < 0$    non($\forall n \in\mathbb{N}, -n < 0$) $\Leftrightarrow \exists n\in\mathbb N,-n\ge 0$ $\Leftrightarrow$ "il existe un entier naturel n dont l'oppose est positif"
2) $\exists n \in\mathbb Z$