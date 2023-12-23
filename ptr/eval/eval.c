#include<stdio.h>
#define debug
int evaluate_f(int *iptr[], int n, int *index){
    //4x-6y
    int max = 0;
    *index = -1;
    for(int i = 0; i < n; i++){
        int val = 4 * iptr[i][0] - 6 * iptr[i][1];
        #ifdef debug
        printf("x = %d y = %d\n", *iptr[i], *(iptr[i] + 1));
        printf("x = %d, y = %d, val = %d\n", iptr[i][0], iptr[i][1], val);
        #endif
        if(*index == -1 || max < val){
            max = val;
            *index = i;
        }
    }
    return max;
}