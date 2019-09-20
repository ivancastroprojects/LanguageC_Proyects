#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float maximo(float *pnum);

int main(int argc, char *argv[])
{
    float *pnum;

    int numnotas, i;

    printf("********** Bienvenido a BUSCA EL MÁXIMO **********\nIndique cuantos números serán: ");
    scanf("%d", &numnotas);

    pnum = (float*)malloc(sizeof(float)*numnotas);

    printf("\nIntroduce %d notas separadas por un intro: \n", numnotas);

    for(i=0; i<numnotas; i++)
        scanf("%2f", pnum+i);

    printf("\nLos números introducidos son: ");
    for(i=0; i<numnotas; i++)
        printf("%.2f ", (*(pnum+i)));

    printf("\nY el máximo es: %.2f\n", maximo(pnum));
    return 0;
}

float maximo(float *pnum)
{
    int i;
    float max=0.0;
    for(i=0; i<sizeof(pnum); i++)
    {
        if((*(pnum+i)) > max)
            max = (*(pnum+i));
    }
    return max;
}
