void inicializa(int *v, int n) {
    int i, j, num, repetido = 0;

    for(i=0; i<n; i++) {
        num = rand()%50 +1;
        repetido = 0;
        for(j=0; j<i; j++) {
            if(v[j] == num) {
                repetido = 1;
                break;
            }
        }
        if(repetido == 0)
            v[i] = num;
        else i--;
    }
    return;
}
