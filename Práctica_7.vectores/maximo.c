#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tamano_v 10

void inicializa(int vector[tamano_v]);
int maximo(int vector[tamano_v]);

////////////////////////////////////////////////////////////


int main(){
    int vector_numeros[tamano_v];

    inicializa(vector_numeros);
    printf("El número máximo es: %d.\n", maximo(vector_numeros));

    return 0;
}

///////////////////////////////////////////////////////////


void inicializa(int vector[tamano_v]) {
    printf("Escribe 10 números: \n");

    int i;
    for(i = 0; i < tamano_v; i++)
    {
        scanf("%d", &vector[i]);
    }
    printf("\nVector inicializado con los números solicitados.\n");
}


int maximo(int vector[tamano_v]) {
    int i, max = 0;
    for(i = 0; i < tamano_v; i++) {
        if(vector[i] > max)
            max = vector[i];
    }
    return max;
}

