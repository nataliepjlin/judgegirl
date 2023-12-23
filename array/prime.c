#include<stdio.h>
#include<assert.h>
#define ArraySize 101
int main(){
    int n;
    scanf("%d", &n);
    assert(n >= 2 && n < ArraySize);
    int prime[ArraySize];

    for(int i = 2; i < ArraySize; i++)
        prime[i] = 1;

    int j = 2;
    while(j * j <= n){
        while(!prime[j]) j ++;
        for(int i = 2 * j; i <= n; i += j){
            prime[i] = 0;
        }
        j ++;
    }
    for(int i = 2; i <= n; i++){
        if(prime[i]) printf("%d\n", i);
    }
}