#include<stdio.h>
// #define debug
void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384]){
    #ifdef debug
    printf("%d buckets, %d balls\n", N, M);
    #endif
    if(method == 0){
        #ifdef debug
        printf("method = %d\n",method);
        #endif
        for(int b = 0; b < M; b++){
            int found = 0;
            for(int buc = 0; buc < N && !found; buc ++){
                if(ball[b] <= bucket[buc]){
                    bucket[buc] -= ball[b];
                    result[b] = buc;
                    found = 1;
                }
            }
            if(!found) result[b] = -1;
            #ifdef debug
            printf("%d/%dth ball's bucket = %d\n", b, M, result[b]);
            #endif
        }
    }
    else if(method == 1){
        #ifdef debug
        printf("method = %d\n",method);
        #endif
        for(int b = 0; b < M; b++){
            int found = 0, minCap = -1, minCapBuc = -1;
            for(int buc = 0; buc < N; buc ++){
                #ifdef debug
                printf("%dth buc\n", buc);
                #endif
                if(ball[b] <= bucket[buc] 
                && (minCapBuc == -1 || minCap > (bucket[buc] - ball[b]))){
                    found = 1;
                    minCap = bucket[buc] - ball[b];
                    minCapBuc = buc;
                }
            }
            if(!found) result[b] = -1;
            else{
                bucket[minCapBuc] -= ball[b];
                result[b] = minCapBuc;
            }
            #ifdef debug
            printf("%d/%dth ball's bucket = %d\n\n", b, M, result[b]);
            #endif
        }
    }
    else if(method == 2){
        #ifdef debug
        printf("method = %d\n",method);
        #endif
        for(int b = 0; b < M; b++){
            int found = 0, maxCap = -1, maxCapBuc = -1;
            for(int buc = 0; buc < N; buc ++){
                if(ball[b] <= bucket[buc] 
                && (maxCapBuc == -1 || maxCap <= (bucket[buc] - ball[b]))){
                    found = 1;
                    maxCap = bucket[buc] - ball[b];
                    maxCapBuc = buc;
                }
            }
            if(!found) result[b] = -1;
            else{
                bucket[maxCapBuc] -= ball[b];
                result[b] = maxCapBuc;
            }
            #ifdef debug
            printf("%d/%dth ball's bucket = %d\n", b, M, result[b]);
            #endif
        }
    }
}