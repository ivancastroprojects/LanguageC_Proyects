#include <stdio.h>
#include <stdlib.h>

int main() {

    int numSeg;
    int dias = 0;
    int horas = 0;
    int minutos = 0;
    int segundos = 0;

    printf("Escribe una cantidad de segundos: ");
    scanf("%d", &numSeg);

    if(numSeg > 59) {
        segundos = numSeg%60;
        minutos = numSeg/60;
       
        
        if(minutos > 59) {
            minutos = horas%60;
            horas = numSeg/3600;
            

            if(horas > 23) {
                horas = dias%60;
                dias = numSeg/86400;
                
            }
        }
    }

    printf("Total: %d días, %d horas, %d minutos, %d segundos\n", dias, horas, minutos, segundos);
    return 0;

}