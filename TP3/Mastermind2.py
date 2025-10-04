from random import randint


def toutes_possibilites(n, longueur):
    possibilites = [[]]
    for _ in range(longueur):
        nouvelles = []
        for c in range(len(possibilites)):
            comb = possibilites[c]
            for i in range(1, n + 1):
                L = list(comb)
                L.append(i)
                nouvelles.append(L)
        possibilites = nouvelles
    return possibilites


def Score(H, R):
    if len(H) != len(R):
        exit("Length diff")
    juste = 0
    mal_place = 0
    H_used = [False] * len(H)
    R_used = [False] * len(R)
    for i in range(len(H)):
        if H[i] == R[i]:
            juste += 1
            H_used[i] = True
            R_used[i] = True
    for i in range(len(H)):
        if not H_used[i]:
            for j in range(len(R)):
                if H[i] == R[j] and not R_used[j]:
                    mal_place += 1
                    R_used[j] = True
                    break
    return (juste, mal_place)


def devine(longeur, n):
    essais = 0
    H = toutes_possibilites(n, longeur)
    H1 = []
    Ens_H = []
    Scores_H = []
    found = False
    temp = H[randint(0, len(H) - 1)]

    print(temp)

    while not (found):
        Ens_H.append(temp)
        essais += 1
        juste = int(input("Combien sont bien placés?\n"))
        mp = int(input("Combien sont mal placés?\n"))
        Scores_H.append([juste, mp])

        if juste == longeur:
            found = True
            return f"Trouve en {essais} essais"

        for i in range(len(H)):
            for j in range(len(Ens_H)):
                bon, pb = Score(H[i], Ens_H[j])

                if bon == Scores_H[j][0] and pb == Scores_H[j][1]:
                    H1.append(H[i])
        H = H1
        temp = H[randint(0, len(H) - 1)]
        Ens_H.append(temp)
        print(temp)


print(devine(2, 3))
