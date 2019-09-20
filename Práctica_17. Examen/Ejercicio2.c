void intercambia(int m[100][100], int i, int j) {
    int t, aux;
    for(t=0; t<100; t++) {
        aux = m[i][t];
        m[i][t] = m[j][t];
        m[j][t] = aux;
    }
    return;
}