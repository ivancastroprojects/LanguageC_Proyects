#include <stdio.h>
#include <string.h>

#define NUMCARACS 120


int main(int argc, char *argv[])
{
	char cadena[NUMCARACS];
	int longitud;
	if (argc!=3)
	{
		printf("\n\nError, el número de argumentos no es válido. Sintaxis: nombreprograma \"cadena\" número");
	}
	else 
	{
		printf("\nIntroduzca una cadena de como máximo 100 caracteres: ");
		fgets(cadena,100,stdin);
		longitud=strlen(cadena);
		printf("\nLa longitud de la cadena es %d", longitud);
		printf("\nLa cadena concatenada es %s", strcat(cadena,"Cadena añadida"));
		if (strstr(cadena,argv[1])!=NULL)
			printf("\nLa cadena SÍ tiene la cadena %s", argv[1]);
		else
			printf("\nLa cadena NO tiene la cadena %s", argv[1]);
		printf("\nLa letra de la posición %d es %c", atoi(argv[2]), cadena[atoi(argv[2])-1]);
	}
	
	return 0;
}

