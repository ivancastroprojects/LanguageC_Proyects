#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE
#define MAX_CHAR 100
#define MAX_ALUMNOS 5

void leer_archivo(char m[MAX_ALUMNOS][MAX_CHAR]);
void busca_nombre(char m[MAX_ALUMNOS][MAX_CHAR], char letra);
void imprime(char m[MAX_ALUMNOS][MAX_CHAR]);

int main(){

	FILE *parchivo;
	char alumnos[MAX_ALUMNOS][MAX_CHAR];
	char inicial;
	
    leer_archivo(alumnos);
    
    //Pedimos inicial al usuario
    printf("Introduzca la inicial de la persona a buscar.\n");
    scanf("%c", &inicial);
    busca_nombre(alumnos, inicial);
    
    printf("\nLos alumnos son:\n");
    imprime(alumnos);
	return 0;
}

void leer_archivo(char m[MAX_ALUMNOS][MAX_CHAR])
{
    FILE *parchivo;
    size_t n=0;
    ssize_t bytesleidos;
    int i=0;
    char *linea =NULL;
    if ((parchivo = fopen("info.txt","r")) == NULL){
        printf("Error al abrir el fichero");
        exit(EXIT_FAILURE);
    }
    
    do{
        bytesleidos=getline(&linea, &n, parchivo);
        if (bytesleidos!=-1){
            strncpy(m[i], linea, bytesleidos-1);
            m[i][bytesleidos-1]=0;
            i++;
        }
    }while(bytesleidos!=-1);
    free(linea);
    fclose(parchivo);
    return;
    
}
void busca_nombre(char m[MAX_ALUMNOS][MAX_CHAR], char letra)
{
    int i;
    for (i=0; i<MAX_ALUMNOS; i++) {
        if (m[i][0]==letra){
            printf("%s\n",m[i]);
        }
    }
    return;
}
void imprime(char m[MAX_ALUMNOS][MAX_CHAR])
{
    int i;
    for (i=0; i<MAX_ALUMNOS; i++)
        printf("%s\n",m[i]);
    return;
}