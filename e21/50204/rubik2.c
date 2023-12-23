#include<stdio.h>
// #define DEBUG
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int cube[n][n][n];
    for(int l = 0; l < n; l++){
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                cube[l][r][c] = l * (n * n) + r * n + c;
            }
        }
    }
    while(m --){
        int type, idx;
        scanf("%d%d", &type, &idx);
        if(type == 0){
            int tmp[n][n];
            for(int r = 0; r < n; r++){
                for(int c = 0; c < n; c++){
                    tmp[r][c] = cube[idx][r][c];
                }
            }

            for(int r = 0; r < n; r++){
                for(int c = 0; c < n; c++){
                    cube[idx][r][c] = tmp[(n - 1) - c][r];
                    
                }
            }
        }
        else{
            int tmp[n][n];
            for(int l = 0; l < n; l++){
                for(int r = 0; r < n; r++){
                    tmp[l][r] = cube[l][r][idx];
                    #ifdef DEBUG
                    printf("%d%c", tmp[l][r], " \n"[r == n - 1]);
                    #endif
                }
            }
            #ifdef DEBUG
            printf("\n");
            #endif

            for(int l = 0; l < n; l++){
                for(int r = 0; r < n; r++){
                    cube[l][r][idx] = tmp[(n - 1) - r][l];
                    #ifdef DEBUG
                    printf("%d%c", tmp[(n - 1) - r][l], " \n"[r == n - 1]);
                    #endif
                }
            }
            #ifdef DEBUG
            printf("\n");
            #endif
        }
    }
    for(int l = 0; l < n; l++){
        for(int r = 0; r < n; r++){//r-th row
            for(int c = 0; c < n; c++){//c-th col
                printf("%d%c", cube[l][r][c], " \n"[c == n - 1]);
            }
        }
    }
    return 0;
}