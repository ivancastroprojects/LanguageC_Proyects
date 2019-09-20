#include <stdio.h>
//Función principal del programa
int main () {
// Este programa calcula la suma de los primeros n números
// Declaro las variables de mi función
int Num, Total, i;
//Sustituyo la función ESCRIBA cadena por printf
printf("Escribe cuantos números quieres sumar: ");
//Sustituyo la función LEA Num por scanf ( %d, &variableEntera);
scanf("%d", &Num); //Guarda el número leído en la variable Num
//Inicializo las variables
Total = 0;
i = 1;
//Compruebo si el número introducido es mayor o igual que 1
if (Num >= 1) {
//Hago el bucle para sumar hasta que i valga n
    while (i <= Num){
//Calculo la suma parcial
    Total = Total + i;
    i++;
    }
//Sustituyo la función ESCRIBA cadena por printf
    printf("La suma es: %d \n", Total);
} else {
//Sustituyo la función ESCRIBA cadena por printf
printf("El número ha de ser mayor o igual a 1");

}
//Fin del programa
return 0;
}