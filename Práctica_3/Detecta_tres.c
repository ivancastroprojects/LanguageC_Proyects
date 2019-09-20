#include <stdio.h>
#include <stdlib.h>

int main () {
    int Num;
    printf("Escribe un número: ");

    scanf("%d", &Num);

    if (Num == 3) {
        printf("El número introducido es el 3\n");
        } else {
            printf("El número introducido no es el 3\n");
        }

    printf("Fin del algoritmo\n");

    return 0;
}
