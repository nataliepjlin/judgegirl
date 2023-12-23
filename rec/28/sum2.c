#include<stdio.h>
// #define debug
int square(int n){
    #ifdef debug
    printf("now n = %d\n", n);
    #endif
    if(!n)
        return 0;
    return square(n - 1) + n * n;
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", square(n));
    return 0;
}