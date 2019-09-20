#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializa(int vector);

int main() {
    srand(time(NULL));
    int aleatorio;
    int orden;
    int abecedario_minusc[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int abecedario_mayusc[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int numeros[10] = {'0','1','2','3','4','5','6','7','8','9'};
    char contra[8];

    inicializa(abecedario_minusc);
    inicializa(abecedario_mayusc);
    inicializa(numeros);

    for(int i=0; i<8; i++) { 
        aleatorio = rand()%26;
        orden = rand()%3;
        if(orden == 0)
            contra[i] = abecedario_minusc[aleatorio];
        if(orden == 1)
            contra[i] = abecedario_mayusc[aleatorio];
        if(orden == 2)
            contra[i] = numeros[aleatorio];
    }
    printf("La contraseña es: %s\n", contra);

    return 0;
}

int inicializa(int vector) {
    int i;
    for(i=0; i<sizeof(vector); i++) {
    }
    return vector;
}

