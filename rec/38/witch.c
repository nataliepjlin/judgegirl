#include<stdio.h>
int make(int d, int a, int b, int c, int A, int B, int C, int power){
    if(a < 0 || b < 0 || c < 0
    || power < 0 || power > d)
        return 0;
    if(power == d
    || make(d, a - 1, b, c, A, B, C, power + A)
    || make(d, a, b - 1, c, A, B, C, power + B)
    || make(d, a, b, c - 1, A, B, C, power + C))
        return 1;
    return 0;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int d, a, b, c, A, B, C;
        scanf("%d%d%d%d%d%d%d", &d, &a, &b, &c, &A, &B, &C);
        int success = make(d, a, b, c, A, B, C, 0);
        if(success)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}