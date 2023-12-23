#include<stdio.h>
#define DEBUG
int max(int a, int b){
    return (a > b) ? (a) : (b);
}
void neg_check(int *neg, int *len, int k){
    if(*neg != 0){
        if(*neg == k && *len != 0) 
            *len += 1;
        else *len = 0;
    }
    #ifdef DEBUG
    printf("neg = %d, len = %d\n", *neg, *len);
    #endif
    *neg = 0;
}
void pos_check(int *pos, int *len, int k, int *max_val){
    if(*pos != 0){
        if(*pos > k) *len = 1;//starting a new seq
        else if(*pos == k){
            #ifdef DEBUG
            printf("set len from %d ", *len);
            #endif
            *len += 1;
            #ifdef DEBUG
            printf("to %d\n", *len);
            #endif
        }
        else *len = 0;
    }
    // else{
    //     #ifdef DEBUG
    //     printf("set len from %d to 0\n", *len);
    //     #endif
    //     *len = 0;
    // } 
    *max_val = max(*max_val, *len);
    #ifdef DEBUG
    printf("pos = %d, len = %d, now max_val = %d\n", *pos, *len, *max_val);
    #endif
    *pos = 0;
}
int main(){
    int k, n; 
    int pos = 0, neg = 0, len = 0, max_val = 0;
    scanf("%d", &k);
    
    while(scanf("%d", &n) && n){
        #ifdef DEBUG
        printf("\nn = %d\n", n);
        #endif
        if(n > 0){
            neg_check(&neg, &len, k);
            pos++;
        }
        else{
            pos_check(&pos, &len, k, &max_val);
            neg++;
        }
    }

    pos_check(&pos, &len, k, &max_val);
    if(max_val == 1) max_val = 0;
    printf("%d\n", max_val * k);
    return 0;
}