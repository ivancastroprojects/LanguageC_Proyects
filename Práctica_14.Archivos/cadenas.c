//Realice un programa en lenguaje C al cual se le pasen una cadena y un número como argumentos. 
//La función main leerá otra cadena de como máximo 100 caracteres por teclado. 
//A continuación debe calcular:
/*
• La longitud de la cadena introducida por teclado y mostrarla por
    pantalla.
• Concatenar la cadena introducida con la cadena "Cadena añadida" y
    mostrar la cadena resultante por pantalla.

• Buscar si contiene la cadena pasada como argumento y en caso de
    que la tenga, indicarlo por pantalla.

• Mostrar la letra que ocupa la posición especificada por el número que
    se le pasa como argumento. Es decir, si la cadena leída es "Hola" y
    se le pasó el número 2, debe mostrar la letra o.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TAM 120

int main(int argc, char*argv[]) {

    char cad[TAM];

    if(argc != 3) {                         
        printf("Error, argumentos incorrectos"); //Comprobamos que sean 3 argumentos
    }
    else {

        printf("\nIntroduce una cadena: "); //Leemos otra cadena de 100
        fgets(cad, 100, stdin);
        printf("\nLa longitud de la cadena es %d.", strlen(cad)); //Imprimimos el contador

        printf("\nCadenas concatenadas: %s.", strcat(cad, "Cadena añadida"));

        if(strstr(cad, argv[1]) != NULL)
            printf("\nLa cadena %s contiene a %s.", cad, argv[1]);
        else printf("\nLa cadena no contiene la cadena %s", argv[1]);

        printf("\nLa letra de la posicion %d es %c", atoi(argv[2]), cad[atoi(argv[2])-1]);
    }   
return 0;
}


