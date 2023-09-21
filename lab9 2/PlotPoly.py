def PlotPoly():
    # First , figure out how many floats there are
    with open('poly.data', 'r') as fid:
        NumPts = 0;
        while True:
            line = fid.readline()
            if not line: break
            NumPts = NumPts+1

    import numpy as np
    import string as str
    import matplotlib.pyplot as plt

    # Second , read -in all the floats
    x = np.zeros(NumPts , dtype = float )
    y = np.zeros(NumPts , dtype = float )
    with open('poly.data', 'r') as fid:
        for k in range(0, NumPts ):
            linestring = fid.readline()
            # linelist = str.split( linestring )
            linelist = linestring .split()
            x[k] = float( linelist [0])
            y[k] = float( linelist [1])

    # Third , plot the result
    plt.rc("font", size=16); plt.figure(1)
    plt.plot(x, y, linestyle ="dashed", linewidth=2, marker="o",
            color="red", markersize=12)
    plt.xlim( -1.0 ,1.0); plt.xticks([ -1.0 , -0.5 ,0.0 ,0.5 ,1.0])
    ax = plt.gca(); ax.grid(True)
    plt.xlabel("x-axis",size =20); plt.ylabel("y-axis",size =20)
    plt.title("Polynomial Plot",size =20)
    plt.savefig('chebyshev.png',dpi =400 , bbox_inches ='tight')
    plt.show()

if __name__ == "__main__":
    print("Plotting points")
    PlotPoly()