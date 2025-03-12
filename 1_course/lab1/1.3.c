#include <stdio.h>
#include <math.h>

int main() {
    double x, y, u;
    
    printf("Введите значение x: ");
    scanf("%lf", &x);
    
    printf("Введите значение y: ");
    scanf("%lf", &y);
    
    u = (1 + pow(sin(x + y), 2)) / (2 + fabs(x - (2 * pow(x, 2)) / (1 + fabs(sin(x + y)))) );
    
    printf("Значение u(x, y) = %lf\n", u);
    
    return 0;
}