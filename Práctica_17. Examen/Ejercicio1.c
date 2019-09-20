#include <stdio.h>
#include <stdlib.h>

void cuenta(char cad[100], char *vletras, int *vnumeros, int n);

int main() {
    char cad[100], vletras;
    int n, i, vnumeros;
    
    printf("Introduce una cadena: ");
    fgets(cad, 100, stdin);

    do {
        printf("\nIntroduce un número");
        scanf("%d", &n);
        if(n<=0)
        printf("\nError. El número debe ser positivo.");
    } while(n<=0);
    
    vletras = (char*)malloc(n*sizeof(char));
    vnumeros = (int*)malloc(n*sizeof(int));
    
    printf("Introduce %d letras separadas por intro: ", n);
    for(i=0; i<n; i++) {
        while(getchar() != '\n');
            scanf("%c", vletras+i);
            while(getchar() != '\n');
    }
    cuenta(cad, vletras, vnumeros, n);
    printf("El número de letras es: \n");
}

void cuenta(char cad[100], char *vletras, int *vnumeros, int n) {
    int i, j = 0;

    for(i=0; i<n; i++) {
        j=0;
        vnumeros[i] = 0;
        while(cad[j] != '\0') {
            if(cad[j] == vletras[i])
                vnumeros[i]++;
            j++;
        }
    }    
    return;
}


