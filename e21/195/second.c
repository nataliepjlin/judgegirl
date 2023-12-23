#include<stdio.h>
#define debug
int main(){
    int maxlen[4] = {-1, -1, -1, -1}, prev[4] = {-1, -1, -1, -1};
    int maxidx[4] = {-1, -1, -1, -1}, maxidx2[4] = {-1, -1, -1, -1};
    int maxlen2[4] = {-1, -1, -1, -1};
    int n, count = 0;;
    while(scanf("%d", &n) != EOF){
        if(maxlen[n] <= (count - prev[n]) && (prev[n] != -1)){
            if(maxlen[n] != -1 && maxlen[n] < (count - prev[n])){
                maxlen2[n] = maxlen[n];//not the 1st max
                maxidx2[n] = maxidx[n];
            }  
            maxidx[n] = prev[n];
            maxlen[n] = (count - prev[n]);
        }
        else if(maxlen2[n] <= (count - prev[n]) && (prev[n] != -1)){
            maxidx2[n] = prev[n];
            maxlen2[n] = (count - prev[n]);
        }
        prev[n] = count;
        #ifdef debug
        printf("now maxlens: ");
        printf("%d, %d, %d\n", maxlen[1], maxlen[2], maxlen[3]);
        printf("now maxlen2s: ");
        printf("%d, %d, %d\n", maxlen2[1], maxlen2[2], maxlen2[3]);
        printf("prevs: ");
        printf("%d, %d, %d\n\n", prev[1], prev[2], prev[3]);
        #endif
        count ++;
    }
    printf("%d %d %d\n", maxlen2[1], maxidx2[1], maxidx2[1] + maxlen2[1]);
    printf("%d %d %d\n", maxlen2[2], maxidx2[2], maxidx2[2] + maxlen2[2]);
    printf("%d %d %d\n", maxlen2[3], maxidx2[3], maxidx2[3] + maxlen2[3]);
    return 0;
}