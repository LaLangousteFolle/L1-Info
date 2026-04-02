import numpy as np

def LU_decomposition(A):
    A = A.astype(float)
    N = A.shape[0]
    L = np.zeros((N, N))
    U = np.eye(N)

    for h in range(N):
        for i in range(h,N):
            somme = 0
            for k in range(h):
                somme += L[i,k] @ U[k,h]
            L[i,h] = A[i,h] - somme
        for j in range(h+1, N):
            somme = 0 
            for k in range(h):
                somme+=L[h,k] @  U[k,j]
            U[h,j] = (A[h,j]- somme)
    return L, U
