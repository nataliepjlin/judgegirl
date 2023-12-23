#include<stdio.h>
#define MAXK 128
#define MAXN 512
// #define debug
int main(){
    int in[MAXN][MAXN];
    int filter[MAXK][MAXK];
    int out[MAXN][MAXN] = {{0}};
    int n, k;
    scanf("%d%d", &n, &k);
    #ifdef debug
    printf("n = %d, k = %d\n", n, k);
    #endif
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &in[i][j]);
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            scanf("%d", &filter[i][j]);
        }
    }
    for(int i = 0; i < n - k + 1; i++){
        for(int j = 0; j < n - k + 1; j++){
            #ifdef debug
            printf("now processing (%d, %d)\n", i, j);
            #endif
            for(int r = 0; r < k; r++){
                for(int c = 0; c < k; c++){
                    out[i][j] += in[r + i][c + j] * filter[r][c];
                    #ifdef debug
                    printf("in[%d][%d] = %d\n", r + i, c + j, in[r + i][c + j]);
                    printf("filter[%d][%d] = %d\n", r, c, filter[r][c]);
                    printf("out[%d][%d] = %d\n\n", i, j, out[i][j]);
                    #endif
                }
            }//calcutating sum
            printf("%d%c", out[i][j], " \n"[j == n - k]);
        }//out c
    }//out r
}