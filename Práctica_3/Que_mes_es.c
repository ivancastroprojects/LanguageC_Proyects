#include <stdio.h>

int main ()
{
int Num;

printf("Escribe el número del mes: ");
scanf("%d", &Num); 

switch (Num){

    case 1: printf("El mes es Enero\n");
    break;
    case 2: printf("El mes es Febrero\n");
    break;
    case 3: printf("El mes es Marzo\n");
    break;
    case 4: printf("El mes es Abril\n");
    break;
    case 5: printf("El mes es Mayo\n");
    break;
    case 6: printf("El mes es Junio\n");
    break;
    case 7: printf("El mes es Julio\n");
    break;
    case 8: printf("El mes es Agosto\n");
    break; 
    case 9: printf("El mes es Septiembre\n");
    break;
    case 10: printf("El mes es Octubre\n");
    break;
    case 11: printf("El mes es Noviembre\n");
    break;
    case 12: printf("El mes es DIciembre\n");
    default:
    printf("Error. Inserte un número de mes correcto.\n");
}

return 0;
}