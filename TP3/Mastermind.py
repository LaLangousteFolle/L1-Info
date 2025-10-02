from random import *
def Init(n, k):
	L = []
	for i in range (n):
		L.append(randint(1, k))
	return(L)

def saisir_proposition():
	L1=list(input("Entrez une liste de chiffres\n"))
	i = 0
	H = []
	for i in range(len(L1)):
		if L1[i] >= '0' and L1[i] <= '9':
			H.append(int(L1[i]))
	return(H)

def Score(H,R):
	juste = 0
	mal_place = 0
	found = False
	if len(H) == len(R):
		for i in range(len(R)):
			for j in range(len(R)):
				if H[i] == R[i]:
					juste += 1
					break
				elif H[j] == R[i]:
					mal_place += 1
					break
	return(juste, mal_place)			

def jouer():
	essais = 10
	n = int(input("Choisissez la taille du la combinaison a trouver\n"))
	k = int(input("Choisissez la valeur maximal des chiffres du jeu (de 1 a 9 max)\n"))
	R = Init(n,k)
	while essais > 0:
		juste, mal_place = Score(saisir_proposition(), R) 
		print(f"{juste} sont bien placé et {mal_place} mal placés")
		if juste == n:
			print("Vous avez gagné")
			essais = 0
		essais -= 1
			
def main():
	play= bool(int(input("Ecrire 1 si vous souhaitez jouer, sinon 0\n")))
	while play:
		jouer()
		play = bool(int(input("Tappez 1 si vous souhaitez rejouer, sinon 0\n")))
	
if __name__ == '__main__':
	main()

