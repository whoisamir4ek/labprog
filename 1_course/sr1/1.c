#include <stdio.h> 
#include <stdlib.h> 

float mean(float *p, int n) {  
    float sum = 0.0, mean_val; 
    for (int i = 0; i < n; i++) {
        sum = sum + (*p + i); 
    }
    mean_val = sum / n;
    return mean_val;  
}

int main() {
    int n;  
    float *arr, m;
    
    printf("Введите размер массива: ");
    scanf("%d", &n);  

    arr = (float *)malloc(n * sizeof(float));
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", arr + i); 
    }

    m = mean(arr, n); 
    printf("Среднее арифметическое элементов массива: %.2f\n", m);

    free(arr);
    return 0;
}