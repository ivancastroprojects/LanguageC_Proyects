
struct Coche {   
    float precio;   
    char modelo[100];   
    int anyo_matriculacion; 
}; 

struct Coche *c;

for (i=0;i<num_coches;i++) {   
    printf(“Introduzca el modelo del coche %d”, i+1);
    fgets((c+i)->modelo, 100, stdin);
    printf(“Introduzca el precio del coche %d”, i+1); 
    scanf("%d", &(c+i)->precio);
    printf(“Introduzca el año de matriculación del coche %d”, i+1);
    scanf("%d", &(c+i)->anyo_matriculacion);
}