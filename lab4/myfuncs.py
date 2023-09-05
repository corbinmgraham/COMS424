def factorial(x,log=False):
    if log == True:
        print(f"{x}!")
    if x < 2:
        if log == True:
            print("The input is less nonpositive")
        return 1
    return (x * factorial((x-1), log))

def sqrt(x):
    s = 1.0
    for k in range(100):
        s = 0.5 * (s + x/s)
    return s

def exp(x,log=False,kmax=100,tol=1.0e-14):
    e_const = 2.7182818284509451 # Stored value for e
    x0 = int(round(x))
    z = 1.0*(x-x0)
    ex0 = e_const**x0
    
    s = 0.0
    for k in range(kmax):
        sold = z**k / factorial(k)
        s = s + sold

        if log == True:
            print(f"S: {s} | New: {sold}")
        if (abs(sold) < tol):
            break
    return ex0 * s

def ln(x,log=False,kmax=100,tol=1.0e-14):
    s = x*10.0
    for k in range(kmax):
        s = s - 1 + x * exp(-s)
        if (log == True):
            print(f"S: {s}")
        if (s < tol):
            break
    return s

def sqrt_newton(x, log=False, initial_guess=1.0, kmax=100, tol=1.0e-14):
    """
    Square Root Function using Newton's Method
    """

    # Convert x to float
    x = 1.0 * x

    if x <= 0:
        print("Input cannot be negative or 0")

    s = initial_guess
    for k in range(kmax):
        if log == True:
            print(f"S: {s} | K: {k}")
        
        sold = s
        s = 0.5 * (s + x/s)
        if (abs((s-sold) / x) < tol):
            break

    if log == True:
        print(f"Final Result: {s}")
    return s