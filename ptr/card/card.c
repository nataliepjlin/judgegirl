#include<stdio.h>
#define SIZE 10000
// #define debug
void print(int *deck[]){
    int i = 0;
    for(i; deck[i] != NULL; i++){
        if(i) printf(" ");
        printf("%d", *deck[i]);
    }
    if(i) printf("\n");
}
void shuffle(int *deck[]){
    int idx = 0;
    int *tmp[SIZE];
    while(deck[idx] != NULL) idx ++;
        if(idx){
            int mid = idx / 2 + (idx % 2);
        #ifdef debug
        printf("idx = %d, mid = %d\n", idx, mid);
        #endif
        int i = 0;
        for(int t = 0; t < idx; t++){
            if(t % 2){
                tmp[t] = deck[mid];
                mid ++;
            }
            else{
                tmp[t] = deck[i];
                i ++;
            }
        }
        #ifdef debug
        print(tmp);
        #endif
        for(int i = 0; i < idx; i++){
            deck[i] = tmp[i];
        }
    }
}
