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


def Score(hypothese, reponse):
    """Version corrigée du score Mastermind"""
    if len(hypothese) != len(reponse):
        return (0, 0)

    bien_places = 0
    mal_places = 0

    # Compter les bien placés
    for i in range(len(hypothese)):
        if hypothese[i] == reponse[i]:
            bien_places += 1

    # Compter les mal placés (plus complexe sans dictionnaires)
    h_utilise = [False] * len(hypothese)
    r_utilise = [False] * len(reponse)

    # Marquer les bien placés comme utilisés
    for i in range(len(hypothese)):
        if hypothese[i] == reponse[i]:
            h_utilise[i] = True
            r_utilise[i] = True

    # Chercher les mal placés
    for i in range(len(hypothese)):
        if not h_utilise[i]:  # Si pas bien placé
            for j in range(len(reponse)):
                if not r_utilise[j] and hypothese[i] == reponse[j]:
                    mal_places += 1
                    r_utilise[j] = True
                    break

    return (bien_places, mal_places)


def devine(longueur, n):
    possibilites = toutes_possibilites(n, longueur)
    essais = 0

    print("Je vais deviner votre combinaison")

    while len(possibilites) > 0:
        # Choisir une possibilité au hasard
        choix = possibilites[randint(0, len(possibilites) - 1)]
        print("Ma proposition:", choix)

        essais += 1
        bien_places = int(input("Combien sont bien placés? "))
        mal_places = int(input("Combien sont mal placés? "))

        if bien_places == longueur:
            print("Trouvé en", essais, "essais!")
            return essais

        # Filtrer les possibilités
        nouvelles_possibilites = []
        for poss in possibilites:
            score_test = Score(choix, poss)
            if score_test[0] == bien_places and score_test[1] == mal_places:
                nouvelles_possibilites.append(poss)

        possibilites = nouvelles_possibilites
        print("Il reste", len(possibilites), "possibilités")

    print("Aucune solution - vérifiez vos réponses")
    return -1


# Test
resultat = devine(4, 6)
