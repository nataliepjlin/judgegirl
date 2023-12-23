#include<stdio.h>
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int in[512][512], filter[128][128], out[512][512] = {{0}};
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

    for(int r = 0; r < n - k + 1; r++){
       for(int c = 0; c < n - k + 1; c++){
            // printf("r = %d, c = %d\n", r, c);
            for(int ri = 0; ri < k; ri ++){
               for(int ci = 0; ci < k; ci ++){
                    // printf("filter[%d][%d] = %d\n", ri, ci, filter[ri][ci]);
                    // printf("in[%d][%d] = %d\n", r + ri, c + ci, in[r + ri][c + ci]);
                    out[r][c] += in[r + ri][c + ci] * filter[ri][ci];
                    // printf("now out[%d][%d] = %d\n\n", r, c, out[r][c]);
                } 
            }
            (c == 0)?printf("%d", out[r][c]) : printf(" %d", out[r][c]);
        } 
        printf("\n");
    }
    
}