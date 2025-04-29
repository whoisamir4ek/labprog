#include <stdio.h>
#include <math.h>
#include <string.h>

// Структура для 3D-вектора
typedef struct {
    char name[50];  // Имя вектора
    double x, y, z; // Координаты
} Vector3D;

// Скалярное произведение векторов
double dot_product(Vector3D a, Vector3D b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Векторное произведение векторов
Vector3D cross_product(Vector3D a, Vector3D b) {
    Vector3D result;
    strcpy(result.name, "Векторное произведение");
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

// Модуль (длина) вектора
double vector_length(Vector3D v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

// Печать вектора
void print_vector(Vector3D v) {
    printf("%s: (%.2f, %.2f, %.2f)\n", v.name, v.x, v.y, v.z);
}

int main() {
    // Создаем векторы
    Vector3D v1 = {"Вектор A", 1.0, 2.0, 3.0};
    Vector3D v2 = {"Вектор B", 4.0, 5.0, 6.0};
    
    // Печатаем векторы
    print_vector(v1);
    print_vector(v2);
    
    // Скалярное произведение
    double dot = dot_product(v1, v2);
    printf("Скалярное произведение: %.2f\n", dot);
    
    // Векторное произведение
    Vector3D cross = cross_product(v1, v2);
    print_vector(cross);
    
    // Модули векторов
    printf("Длина вектора %s: %.2f\n", v1.name, vector_length(v1));
    printf("Длина вектора %s: %.2f\n", v2.name, vector_length(v2));
    
    return 0;
}