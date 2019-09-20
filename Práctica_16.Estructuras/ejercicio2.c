#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void inicializa(int*m, int nf, int nc);
float media(int*m, int nf, int nc);
char sacaletra(char*cad, int pos);

int main(int argc, char*argv[]){
	if (argc!=3){
		printf("error");
		return -1;
	}
	int *m, pos;
	float r;
	char cad[100], letra;
	srand(time(NULL));
	m=(int*)malloc(sizeof(int)*atoi(argv[1])*atoi(argv[2]));
	inicializa(m, atoi(argv[1]), atoi(argv[2]));
	r=media(m, atoi(argv[1]), atoi(argv[2]));
	printf("\nEl resultado es %f\n", r);
	printf("Introduce una cadena: ");
	fgets(cad, 100, stdin);
	do{
		printf("\nIntroduce una posición: ");
		scanf("%d", &pos);
		if(pos<1 || pos>99)
			printf("error");
	}while(pos<1 || pos >99);
	letra=sacaletra(cad, pos);
	printf("\nLa letra es %c\n", letra);
	free(m);
	return 0;
}
void inicializa(int*m, int nf, int nc){
	int i,j;
	for (i=0;i<nf;i++)
		for(j=0;j<nc;j++)
			*(m+i*nc+j)=rand()%5+3;
	return;
}
float media(int *m, int nf, int nc){
	int i,j;
	float resultado=0;
	for (i=0;i<nf;i++)
		for(j=0;j<nc;j++)
			resultado+=*(m+i*nc+j);
	return(resultado/(nf*nc));
}
char sacaletra(char*cad, int p){
	return (cad[p-1]);
}

