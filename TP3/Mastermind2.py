from random import *
def toutes_possibilites(n, longueur):
	possibilites = [[]]
	for _ in range(longueur):
		nouvelles = []
		for c in range(len(possibilites)):
			comb= possibilites[c]
				for i in range(1, n+1):
					L=list(comb)
					L.append(i)
					nouvelles.append(L)
			possibilites = nouvelles
	return possibilites

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


def devine(longeur, n):
	essais = 0 
	H = toutes_possibilites(n, longeur)
	Ens_H = []
	Scores_H =[]
	found = False
	Ens_H.append(H[randint(0, len(H-1))])
	while not(found):
		temp =Ens_H[randint(0, len(H-1))])
		print(temp)
		Ens_H.append(temp)
		essais += 1
		juste = int(input("Combien sont bien placés?")
		mp = int(input("Combien sont mal placés?")
		Scores_H.append([juste, mp])
		if juste == longeur:
			found = True
			print("Trouve")
		for i in range(len(H)):
			bon, pb= Score(temp,H[i])
			if bon == juste and pb == mp:
				Ens_H.append(H[i])
				 
