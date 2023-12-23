#include<stdio.h>
#include<stdlib.h>
void snake(const int *ptr_array[100][100], int m){
    int *tmp[100 * 100];
    for(int i = 0; i < m * m; i++){
        // tmp[i] = (int *) malloc(sizeof(int *));
        tmp[i] = ptr_array[i / m][i % m];
    }
    for(int i = 0; i < m * m; i++){
        for(int j = 0; j < m * m - i - 1; j++){
            if(*tmp[j] > *tmp[j + 1]){
                int *ptr = tmp[j];
                tmp[j] = tmp[j + 1];
                tmp[j + 1] = ptr;
            }
        }
    }
    for(int r = 0; r < m; r++){
        for(int c = 0; c < m; c++){
            if(r % 2){
                ptr_array[r][(m - 1) - c] = tmp[r * m + c];
            }
            else 
                ptr_array[r][c] = tmp[r * m + c];
        }
    }
}