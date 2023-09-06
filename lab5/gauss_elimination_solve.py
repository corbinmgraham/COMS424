from math import perm
import numpy as np
from scipy.linalg import lu

def gauss_elimination(x:np.array):

    x = x * 1.0
    rows,cols = x.shape

    # initial
    for i in range(1,rows):
        R1 = x[i][0]/x[0][0]
        x[i] = x[i] - (x[0] * (R1))
    
    # final
    for i in range(rows):
        x[i,:] = x[i,:] / x[i,i]
        for j in range(rows):
            if j == i: break
    x[j,:] = x[j,:] - x[j,i] * x[i,:]

    return x

def gauss_elimination_test(x=np.array([
        [-2, 0, 1, -4],
        [-1, 7, 1, -50],
        [5, -1, 1, -26]
    ])):
    A = x[:,:-1]
    b = x[:,3]
    origin = np.linalg.solve(A,b).reshape(-1,1)
    mine = gauss_elimination( x.copy() )
    print(f"Original:\n{x}\n\nNumpy:\n{origin}\n\nMine:\n{mine}\n(SOL)\n{mine[:,3].reshape(-1,1)}")
    return True

if __name__ == "__main__":
    gauss_elimination_test()