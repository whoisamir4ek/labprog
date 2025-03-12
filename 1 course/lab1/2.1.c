#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main() {
    double r1 = 227.9, r2 = 149.6; // Радиусы орбит Марса и Земли в миллионах км
    double T1 = 687.0, T2 = 365.25; // Периоды обращения Марса и Земли в годах
    double w1 = 2 * PI / T1, w2 = 2 * PI / T2; // Угловые скорости
    double x, y;
    
    // Пройдем по времени от 0 до 10 лет с шагом 1 год
    for (int t = 0; t <= 10; t++) {
        x = r1 * cos(w1 * t) - r2 * cos(w2 * t);
        y = r1 * sin(w1 * t) - r2 * sin(w2 * t);
        
        printf("Время t = %d лет: координаты Марса (x, y) = (%.2lf, %.2lf)\n", t, x, y);
    }

    return 0;
}