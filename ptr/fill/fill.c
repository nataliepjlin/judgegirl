#include <stdio.h>
// #define debug
void fill_array(int *ptr[], int n){
    for(int *i = ptr[0]; i <= ptr[n - 1]; i++){
        *i = 0;
    }

    for(int i = 0; i < n; i++){
        *ptr[i] = i;
    }
    
    int len = (int) (ptr[n - 1] - ptr[0]);
    #ifdef debug
    printf("len = %d\n", len);
    #endif
    int *base = ptr[0];
    int prev = 0;
    for(int i = 1; i <= len; i++){
        #ifdef debug
        printf("*(base + %d) = %d\n", i, *(base + i));
        #endif
        if(*(base + i)){
            for(int j = prev + 1; j < i; j++){
                *(base + j) = *(base + prev) + *(base + i);
            }
            prev = i;
        }
    }
}