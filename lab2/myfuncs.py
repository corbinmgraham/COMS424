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