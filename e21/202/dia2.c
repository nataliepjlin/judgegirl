#include<stdio.h>
// #define debug
#define MAX 200
int max(int a, int b){
    return (a > b) * a + (a <= b) * b;
}
int main(){
    int row, col, size;
    int arr[MAX][MAX] = {{0}};
    scanf("%d%d%d", &row, &col, &size);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int maxsum = 0;
    for(int i = size - 1; i + size - 1 < row; i ++){
        for(int j = size - 1; j + size - 1 < col; j ++){
            int tmp = 0;
            #ifdef debug
            printf("\nj = %d\n", j);
            #endif
            for(int k = 0; k < size - 1; k++){
                #ifdef debug
                printf("k = %d\n", k);
                printf("%d %d\n", i + k, j - (size - 1) + k);//right down
                printf("%d %d\n", i - k, j + (size - 1) - k);//left up
                printf("%d %d\n", i - (size - 1) + k, j - k);//left down
                printf("%d %d\n", i + (size - 1) - k, j + k);//right up
                #endif
                tmp += arr[i + k][j - (size - 1) + k];
                tmp += arr[i - k][j + (size - 1) - k];
                tmp += arr[i - (size - 1) + k][j - k];
                tmp += arr[i + (size - 1) - k][j + k];
            }
            maxsum = max(maxsum, tmp);
        }//check move right
    }//check move down
    printf("%d\n", maxsum);
    return 0;
}