#include <stdio.h> 
#include <string.h> 

int main () 
{ 
    
char cadena1[101];
char cadena2[101]={"compara\n"};

printf("\nIntroduce una cadena: \n");
fgets(cadena1,100,stdin);

printf("\nLa longitud de la cadena insertada es %ld.\n", strlen(cadena1));

if(strcmp(cadena1, cadena2)==0)
    printf("La cadena original es igual a 'compara'.");
else printf("La cadena original es distinta a 'compara'.");
    
printf("\nEl resultado de concatenar ambas cadenas es: %s.\n", strcat(cadena1,cadena2));

return 0; 

}