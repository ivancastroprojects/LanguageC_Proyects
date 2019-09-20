#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tamano_v1 15
#define tamano_v2 2

void enteros(int vector[tamano_v1], int tipo[tamano_v2]);

////////////////////////////////////////////////////////////


int main() {
    int i;
    int vec_numeros[tamano_v1];
    int tipo_numero[tamano_v2]; //0 Par, 1 Impar
    printf("Introduzca 15 números enteros: \n");

    for(i=0; i<tamano_v1; i++) {
        scanf("%d", &vec_numeros[i]);
    }

    enteros(vec_numeros, tipo_numero);
    printf("\nHay %d números pares y %d números impares.", tipo_numero[0], tipo_numero[1]);

    return 0;
}

void enteros(int vector[tamano_v1], int tipo[tamano_v2]) {
    int i;
    tipo[0] = 0; 
    tipo[1] = 0;
    for(i=0; i<tamano_v1; i++)
    {
        if(vector[i]%2==0)  //Si dividido entre 2 da 0 es PAR
            tipo[0] += 1;   
        else tipo[1] += 1;  //Si no IMPAR
    }
}


