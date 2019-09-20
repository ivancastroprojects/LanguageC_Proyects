#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializa(int matriz[3][3]);
int multiplica(int matriz1[3][3], int matriz2[3][3], int matriz3[3][3]);

int main() {
    srand(time(NULL));

    int matrizA[3][3], matrizB[3][3], matrizC[3][3];

    inicializa(matrizA);
        printf("\n");
    inicializa(matrizB);
        printf("\n");
    multiplica(matrizA, matrizB, matrizC);

    int m, n;
    for(m=0; m<3; m++) {
        for(n=0; n<3; n++) {
            printf("%d\t", matrizC[m][n]);    
        }
        printf("\n");
    }

    return 0;
}

int inicializa(int matriz[3][3]) {
    int i,j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            matriz[i][j] = rand()%(10+1);
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    return matriz;
}

int multiplica(int matriz1[3][3], int matriz2[3][3], int matriz3[3][3]) {
    int i, j, k;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)  {
            matriz3[i][j] = 0;
            for (k=0; k<3; k++)
                matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
  }
    return matriz3;
}