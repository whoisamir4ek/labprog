#include <stdio.h> 
#include <stdlib.h> 
int main() {double ***pointer = NULL; pointer = malloc(sizeof(double**)); *pointer = malloc(sizeof(double*)); **pointer = malloc(sizeof(double)); ***pointer = 2.0; printf("%.2lf", ***pointer); free(**pointer); free(*pointer); free(pointer);}