#include <stdio.h>
int funcion (int* b, int v[2], int a);
int main (){
	int a, *b, e[2]={1,2};
 	a=4; b=&a; 
	e[0]=funcion(&a, e, e[1]);
	printf("a=%d, b=%d, e[0]=%d, e[1]=%d", a, *b, e[0], e[1]);
	return 0;
}
int funcion (int* b, int v[2], int a){
	*b=7;
	v[0]=5;
	a=20;
	return *b;
}

