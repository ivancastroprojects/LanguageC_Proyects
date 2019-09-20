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


float calculaperimetro(struct Tpunto punto1, struct Tpunto punto2,struct Tpunto punto3);
float calculaarea(struct Tpunto punto1, struct Tpunto punto2,struct Tpunto punto3);
struct Ttriangulo *leerdatos(char *nombrearchivo, int numlineas);
int numlineasarchivo(FILE *p);
int mayorarea(struct Ttriangulo *info, int tam);
int mayorperimetro(struct Ttriangulo *info, int tam);


int main(int argc, char* argv[]){
	
	struct Ttriangulo *info;
	int numtriangulos,resultado;
	FILE *parchivo;

	
	
	if (argc!=2)
		printf("Error, el número de argumentos no es correcto\n");
	else {
		parchivo=fopen(argv[1],"r");
		if (parchivo==NULL) {
			printf("Error al abrir el archivo");
		}
		else {
			//obtenemos el número de líneas del fichero
			numtriangulos =numlineasarchivo(parchivo);
			fclose(parchivo);
			
			info=leerdatos(argv[1],numtriangulos);
			
			resultado=mayorarea(info,numtriangulos);			
			printf("El triángulo con mayor área tiene como puntos (%f,%f,%f),(%f,%f,%f) y (%f,%f,%f) y su área es %f\n",(info+resultado)->p1.x,(info+resultado)->p1.y,(info+resultado)->p1.z,(info+resultado)->p2.x,(info+resultado)->p2.y,(info+resultado)->p2.z,(info+resultado)->p3.x,(info+resultado)->p3.y,(info+resultado)->p3.z,(info+resultado)->area);
			resultado=mayorperimetro(info,numtriangulos);			
			printf("El triángulo con mayor perímetro tiene como puntos (%f,%f,%f),(%f,%f,%f) y (%f,%f,%f) y su perímetro es %f\n",(info+resultado)->p1.x,(info+resultado)->p1.y,(info+resultado)->p1.z,(info+resultado)->p2.x,(info+resultado)->p2.y,(info+resultado)->p2.z,(info+resultado)->p3.x,(info+resultado)->p3.y,(info+resultado)->p3.z,(info+resultado)->perimetro);
		
			free(info);						
		}

	}

	return 0;
}

int numlineasarchivo(FILE *p)
{
	int nlineas;
	char linea[MAX_CHAR];

	//obtenemos el número de líneas del fichero
	nlineas = 0;
	while (!feof(p)) {
		fgets(linea,MAX_CHAR,p);
		nlineas++;
	}
	return nlineas;
}


//Lee los datos de un archivo y los guarda en Ttriangulos
struct Ttriangulo *leerdatos(char *nombrearchivo, int numlineas)
{
	FILE *parchivo;
	struct Ttriangulo *info;
	int i;
	
	parchivo=fopen(nombrearchivo,"r");
	if (parchivo==NULL) {
		printf("Error al abrir el archivo");
	}
	else {
	
		//reservamos espacio para la matriz
		info=(struct Ttriangulo*)malloc(sizeof(struct Ttriangulo)*numlineas);
	
		//leemos los datos
		for (i=0; i<numlineas; i++) {
			fscanf (parchivo, "%f %f %f;%f %f %f;%f %f %f",&(info+i)->p1.x,&(info+i)->p1.y,&(info+i)->p1.z,&(info+i)->p2.x,&(info+i)->p2.y,&(info+i)->p2.z,&(info+i)->p3.x,&(info+i)->p3.y,&(info+i)->p3.z);
			(info+i)->area=calculaarea((info+i)->p1,(info+i)->p2,(info+i)->p3);
			(info+i)->perimetro=calculaperimetro((info+i)->p1,(info+i)->p2,(info+i)->p3);
		}
	}
	fclose(parchivo);
	return info;
}


//Devuelve el índice del triángulo con mayor área
int mayorarea(struct Ttriangulo *info, int tam)
{
	int res,i;
	res=0;
	for (i=0; i<tam; i++) {
		if ((info+i)->area > (info+res)->area) {
			res=i;
		}
	}
	return res;
}

//Devuelve el índice del triángulo con mayor perímetro
int mayorperimetro(struct Ttriangulo *info, int tam)
{
	int res,i;
	res=0;
	for (i=0; i<tam; i++) {
		if ((info+i)->perimetro > (info+res)->perimetro) {
			res=i;
		}
	}
	return res;
}


//Dados 3 puntos de un triángulo, calcula el perímetro
float calculaperimetro(struct Tpunto punto1, struct Tpunto punto2,struct Tpunto punto3)
{
	float lado1,lado2,lado3,perimetro;
	lado1 = sqrt(pow(punto1.x-punto2.x,2)+pow(punto1.y-punto2.y,2));
	lado2 = sqrt(pow(punto1.x-punto3.x,2)+pow(punto1.y-punto3.y,2));
	lado3 = sqrt(pow(punto3.x-punto2.x,2)+pow(punto3.y-punto2.y,2));
	perimetro = lado1 + lado2 + lado3;
	return perimetro;
}

//Dados 3 puntos de un triángulo, calcula el área
float calculaarea(struct Tpunto punto1, struct Tpunto punto2,struct Tpunto punto3)
{
	float s,area,lado1,lado2,lado3;
	s= 1.0/2.0 * calculaperimetro(punto1,punto2,punto3);
	lado1 = sqrt(pow(punto1.x-punto2.x,2)+pow(punto1.y-punto2.y,2));
	lado2 = sqrt(pow(punto1.x-punto3.x,2)+pow(punto1.y-punto3.y,2));
	lado3 = sqrt(pow(punto3.x-punto2.x,2)+pow(punto3.y-punto2.y,2));
	area = sqrt(s*(s-lado1)*(s-lado2)*(s-lado3));
	return area;
}