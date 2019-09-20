#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializa(int matriz[5][5]);
int maximo(int matriz[5][5]);

int main() {
    srand(time(NULL));

    int matrizA[5][5];

    inicializa(matrizA);
    printf("\nEl valor máximo es: %d\n", maximo(matrizA));

    return 0;
}

int inicializa(int matriz[5][5]) {
    int i,j;
    for(i=0; i<5; i++) {
        for(j=0; j<5; j++) {
            matriz[i][j] = rand()%(10+1);
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    return matriz;
}

int maximo(int matriz[5][5]) {
    int i, j, k;
    int max = 0;
    for (i=0; i<5; i++)
        for (j=0; j<5; j++)  {
            if(matriz[i][j] > max)
                max = matriz[i][j];
  }
    return max;
}