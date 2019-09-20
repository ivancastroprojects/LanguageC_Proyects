#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, num;
    int factorial = 1;

    printf("Escribe un número: ");
    scanf("%d", &num);

    if(num != 0) {    //Caso general
        for(i = num; i >= 1; i--) {
            factorial = i * factorial;
        }
        printf("El resultado es: %d.\n", factorial);

    } else printf("El resultado es: %d.\n", 1); //Si num == 0

    return 0;
}