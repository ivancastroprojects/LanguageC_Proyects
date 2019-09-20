#include <stdio.h>
#include <stdlib.h>

int main() {

    int m, n;
    int suma = 0;

    do {
        printf("Esciba un número (será M): \n");
        scanf("%d", &m);

        printf("Esciba otro número (será N): \n");
        scanf("%d", &n);

    } while (m < n); // Pide nuevos números si M es menor que N



    do {  // Si M es mayor que N, calculamos intervalo
        suma = suma + (m);
        m--;

    } while (m >= n);

    printf("La suma del intervalo es: %d\n", suma);

    return 0;
}

