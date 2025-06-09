#include <stdio.h>

int main() {
    int i;
    
    printf("os numeros pares de 1 a 10 são:\n");
    
    for (i = 0; i <= 10; i++) {
        
        if (i % 2 == 0) {
            
            printf("%d\n", i);
        }
    }

    return 0;
}

