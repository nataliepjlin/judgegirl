int f(int x, int a, int b, int c){
    return (a * x + b) % c;
}
void count_collision(int *ptr[], int A[], int n, int a, int b, int c){
    for(int i = 0; i < c; i++){
        A[i] = -1;
    }
    for(int i = 0; i < n; i++){
        int idx = f(i, a, b, c);
        ptr[i] = &A[idx];
        A[idx] ++;
    }
    for(int i = 0; i < c; i++){
        A[i] += (A[i] == -1);
    }
}