#include <stdio.h>
#include <math.h>

int main() {
    double a1 = 0.12, b1 = 3.5, c1 = 2.4, x1 = 1.4;
    double a2 = 0.12, b2 = 3.5, c2 = 2.4, x2 = 1.6;
    double a3 = 0.27, b3 = 3.9, c3 = 2.8, x3 = 1.8;
    double h1, h2, h3;

    h1 = -(x1 - a1) / pow(x1 * x1 + a1 * a1, 1.0 / 3.0) - (4 * pow(x1 * x1 + b1 * b1, 3.0 / 4.0)) / (2 + a1 + b1 + pow(x1 - c1, 2.0) / 3.0);
    h2 = -(x2 - a2) / pow(x2 * x2 + a2 * a2, 1.0 / 3.0) - (4 * pow(x2 * x2 + b2 * b2, 3.0 / 4.0)) / (2 + a2 + b2 + pow(x2 - c2, 2.0) / 3.0);
    h3 = -(x3 - a3) / pow(x3 * x3 + a3 * a3, 1.0 / 3.0) - (4 * pow(x3 * x3 + b3 * b3, 3.0 / 4.0)) / (2 + a3 + b3 + pow(x3 - c3, 2.0) / 3.0);

    printf("Значение h(x) при x = 1.4: %lf\n", h1);
    printf("Значение h(x) при x = 1.6: %lf\n", h2);
    printf("Значение h(x) при x = 1.8: %lf\n", h3);

    return 0;
}