#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int inicializa(int *matriz[fil][col]);
void calculaminimo(int matriz[8][5]);

int main(int argc, char *argv[]) {
    srand(time(NULL));

    float *pmatriz;

    int numeros, numfilas, numcolumnas, i, j;

    printf("********** Bienvenido a BUSCA EL MÍNIMO **********\nIndique número de filas y columnas serán separado por un intro: ");
    scanf("%2f", numfilas);
    scanf("%2f", numcolumnas);

    numeros = numfilas * numcolumnas;
    pmatriz = (float*)malloc(sizeof(float) * numeros);

    //La inicializamos
    inicializa(*pmatriz[numfilas][numcolumnas]);
    //Enseñamos como queda inicializada
    printf("\nLa matriz aleatoria queda así: ");
    for(i=0; i<numeros; i++)
        printf("%.2f ", (*(pmatriz+i)));

    printf("\nY el mínimo es: %.2f\n", calculaminimo(pmatriz));
    return 0;
}

int inicializa(int *matriz[fil][col]) {
    int i,j;
    for(i=0; i<fil; i++) {
        for(j=0; j<col; j++) {
            *(pmatriz+i*col+j) = rand()%10+1;
            printf("%d\t", *(pmatriz+i*col+j));
        }
        printf("\n");
    }
    return pmatriz;
}

void calculaminimo(int matriz) {
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