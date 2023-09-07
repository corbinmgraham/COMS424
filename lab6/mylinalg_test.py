import numpy as np
import mylinalg as my

if __name__ == "__main__":
    x=np.array([
        [-2, 0, 1, -4],
        [-1, 7, 1, -50],
        [5, -1, 1, -26]
    ])
    A = x[:,:-1]
    b = x[:,3]
    my.gauss_elimination_test(A,b)