#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #define debug
#define SIZE 512
void bs(int *out[SIZE], int count[SIZE], int idx){
    for(int i = 0; i < idx; i++){
        for(int j = 0; j < idx - i - 1; j++){
            if(count[j] > count[j + 1]
            || (count[j] == count[j + 1] && *out[j] > *out[j + 1])){
                int tmp = count[j];
                count[j] = count[j + 1];
                count[j + 1] = tmp;

                int *ptr = out[j];
                out[j] = out[j + 1];
                out[j + 1] = ptr;
            }
        }
    }
}
void count(int **p[]){
    int *out[SIZE], idx = 0;
    for(int i = 0; i < SIZE; i++){
        out[i] = (int *) malloc(sizeof(int *));
    }
    int count[SIZE] = {0};
    for(int i = 0; p[i] != NULL; i++){
        #ifdef debug
        printf("val = %d\n", **p[i]);
        #endif
        int j = 0, found = 0;
        for(j; j < idx && !found; j++){
            found = (out[j] == *p[i]);
        }
        j -= found;
        out[j] = *p[i];
        count[j] ++;
        idx += (!found);
        #ifdef debug
        printf("*out[%d] = %d, count[%d] = %d\n", j, *out[j], j, count[j]);
        #endif
    }
    bs(out, count, idx);
    for(int i = 0; i < idx; i++){
        printf("%d %d\n", *out[i], count[i]);
    }
}