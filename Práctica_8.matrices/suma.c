#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializa(int matriz[][6]);
int suma(int matriz[][6]);

int main() {
    srand(time(NULL));
    int i,j, matrizaleat[6][6];

    inicializa(matrizaleat);
    printf("\nEl resultado de la suma es: %d. \n", suma(matrizaleat));

    return 0;
}

int inicializa(int matriz[][6]) {
    int i,j;
    for(i=0; i<6; i++) {
        for(j=0; j<6; j++) {
            matriz[i][j] = rand()%(11-1);
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int suma(int matriz[][6]) {
    int i,j;
    int suma = 0;
    for(i=0; i<6; i++) {
        for(j=0; j<6; j++) {
            suma += matriz[i][j];
        }
    }
    return suma;
}
