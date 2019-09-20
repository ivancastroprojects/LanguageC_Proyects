#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tamano_v 15

float media(float vector[tamano_v]);
float varianza(float vector[tamano_v], float media);
float desviacion(float varianza);

////////////////////////////////////////////////////////////


int main() {
    int i;
    float vec_numeros[tamano_v];
    printf("Introduzca 15 números\n");

    for(i=0; i<tamano_v; i++) {
        scanf("%e", &vec_numeros[i]);
    }

    printf("La media es: %2f.\n", media(vec_numeros));
    printf("La varianza es: %2f.\n", varianza(vec_numeros, media(vec_numeros)));
    printf("La desviación es: %2f.\n", desviacion(varianza(vec_numeros, media(vec_numeros))));

    return 0;
}

///////////////////////////////////////////////////////////

float media(float vector[tamano_v]) {
    float v_media, suma;
    int i;
    for(i=0; i<tamano_v; i++) {
        suma += vector[i];
    }
    return v_media = suma/15;
}

float varianza(float vector[tamano_v], float media) {
    float v_varianza;
    int i;
    float suma;
    for(i=0; i<tamano_v; i++) {
        suma += pow(vector[i], 2);
    }
    return v_varianza = (suma-pow(media, 2))/15;
}

float desviacion(float varianza) {
    float v_desviacion;
    return v_desviacion = sqrt(varianza);
}
