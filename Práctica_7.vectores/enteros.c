#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tamano_v1 20
#define tamano_v2 3

int enteros(int vector[tamano_v1], int tipo[tamano_v2]);

////////////////////////////////////////////////////////////

int main() {
    int i;
    int vec_numeros[tamano_v1];
    int tipo_numero[tamano_v2]; //0 Negativos, 1 Ceros, 2 Positivos
    printf("Introduzca 20 números enteros (positivos, negativos o 0): \n");

    for(i=0; i<tamano_v1; i++) {
        scanf("%d", &vec_numeros[i]);
    }

    enteros(vec_numeros, tipo_numero);
    
    printf("\nHay %d números positivos, %d ceros y %d números negativos.", tipo_numero[0], tipo_numero[1], tipo_numero[2]);

    return 0;
}

int enteros(int vector[tamano_v1], int tipo[tamano_v2]) {
    int i;
    tipo[0] = 0;
    tipo[1] = 0;
    tipo[2] = 0;
    for(i=0; i<tamano_v1; i++)
    {
        if(vector[i]<0)
            tipo[0] ++;  //Negativos +1
        else if(vector[i]=0)
            tipo[1] ++;  //Ceros +1
        else if(vector[i]>0)
            tipo[2] ++;  //Positivos +1
    }
    return tipo;
}