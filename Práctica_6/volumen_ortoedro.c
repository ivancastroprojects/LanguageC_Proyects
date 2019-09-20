#include <stdio.h>
#define PI 3,1415

float volumen_cono(float r, float h);
float volumen_ortoedro(float al, float la, float an);

int main() {
    int option;
    int radio, altura;
    int alto, largo, ancho;

    printf("Introduzca una opcion:\n 1. Calcular volumen del cono.\n 2. Cacular volumen del ortoedro\n.");
    
    scanf("%d", &option);
    switch (option)
    {
        case 1: printf("Se ha elegido el volumen del cono.\n Ingrese el radio: ");
                scanf("%d", &radio);
                printf("Ingrese la altura\n");
                scanf("%d", &altura);
                
                printf("El volumen del cono es: %.2f\n", volumen_cono(radio, altura));
            break;

        case 2: printf("Se ha elegido el volumen del ortoedro.\n Ingrese el alto: ");
                scanf("%d", &alto);
                printf("Ingrese el largo\n");
                scanf("%d", &largo);
                printf("Ingrese el ancho\n");
                scanf("%d", &ancho);
                
                printf("El volumen del ortoedro es: %.2f\n", volumen_ortoedro(alto, largo, ancho));
            break;

        default: printf("Error. Ingrese una opcion válida.\n");
            break;
    }

    return 0;
}

