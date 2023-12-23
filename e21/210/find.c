#include<stdio.h>
void findRowAndColumn(int **ptr, int *Row, int *Col, int **start, int *ansRow, int *ansCol){
    for(int i = 0; ptr[i] != NULL; i++){
        int len = ptr[i] - start[i];
        ansRow[i] = len / Col[i];
        ansCol[i] = len % Col[i];
    }
}