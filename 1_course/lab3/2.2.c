#include <stdio.h>

// Объединение для доступа к отдельным байтам числа
union LongBytes {
    unsigned long number;  // Целое число (обычно 4 или 8 байт)
    unsigned char bytes[sizeof(unsigned long)];  // Массив байтов
};

int main() {
    union LongBytes lb;
    lb.number = 0x12345678;  // Пример числа для анализа
    
    printf("Число: 0x%lx (%lu)\n", lb.number, lb.number);
    printf("Байты (младший байт первый):\n");
    
    // Печатаем каждый байт отдельно
    for (size_t i = 0; i < sizeof(unsigned long); i++) {
        printf("Байт %zu: 0x%02x\n", i, lb.bytes[i]);
    }
    
    return 0;
}