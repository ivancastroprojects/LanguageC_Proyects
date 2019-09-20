#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quitaespacios(char *cadena, char *cadenasin);


int main(){

int n;
char *pcadena, *pcadenasin;

printf("Ingrese el numero de caracteres de la cadena: ");
scanf("%d",&n);

pcadena = (char*)malloc(sizeof(char)*n);
pcadenasin = (char*)malloc(sizeof(char)*n);

printf("Se ha reservado espacio de memoria para %d caracteres.\n", n);
printf("\nIngrese la cadena: ");
scanf("%s[^\n]",pcadena);

quitaespacios(pcadena, pcadenasin);
printf("\nLa cadena sin espacios es: %s\n", pcadenasin);

return 0;
}


void quitaespacios(char *cadena, char *cadenasin)
{
   int i, j;
   cadena = strtok(cadena, ' ');
   for (i = j = 0; cadena[i] != '\0'; i++)
      if (cadena[i] != 32)
         cadenasin[j++] = cadena[i];
   cadenasin[j] = '\0';
}