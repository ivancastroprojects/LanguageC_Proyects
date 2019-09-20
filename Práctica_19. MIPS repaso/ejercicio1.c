#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char*argv[]) {

    srand(time(NULL));

    if(argc != 3) {
        printf("Error. Debe introducir dos parámetros");
        return -1;
    }       

    int *matriz, i, j;
    int numfil = atoi(argv[1]), numcol = atoi(argv[2]);
    
    matriz = (int*)malloc(sizeof(int)*numfil*numcol);

    for(i=0; i<numfil; i++) {
        for(j=0; j<numcol; j++) {
            if(i == j) {
                *(matriz+i*numcol+j) = 1;   

            } else if(i==numcol-1-j) {
                *(matriz+i*numcol+j) = 0;
                
            } else {
                *(matriz+i*numcol+j) = rand()% 11;
            }
            printf("%d\t", *(matriz+i*numcol+j));
        }    
        printf("\n");
    }

    return 0;

}