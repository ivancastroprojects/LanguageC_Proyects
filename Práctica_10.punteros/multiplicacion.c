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
            for (k=0; k<3; k++) {
                 matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
            }
    }
    return matriz3;
}






#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

int * pm1, *pm2, *pm3, numfilas,numcols, i,j;

//Leemos cuántas filas tienen las matrices
printf("indique cuántas filas tienen: ");
scanf("%d",&numfilas);

//Leemos cuántas columnas tienen las matrices
printf("indique cuántas columnas tienen: ");
scanf("%d",&numcols);

/*Reservamos espacio para las matrices */
// Tienen numfilas*numcols números enteros
pm1=(int*)malloc(sizeof(int)*numfilas*numcols);
pm2=(int*)malloc(sizeof(int)*numfilas*numcols);
pm3=(int*)malloc(sizeof(int)*numfilas*numcols);

//Leemos las matrices A y B
for (i=0;i<numfilas;i++)
{
    for (j=0;j<numcols;j++)
    {
        printf("Introduzca la posición (%d,%d) de la matriz A y B separadas por un intro: ", i,j);
        scanf("%d",pm1+(i*numcols)+j);
        scanf("%d",pm2+(i*numcols)+j);
        
        *(pm3+(i*numcols)+j)=*(pm1+(i*numcols)+j)+(*(pm2+(i*numcols)+j));
    }
}

//Imprimimos el resultado
for (i=0;i<numfilas;i++)
{
    for (j=0;j<numcols;j++)
        printf("%d\t",*(pm3+(i*numcols)+j));
        printf("\n");
}

//liberamos memoria
free (pm1);
free (pm2);
free (pm3);
return 0;

}