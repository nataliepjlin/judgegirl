#include<stdio.h>
#define debug
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
int checkNeg(int *neg, int *count, int k){
    if(*neg){
        if(*neg == k && *count){
            *count += 1;
        }
        else{
            *count = 0;
        }
    }
    #ifdef debug
    printf("count = %d\n", *count);
    #endif
    *neg = 0;
}
int checkPos(int *pos, int *count, int k, int *maxcount){
    if(*pos){
        if(*pos > k) *count = 1;
        else if(*pos == k){
            *count += 1;
        }
        else *count = 0;
    }
    *maxcount = max(*maxcount, *count);
    #ifdef debug
    printf("count = %d, max = %d\n", *count, *maxcount);
    #endif

    *pos = 0;
}
int main(){
    int k; scanf("%d", &k);
    int n, maxcount = 0;
    int pos = 0, neg = 0, count = 0;
    while(scanf("%d", &n) != EOF){
        #ifdef debug
        printf("\nn = %d\n", n);
        #endif
        if(n > 0){
            pos ++;
            checkNeg(&neg, &count, k);
        }
        else if(n < 0){
            neg ++;
            checkPos(&pos, &count, k, &maxcount);
        }
        else break;//n == 0
    }
    checkPos(&pos, &count, k, &maxcount);
    printf("%d\n", maxcount * k);
    return 0;
}