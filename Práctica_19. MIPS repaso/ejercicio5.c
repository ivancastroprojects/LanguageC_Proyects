#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void inicializa(int orden, int *matriz);

int main(int argc, char *argv[]) {
    
    srand(time(NULL));

    if(argc != 2) {
        printf("Error. El nº de argumentos debe ser 2.");
        return -1;
    }
    
    int *matriz;
    int orden = atoi(argv[1]);

    matriz = (int*)malloc(sizeof(int)*orden*orden);

    inicializa(orden, matriz);

    return 0;
}

void inicializa(int orden, int *matriz) {
    int i, j;
    for(i=0; i<orden; i++) {
        for(j=0; j<orden; j++) {
            if(i==j) {
                *(matriz+i*orden+j) = 0;
            } else {
                *(matriz+i*orden+j)= rand()% 11;
            }
            printf("%d\t", *(matriz+i*orden+j));
        }
        printf("\n");
    }
}
