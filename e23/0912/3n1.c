#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    while(n != 1){
        if(n % 2) n = 3 * n + 1;
        else n /= 2;
        printf("%d\n", n);
    }
}