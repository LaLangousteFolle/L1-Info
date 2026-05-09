import numpy as np
import time

A1 = np.array([[0, 1, -1],
               [-2, 4, -1],
               [-2, 5, -4]], dtype=float)
B1 = np.array([3, 1, -2], dtype=float)

X = np.linalg.solve(A1, B1)
print(X)

A2 = np.array([[9, -6, 10],
               [-5, 2, -5],
               [-12, 6, -13]], dtype=float)
B2 = np.array([[9, -6, 10],
               [-5, 2, -5],
               [-12, 6, -13]], dtype=float)

def produit_scalaire(l1, l2):
    res = 0
    for i in range(len(l1)):
        res += l1[i] * l2[i]
    return res

def produit_mat(A, B):
    n = A.shape[0]
    m = B.shape[1]
    C = np.zeros((n, m))
    for i in range(n):
        for j in range(m):
            C[i][j] = produit_scalaire(A[i], B.T[j])
    return C

print(produit_mat(A2, B2))
print(np.dot(A2, B2))

n = 300
Ag = np.random.rand(n, n)
Bg = np.random.rand(n, n)

t1 = time.time()
produit_mat(Ag, Bg)
t2 = time.time()
print("produit_mat:", t2 - t1)

t3 = time.time()
np.dot(Ag, Bg)
t4 = time.time()
print("np.dot:", t4 - t3)

notes = np.array([
    [12.5, 14.0,  8.5, 11.0],
    [ 9.0, 13.5, 17.0,  6.5],
    [15.0,  7.0, 12.0, 18.0],
    [11.5, 14.0, 10.5, 13.0],
    [ 8.0, 12.0, 15.0,  9.5],
    [16.0, 11.0,  9.0, 14.5]
], dtype=float)

def stats(A):
    moy_globale = np.mean(A)
    std_globale = np.std(A)
    moy_par_matiere = np.mean(A, axis=0)
    std_par_matiere = np.std(A, axis=0)
    return moy_globale, std_globale, moy_par_matiere, std_par_matiere

print(stats(notes))

def indices_sup(A, seuil):
    moyennes = np.mean(A, axis=1)
    return np.where(moyennes > seuil)[0]

print(indices_sup(notes, 12))

A4 = np.random.rand(5, 5)
A4_inv = np.linalg.inv(A4)
print(np.dot(A4, A4_inv))

def chercher_pivot(M, l, c):
    pivot = l
    for k in range(l, M.shape[0]):
        if abs(M[k][c]) > abs(M[pivot][c]):
            pivot = k
    return pivot

def echange_lignes(M, i, j):
    M[i], M[j] = M[j].copy(), M[i].copy()

def transvection(M, i, j, c):
    M[j] = M[i, c] * M[j] - M[j, c] * M[i]

def echelonner(A):
    n1 = A.shape[0]
    n2 = A.shape[1]
    l = 0
    for c in range(n2):
        if l == (n1 - 1):
            break
        pivot = chercher_pivot(A, l, c)
        if A[pivot][c] == 0:
            continue
        if pivot > l:
            echange_lignes(A, l, pivot)
        for k in range(l + 1, n1):
            transvection(A, l, k, c)
        l = l + 1

A_test = np.array([[1, 2, 1, 1], [2, 4, 2, 2], [3, 6, 3, 4]], dtype=float)
echelonner(A_test)
print(A_test)

B_test = np.array([[1, 2, 1, 3, 3], [2, 4, 0, 4, 4], [1, 2, 3, 5, 5], [2, 4, 0, 4, 7]], dtype=float)
echelonner(B_test)
print(B_test)

def echelonner_rang(A):
    n1 = A.shape[0]
    n2 = A.shape[1]
    l = 0
    rang = 0
    for c in range(n2):
        if l == (n1 - 1):
            break
        pivot = chercher_pivot(A, l, c)
        if A[pivot][c] == 0:
            continue
        if pivot > l:
            echange_lignes(A, l, pivot)
        for k in range(l + 1, n1):
            transvection(A, l, k, c)
        rang += 1
        l = l + 1
    return rang

A_test2 = np.array([[1, 2, 1, 1], [2, 4, 2, 2], [3, 6, 3, 4]], dtype=float)
print(echelonner_rang(A_test2))

B_test2 = np.array([[1, 2, 1, 3, 3], [2, 4, 0, 4, 4], [1, 2, 3, 5, 5], [2, 4, 0, 4, 7]], dtype=float)
print(echelonner_rang(B_test2))

def echelonner_famille_libre(A):
    A_orig = A.copy()
    n1 = A.shape[0]
    n2 = A.shape[1]
    l = 0
    pivot_cols = []
    for c in range(n2):
        if l == (n1 - 1):
            break
        pivot = chercher_pivot(A, l, c)
        if A[pivot][c] == 0:
            continue
        if pivot > l:
            echange_lignes(A, l, pivot)
        for k in range(l + 1, n1):
            transvection(A, l, k, c)
        pivot_cols.append(l)
        l = l + 1
    return A_orig[:, pivot_cols]

A_test3 = np.array([[1, 2, 1, 1], [2, 4, 2, 2], [3, 6, 3, 4]], dtype=float)
print(echelonner_famille_libre(A_test3))

B_test3 = np.array([[1, 2, 1, 3, 3], [2, 4, 0, 4, 4], [1, 2, 3, 5, 5], [2, 4, 0, 4, 7]], dtype=float)
print(echelonner_famille_libre(B_test3))
