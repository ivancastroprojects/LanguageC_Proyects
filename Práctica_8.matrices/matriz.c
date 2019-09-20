#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

int inicializa(int matriz[TAM][TAM]);

int main() {
    srand(time(NULL));
    int i,j, matrizaleat[TAM][TAM];

    inicializa(matrizaleat);

    return 0;
}

int inicializa(int matriz[TAM][TAM]) {
    int i,j;
    for(i=0; i<TAM; i++) {
        for(j=0; j<TAM; j++) {
            matriz[i][j] = 3+rand()%13;
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}
