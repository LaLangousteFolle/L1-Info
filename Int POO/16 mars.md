# Recursivite
**se** repeter

```c
int fact(int N)
{
if (N<=1) return 1;
	return N*fact(N-1);
}
```
# Recursivite croisee (ou mutuelle)

```c
bool Pair(int N);

bool Impair(int N)
{
	if (N = 0) return false;
		return Pair(N-1);
}
bool Pair(int N)
{
	if (N == 0) return true;
		return Impair(N-1);
}
```
## Structure Chainees Arbres

### Implementation des arbres binaires
```c++
class Noeud
{
	int Info;
	Noeud *fg, *fd;
	public:
	.
	.
	.
	
};
class Arbre
{
	Noeud *racine;
	public:
	.
	.
	.
};

Arbre::Arbre(void)
{
	racine nullptr;
}
Arbre::Arbre(Noeud *N)
{
	racine = N;
}
Noeud::Noeud(int i, Noeud *G, Noeud *D)
{
	info = I
	fg = G;
	fd = D;
}
	Arbre A (newNoeud(12, newNoeud(7, newNoeud(16,nullptr, nullptr)newNoeud(4, nullptr, nullptr))newNoeud(2, nullptr, nullptr)))
```
