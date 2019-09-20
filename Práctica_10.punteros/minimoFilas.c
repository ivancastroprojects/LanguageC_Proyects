#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int inicializa(int matriz[8][5]);
void minimoFilas(int matriz[8][5], int vector[8]);

int main() {
    srand(time(NULL));
    int m, matrizaleat[8][5], vectormin[8];

    inicializa(matrizaleat);
    minimoFilas(matrizaleat, vectormin);

    printf("\nVector de mínimos: [");
    for(m=0; m<8; m++){
        printf(" %d " ,vectormin[m]);
    }
    printf("]\n\n");
    return 0;
}

int inicializa(int matriz[8][5]) {
    int i,j;
    for(i=0; i<8; i++) {
        for(j=0; j<5; j++) {
            matriz[i][j] = rand()%21-10;
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void minimoFilas(int matriz[8][5], int vector[8]) {
    int i,j;
    int minimo = 0;

    for(i=0; i<8; i++) {
        vector[i]=matriz[i][0];
        for(j=0; j<5; j++) {
            if(matriz[i][j] < vector[i])
                vector[i] = matriz[i][j];
        }
    }

}