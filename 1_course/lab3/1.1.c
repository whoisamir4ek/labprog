#include <stdio.h>

struct MyStruct {
    void (*function)(int);
};

void print_number(int num) {
    printf("Number: %d\n", num);
}

int main() {
    struct MyStruct my_instance;
    my_instance.function = print_number;
    
    my_instance.function(123);
    
    return 0;
}