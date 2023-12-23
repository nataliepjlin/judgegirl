#include<stdio.h>
#include<math.h>
#define MAX 2048
int main(){
    int row, col;
    scanf("%d%d", &col, &row);
    char out[2][2];
    int result[col * row], idx = 0;
    scanf("%s%s", out[1], out[0]);
    unsigned int n;
    while(scanf("%u", &n) == 1 && idx < row * col){
        for(int i = 31; i >= 0 && idx < row * col; i--, idx ++){
            result[idx] = n / (unsigned int)(1 << i);
            // printf("%d", result[idx]);
            n %= (unsigned int)(1 << i);
        }
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%c", out[result[i * col + j]][0]);
        }
        printf("\n");
    }
}