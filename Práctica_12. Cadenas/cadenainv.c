#include <stdio.h> 
#include <string.h> 

void invierte(char cadenaOrigen[100], char cadenaDestino[100]);

int main () 
{ 
    
char cadenaleida[100];
char cadenainv[100];

printf("\nIntroduce una cadena: \n");
fgets(cadenaleida,100,stdin);

invierte(cadenaleida, cadenainv);
printf("\nLa cadena invertida queda así: %s\n", cadenainv);

return 0; 

}


void invierte(char cadenaOrigen[100], char cadenaDestino[100])
{
    int i;
    int k = strlen(cadenaOrigen)-1;

    for(i=0; i<strlen(cadenaOrigen); i++) {
        cadenaDestino[k] = cadenaOrigen[i];
        k--; 
    }
    cadenaDestino[k]='\n';
}

