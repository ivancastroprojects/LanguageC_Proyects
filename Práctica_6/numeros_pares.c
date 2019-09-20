#include <stdio.h>

int numeros_pares(int a, int b);


int main() {
    int numA, numB;

    printf("Introduzca dos números: \n");
    scanf("%d", &numA);
    scanf("%d", &numB);
    
    if (numA < numB) {
        numeros_pares(numA, numB);
    } else printf("Error. El primero debe ser menor que el segundo.\n");
  
    return 0;
}

int numeros_pares(int a, int b) {

    for(int i = b; b > a; i--){
        if(i%2 == 0){
            printf("%d, ",i);
        }
    }
}