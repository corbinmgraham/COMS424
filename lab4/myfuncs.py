def factorial(x):
    if x < 2:
        return 1
    return (x * factorial(x-1))
def sqrt(x):
    s = 1.0
    for k in range(100):
        s = 0.5 * (s + x/s)
    return s

def exp(x):
    import math
    e = 2.7182818284509451 # Stored value for e
    x0 = int(round(x))
    z = x-x0
    ex0 = e**x0
    
    s = 0.0
    for k in range(20):
        s = s + z**k / math.factorial(k)
    return ex0 * s

def ln(x):
    s = x*10
    for k in range(100):
        s = s - 1 + x * exp(-s)
    return s

if __name__ == "__main__":
    # Factorial Test
    import math
    print(f"Factorial\n Num | {'Math':<15} | {'Mine':<15} | Equal")
    for i in range(20):
        mm = math.factorial(i)
        mn = factorial(i)
        print(f"{i:4} | {mm:>15d} | {mn:<15d} | {(mm == mn)}")

    # Factorial Test
    print(f"Square Root\n Num | {'Math':<15} | {'Mine':<15} | Equal")
    for i in range(18):
        mm = math.sqrt(i)
        mn = sqrt(i)
        print(f"{i:4} | {mm:.15} | {mn:.15} | {(mm == mn)}")