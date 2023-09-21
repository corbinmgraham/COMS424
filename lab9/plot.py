import sys
import matplotlib.pyplot as plt

def plot_file(filename):
    xs = []
    ys = []
    with open(filename, 'r') as file:
        for line in file:
            line = line.split()
            try:
                x = float(line[0])
                y = float(line[1])
                print(x,y, sep=', ')
                xs.append(x)
                ys.append(y)
            except:
                print(f"Error reading {line}")
    plt.scatter(xs, ys)
    plt.show()


if __name__ == "__main__":
    plot_file(sys.argv[1])
