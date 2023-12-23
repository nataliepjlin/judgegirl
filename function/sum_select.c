#include<stdio.h>
int facto(int n){
    int f = 1;
    for(int i = n; i > 0; i --){
        f *= i;
    }
    // printf("denom = %d\n", f);
    return f;
}
int facton(int n, int nk){
    int f = 1;
    for(int i = n; i > nk; i--){
        f *= i;
    }
    // printf("multiply from %d to %d, nume = %d ", n, nk, f);
    return f;
}
int cnk(int n, int k){
    return (n - k > k) ? (facton(n, n - k) / facto(k)) : (facton(n, k) / facto(n - k));
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = 0;
    for(int i = 0; i <= m; i++){
        sum += cnk(n, i);
        // printf("i = %d, now sum = %d\n\n", i, sum);
    }
    printf("%d\n", sum);
    return 0;
}