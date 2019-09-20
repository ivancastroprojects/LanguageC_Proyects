#include <stdio.h>
#include <stdlib.h>

int inicializa(int vector);

int main() {
    srand(time(NULL));
    int aleatorio;
    int abecedario_ingles[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char contra[8];

    inicializa(abecedario_ingles);

    for(int i=0; i<8; i++) { 
        aleatorio = rand()%26;
        contra[i] = abecedario_ingles[aleatorio];
    }
    printf("La contraseña es: %s.\n", contra);

    return 0;
}

int inicializa(int vector) {
    int i;
    for(i=0; i<sizeof(vector); i++) {
    }
    return vector;
}

