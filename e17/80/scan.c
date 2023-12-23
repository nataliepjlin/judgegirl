#include<stdio.h>
#define MAX -10001
#define MIN 10001
// #define debug
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
int min(int a, int b){
    return a * (a < b) + b * (a >= b);
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int maxN = MAX, minN = MIN;
        int in, i;
        for(i = 0; i < n; i++){
            if(scanf("%d", &in) == EOF) break;
            #ifdef debug
            printf("%d of %d, in = %d\n", i, n, in);
            #endif
            maxN = max(maxN, in);
            minN = min(minN, in);
        }
        (i == n) ? printf("%d\n", maxN) : printf("%d\n", minN);
    }
    return 0;
}