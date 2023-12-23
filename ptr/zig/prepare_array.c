#include<stdio.h>
// #define debug
void prepare_array(int buffer[], int *array[], int row, int column[]){
    int sum = 0;
    for(int r = 0; r < row; r++){
        array[r] = &buffer[sum];
        sum += column[r];
        #ifdef debug
        printf("array[%d] = buffer[%d]\n", r, sum);
        #endif
    }
}