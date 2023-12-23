#include <stdio.h>
// #define DEBUG
void prepare_array(int buffer[], int *array[], int row, int column[]){
    int j = 0;
    for(int r = 0; r < row; r++){
        array[r] = &buffer[j];
        #ifdef DEBUG
        printf("r = %d, j = %d\n", r, j);
        #endif
        for(int c = 0; c < column[r]; c++){
            j ++;
        }
    }
}
int main() {
    int row = 4;
    int column[4] = {10, 20, 30, 10};
    int *array[50];
    int buffer[10000];
    prepare_array(buffer, array, row, column);
    for (int i = 0; i < 4; i++)
     for (int j = 0; j < column[i]; j++)
       array[i][j] = i * 100 + j;
    for (int i = 0; i < 4; i++)
     for (int j = 0; j < column[i]; j++)
       printf("%d%c",array[i][j], " \n"[j == column[i] - 1]);
    return 0;
}