#include <stdio.h>
#include <math.h>

double factorial(int x) {
    if(x <= 1) return 1;
    return x * factorial(x-1);
}

double exp(double x) {
    double e = 2.7182818284509451; // Stored value for e
    double x0 = x;
    double z = x-x0;
    double ex0 = pow(e,x0);
    
    double s = 0.0;
    for(int i = 0; i < 20; i++) {
        s = s + pow(z,i) / factorial(i);
    }
        
    return ex0 * s;
}

double ln(double x) {
    double s = x*10;
    for(int i = 0; i < 100; i++) {
        s = s - 1 + x * exp(-s);
    }
    return s;
}
int main() {
    double x = 2.0;
    double ln_x = ln(x);
    double ln_x_builtin = log(x);
    printf("Mine: %f\nBuiltin: %f\n", ln_x, ln_x_builtin);
    return 0;
}