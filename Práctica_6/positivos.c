#include <stdio.h>
#include <stdlib.h>


int calcula_exp(int a, int b);


int main() {
    int numA, numB;

    printf("Introduzca dos números: \n");
    scanf("%d", &numA);
    scanf("%d", &numB);
    
    if (numA>0 && numB>0) { //Si son positivos
        calcula_exp(numA, numB);
    } else printf("Error. Deben ser positivos.\n"); //Si son negativos
  
    return 0;
}

int calcula_exp(int a, int b) {
    printf("El resultado es: %d", pow(a,b));
}