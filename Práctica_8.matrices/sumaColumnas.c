#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializa(int matriz[3][6]);
int sumaColumnas(int matriz[3][6], int vector[6]);

int main() {
    srand(time(NULL));
    int m, matrizaleat[3][6], vectorsum[6];

    inicializa(matrizaleat);
    sumaColumnas(matrizaleat, vectorsum);

    for(m=0; m<6; m++){
        printf("\nSuma de la columna %d : %d\n",m,vectorsum[m]);
    }


    return 0;
}

int inicializa(int matriz[3][6]) {
    int i,j;
    for(i=0; i<3; i++) {
        for(j=0; j<6; j++) {
            matriz[i][j] = rand()%(11-1);
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int sumaColumnas(int matriz[3][6], int vector[6]) {
    int i,j;
    for(j=0; j<6; j++) {
    int suma=0;
        for(i=0; i<3; i++) {
            suma += matriz[i][j] ;            
        }
        vector[j]=suma;
    }
    return vector;
}