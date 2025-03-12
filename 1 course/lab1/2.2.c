#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(x + 2);  
}

double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    
    return sum * h;
}

int main() {
    double a = 0, b = 1; 
    int n = 1000;    
    
    double result = trapezoidal_rule(a, b, n);
    printf("Результат численного интегрирования методом трапеций: %lf\n", result);
    
    return 0;
}