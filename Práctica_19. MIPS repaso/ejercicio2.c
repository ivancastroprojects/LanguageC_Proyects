#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void rellena(int *v, int num);
int pares(int *v);

int main(int argc, char*argv[]) {
    if(argc != 2) {
        printf("Error. El número de argumentos debe ser 2.");
        return -1;
    }
    
    int *vector, numelem = atoi(argv[1]);
    vector = (int*)malloc(sizeof(int)*numelem);

    rellena(vector, numelem);
    printf("\nEl número de elementos pares es: %d\n", pares(vector));

return 0;
}


void rellena(int *v, int num) {
    int i;
    
    for(i=0; i<sizeof(v)+1; i++) {
        if(i==0 || i==1) {
            v[0] = 1;
            v[1] = 1;
        } else {
            v[i] = v[i-1] + v[i-2];
        }
        printf("%d\t", v[i]);
    }
}

int pares(int *v) {
    int i, cont=0;

    for(i=0; i<sizeof(v)+1; i++) {
        if(*(v+i)%2==0) {
            cont++;
        }
    }
    return cont;
}