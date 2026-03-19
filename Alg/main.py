import numpy as np 
import time

A = np.ones((3,3))
A = A * 3
A += 2 * np.eye(3)
print(A)
print()

B = np.eye(4)
B[1: ,0] = 1

print(B)
print()

C = np.arange(1,17,1)
C = np.reshape(C, (4,4))

print()
print(C)

D = np.arange(1,5,1)
D = np.tile(D,(4,1))

print(D)
print()

# Exercice 2:

B = np.array([[1,1,0],[1,-1,1],[1,0,1]])
print(B)

print(np.linalg.matrix_rank(B))

B_inv = np.linalg.inv

print(B)


X = np.array([[1],[3],[-2]])

Y = np.linalg.solve(B, X)

print(Y)


# Exercice 3


X = np.array([[1,1,1],[1,-2,1],[2,-1,1]])
Y =  np.array([[1],[0],[2]])

Z = np.linalg.solve(X,Y)

print(Z)

X = np.array([[3,1,-1],[1,1,1],[1,-2,2]])
Y = np.array([[3],[3],[1]])
Z = np.linalg.solve(X,Y)
X = np.array([[1,1,1],[1,-2,1],[2,-1,1]])
Y = np.linalg.solve(X,Z)

print(Y)
print()

# Exercice 4

KYS = np.arange(1,11,1).reshape((10, 1))
print(KYS)
ZIG = np.ones((1,10))
print(ZIG)

JACKY = KYS @ ZIG

print(JACKY)



#Exercice 5

SOL = np.arange(1,1000001,1)
print(np.sum(SOL))
sum = 0
for i in range(1000001):
    sum = sum + i 
print(sum)


#exercice 6

def zawg(L1, L2, L3):
    if L1.shape == L2.shape and L2.shape == L3.shape and L1.shape == L3.shape:
        M  = np.zeros((L1.shape[0] * 3, L1.shape[1]))
        j = 0
    else:
        return
    for i in range(L1.shape[0]):
        M[j] = L1[i]
        j += 1
        M[j] = L2[i]
        j += 1
        M[j] = L3[i]
        j+=1
    print(M)

A =  np.eye(3)
B = np.eye(3)
C = np.eye(3)

zawg(A,B,C)


def remplacement(A):
    B = a.copy()

