## Exercice 1:
1) $((((p\lor q)\lor r)\lor s)\lor t)$
2) $((((p \land q)\land r)\land s)\land t)$
3) $(p \Leftrightarrow ((\neg q)\lor r))$
4) $(p \lor(q\Rightarrow(r\land s)))$
5) $(((p \lor q)\Rightarrow r )\Leftrightarrow s)$
6) $(((p\lor(q \land r))\Rightarrow(\neg s))$
7) $((p\Rightarrow(r\land s))\Rightarrow t)$
8) $((p\lor (q\land s)\lor t)$
9) $((p\land q)\Leftrightarrow((\neg r)\lor s))$

## Exercice 2:
1) $\neg q$
2) $u\land \neg a$
3) $e \lor i\Rightarrow i$
4) $(s\land e)\lor(s\land\neg e)$
5) $m \Leftrightarrow v$
6) $l\Rightarrow r$
7) $((t\land f)\Rightarrow b)$
8)  $\neg f$
9) $m\land i$
10) $(p \Rightarrow c)(\neg p\Rightarrow(c \land p))$
## Exercice 3:
*Propriété:*
- proposition: $p\Rightarrow q$
- contraposée: $\neg q \Rightarrow \neg p$
- réciproque: $q\Rightarrow p$
- inverse: $\neg p\Rightarrow\neg q$

1) **Proposition:** Si il pleut je vais faire les courses
	**Contraposée:** Si il je ne vais pas faire les courses, il ne pleut pas
	**Réciproque**: Je vais faire les courses si il pleut
	**Inverse:** Si il ne pleut pas, je ne fais pas faire les courses
2) **Proposition:**  J'ai mon diplôme seulement si je valide mon année ($d\Rightarrow a$)
	**Contraposée:** Si je ne valide pas mon année, je n'ai pas mon diplôme ($\neg a \Rightarrow \neg b$)
	**Réciproque:** Je valide mon année, si j'ai mon diplôme($a\Rightarrow d$)
	**Inverse:** Je n'ai pas mon diplôme si je ne valide pas mon année ($\neg d \Rightarrow \neg a$)
3) **Proposition:** Si le temps est clément et que je suis en forme, alors je vais me balader ($c\land f\Rightarrow b$)
	**Contraposée:** Si je ne vais pas me balader, le temps n'est pas clément ou je ne suis pas en forme ($\neg b\Rightarrow c\lor f$)
	**Réciproque:** Si le temps n'est pas clément ou que je ne suis pas en forme, je ne vais pas me balader ($\neg c\lor\neg f\Rightarrow b$)
	**Inverse:** Si je vais me balader, le temps et clément et je suis en forme ($b\Rightarrow c \land f$)

## Exercice 4:
1) $\neg(a\Rightarrow b)\equiv a\land \neg b$
	$\neg(\neg a\lor b)\equiv (a\lor \neg b)$
2) $a \land b\Rightarrow a \equiv \top$
	$(a\land b) \equiv \neg(a\land b)\lor a\equiv(\neg a\lor\neg b)\equiv \top$
3) $a\Rightarrow a\lor b\equiv \top$
	$(\neg a\lor a)\lor b\equiv \top$
4) $x\Rightarrow (y\lor z)\equiv(x\Rightarrow y)\lor(x\Rightarrow z)$
	$(\neg x \lor(y\lor z) )\equiv(\neg x\lor y)\lor(\neg x\lor z)\equiv (x\Rightarrow y)\lor(x\Rightarrow z)$
5) $(a\land b)\Rightarrow(x\lor y)\equiv (a\Rightarrow x)\lor(b\Rightarrow y)$
	$\neg(a\land b)\lor(x\lor y)\equiv(\neg a\lor\neg b)\lor(x\lor y)\equiv(a\Rightarrow x)\lor(b\Rightarrow y)$

## Exercice 5:
1) dans les cas ou x est different de y.
2) Dans le cas ou x est egal a y.
3) ```c
   bool ProcedureBooleene2()
   {
   int x = randint(10);
   int y = randint(10);
   if (x - y != 0)
	   return(false);
	return(true);
   }
   ```
## Exercice 6:
1) $(a\land\neg b) \lor(\neg a\land b)$ on peut dire que $a \neq b$
2) $(a\lor \neg b)\land(\neg a \lor b)$
3) ```c
   while(a!=b)
   ```

## Exercice 7:
1) $(a\Rightarrow i)$
2) $(\neg a\land b)\Rightarrow o$
3) $(\neg a\land\neg b)\Rightarrow u$
4) ```c
   if(x > y && x != y+1)
   
   elif(x<=y)
   ```

