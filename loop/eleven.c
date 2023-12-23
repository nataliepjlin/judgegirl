#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    int count = 0, sum1 = 0, sum2 = 0;
    while(scanf("%d", &n) != EOF){
        (count % 2) ? (sum1 += n) : (sum2 += n);
        count ++;
    }

    int diff = abs(sum1 - sum2);
    printf("%d\n", diff % 11 == 0);
    return 0;
}