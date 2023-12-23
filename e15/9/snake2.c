#include<stdio.h>
// #define debug
int snake(int *ptr, int *row, int *column){
    int sum = 1;
    for(int i = 1; ptr[i] != 0; i++){
        sum ++;
    }
    #ifdef debug
    printf("sum = %d\n", sum);
    #endif
    *row = 1;
    *column = sum / *row;
    #ifdef debug
    printf("init row = %d, col = %d\n", *row, *column);
    #endif
    while(*column >= 2){
        int valid = (*row * *column == sum);
        int breakR = -1, breakC = -1;
        for(int r = 0; r < *row; r++){
            for(int c = 0; c < *column && valid; c++){
                #ifdef debug
                printf("val should be %d, ", r * (*column) + (((*column - 1) - c) * (r % 2 == 1) + c * (r % 2 == 0)));
                printf("ptr val = %d\n", ptr[r * (*column) + c]);
                #endif
                valid = (ptr[r * (*column) + c] 
                == r * (*column) + (((*column - 1) - c) * (r % 2 == 1) + c * (r % 2 == 0)));
                breakR = r, breakC = ((*column - 1) - c) * (r % 2 == 1) + c * (r % 2 == 0);
            }
        }
        if(valid) return 1;
        else if(breakR > 1 || breakR == 1 && breakC < *column - 1){
            *row = breakR;
            *column = breakC;
            return 0;
        } 
        *row += 1;
        *column = sum / *row;
        #ifdef debug
        printf("new row = %d, col = %d\n\n", *row, *column);
        #endif
    }//while
}