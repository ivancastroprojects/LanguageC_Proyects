#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CHAR 10000

struct Tpunto {
    float x;
    float y;
    float z;
};

struct Ttriangulo {
    struct Tpunto p1;
    struct Tpunto p2;
    struct Tpunto p3;
    float area;
    float perimetro;
};

float calculaPerimetro(struct Tpunto punto1, struct Tpunto punto2, struct Tpunto punto3);
float calculaArea(struct Tpunto punto1, struct Tpunto punto2, struct Tpunto punto3);
struct Ttriangulo *leerDatos(char *nombrearchivo, int numlineas);
int numLineasArchivos(FILE *p);
int mayorArea(struct Ttriangulo *info, int tam);
int mayorPerimetro(struct Ttriangulo *info, int tam);

int main(int argc, char* argv[]) {
    struct Ttriangulo *info;
    int numtriangulos, resultado;
    FILE *parchivo;

    if (argc != 2)
        printf("Error, el número de argumentos no es correcto\n");
    else {
        parchivo = fopen(argv[1], "r");
        if(parchivo == NULL) {
            printf("Error al abrir el archivo");
        } else {
            numtriangulos = numlineasarchivo(parchivo);
            fclose(parchivo);

            info = leerDatos(argv[1], numtriangulos);
        }
    }
}
int numLineasArchivos(FILE *p) {
    int nlineas;
    char linea[MAX_CHAR];

    while(!feof(p)) {
        fgets(linea, MAX_CHAR, p);
        nlineas++;
    }
    return nlineas;
}

float calculaPerimetro(struct Tpunto punto1, struct Tpunto punto2, struct Tpunto punto3) {
    
}

struct Ttriangulo *leerDatos(char *nombrearchivo, int numlineas) {
    FILE *parchivo;
    struct Ttriangulo *info;
    int i;
    
    parchivo = fopen(nombrearchivo, "r");
    if(parchivo == NULL) {
        printf("Error al abrir el archivo");
    } else {
        info = (struct Ttriangulo*)malloc(sizeof(struct Ttriangulo)*numlineas);

        for(i=0; i<numlineas; i++) {
            fscanf(parchivo, "%f %f %f; %f %f %f; %f %f %f", &(info+i)-> p1.x,&(info+i)->p1.y,&(info+i)->p1.z,&(info+i)->p2.x,&(info+i)->p2.y,&(info+i)->p2.z,&(info+i)->p3.x,&(info+i)->p3.y,&(info+i)->p3.z);
            (info+i)->area = calculaArea((info+i)->p1,(info+i)->p2,(info+i)->p3);
            (info+i)->perimetro = calculaPerimetro((info+i)->p1,(info+i)->p2,(info+i)->p3);
        }
    }
};

float calculaArea(struct Tpunto punto1, struct Tpunto punto2, struct Tpunto punto3);
int mayorArea(struct Ttriangulo *info, int tam);
int mayorPerimetro(struct Ttriangulo *info, int tam);

