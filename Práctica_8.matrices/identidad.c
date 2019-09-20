#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int i, j, m_identidad[3][3];

    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            
            if(m_identidad[i][j] = (i==j))
                m_identidad[i][j] = 1;

            else m_identidad[i][j] = 0;
            printf("%d\t", m_identidad[i][j]);
        }
        printf("\n");
    }

    return 0;
}


