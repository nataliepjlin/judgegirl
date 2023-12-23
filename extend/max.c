#include<stdio.h>
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
int main(){
    long long n;
    while(scanf("%lld", &n) == 1){
        int maxCons = 0, count = 0;
        while(n){
            int now = n % 2;
            count += (now);
            maxCons = max(maxCons, count);
            n /= 2;
        }
        printf("%d\n", maxCons);
    }
    return 0;
}