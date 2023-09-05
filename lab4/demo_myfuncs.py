import myfuncs as mf
import math
import numpy as np

if __name__ == "__main__":
    # Factorial Test
    print(f"Factorial\n Num | {'Math':<15} | {'Mine':<15} | Equal")
    for i in range(20):
        mm = math.factorial(i)
        mn = mf.factorial(i)
        print(f"{i:4} | {mm:>15d} | {mn:<15d} | {(mm == mn)}")

    # Square Root Test
    print(f"Square Root\n Num | {'Math':<15} | {'Mine':<15} | Equal | Difference")
    for i in range(18):
        mm = math.sqrt(i)
        mn = mf.sqrt(i)
        diff = (abs((mm - mn)) / ((mm + mn) / 2)) * 100
        print(f"{i:4} | {mm:.13f} | {mn:.13f} | {(mm == mn)} | {diff}")

    # Exp Test
    print(f"Exp\n Num | {'Math':<15} | {'Mine':<15} | Equal | Difference")
    for i in range(18):
        mm = math.exp(i)
        mn = mf.exp(i)
        diff = (abs((mm - mn)) / ((mm + mn) / 2)) * 100
        print(f"{i:4} | {mm:.13f} | {mn:.13f} | {(mm == mn)} | {diff}")

    # Ln Test
    print(f"Ln\n Num | {'Numpy':<15} | {'Mine':<15} | Equal | Difference")
    for i in range(18):
        mm = np.log(i)
        mn = mf.ln(i)
        diff = (abs((mm - mn)) / ((mm + mn) / 2)) * 100
        print(f"{i:4} | {mm:.13f} | {mn:.13f} | {(mm == mn)} | {diff}")