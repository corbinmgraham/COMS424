import numpy as np
import matplotlib.pyplot as plt

def gauss_elimination(A:np.array, b:np.array, log=False) -> np.array:

    """
    Gauss elimination (no partial pivoting)
    solve linear system Ax = b
    with a given example
    A size 3 by 3 matrix
    b size 3 by 1 vector
    compared with numpy solve results
    """
    # input A and b
    #A = np.array([[3.0,1,-1],[1.0,-1,1],[2.0,1,1]])
    #b = np.array([1.0,-3,0])
    if log:
        print('A and b are:')
        print(A)
        print(b)
    AA = np.copy(A)
    bb = np.copy(b)
    num_rows = 3
    num_cols = 3
    #main loop
    if log: print('Gaussian Elimination === ')
    for col in range(num_cols-1):
        if log: print('Gauss elemination along col=',col,':')
        for row in range(col+1,num_rows):
            m = (A[row][col]/A[col][col])
            A[row][col:] = A[row][col:] - m*A[col][col:]
            b[row] = b[row] - m*b[col]
        if log:
            print(A)
            print(b)
    #back substituion
    if log: print('Back substitution === ')
    x= np.zeros(3)
    x[num_rows-1] = b[num_rows-1]/A[num_rows-1][num_cols-1]
    for row in range(num_rows-2,-1,-1):
        x[row] = (b[row] - np.dot(A[row][row+1:],x[row+1:]))/A[row][row]
    if log: print(x)
    return x

def gauss_elimination_test(A=np.array, b=np.array, log=False):
    origin = np.linalg.solve(A,b).reshape(-1,1)
    mine = gauss_elimination(A.copy(), b.copy(), log=log).reshape(-1,1)
    print(f"Original:\n{A,b}\n\nNumpy:\n{origin}\n\nMine:\n{mine}\nError: {np.linalg.norm(mine-origin)}\n")
    return True

if __name__ == "__main__":
    A = np.array([[-2,0,1],[-1.0,7,1],[5,-1,1]])
    b = np.array([-4.0,-50,-26])

    x = gauss_elimination(A,b)
    print(x)

    xgrid = np.linspace(-0.1, 0.1, 101)
    f = np.cos(xgrid)
    p = 0
    p = xgrid * x[2] + p
    p = xgrid**2 * x[1] + p
    p = xgrid**3 * x[0] + p
    plt.plot(xgrid,f,'r',xgrid,p,'o')
    plt.show()

    # Testing cubic polynomial

    # p(x) = ax^3 + bx^2 + cx + d
    #   = d + cx + bx^2 + ax^3 = 0
    #   = 
    # f(x) = cos(x)
    #   (-0.1, cos(-0.1)), (-0.2, cos(-0.2)), (0.1, cos(0.1)), (0.2, cos(0.2))

    

