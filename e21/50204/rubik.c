#include<stdio.h>
#define DEBUG
#define size 100

int main(){
    int n, m;
    int rot, idx;
    scanf("%d%d", &n, &m);
    int cube[2][size][size][size]; int now = 0, next = 1;
    for(int l = 0; l < n; l++){//l-th layer
        for(int r = 0; r < n; r++){//r-th row
            for(int c = 0; c < n; c++){//c-th col
                cube[next][l][r][c] = cube[now][l][r][c] = l * (n * n) + r * n + c;
            }
        }
    }//initializing cube
    int rot_count[size] = {0}, rot1_count[size] = {0};
    for(int round = 0; round < m; round ++){
        scanf("%d%d", &rot, &idx);
        if(rot == 0){
            for(int c = 0; c < n; c++){
                for(int r = n - 1; r >= 0; r--){
                    cube[next][idx][c][(n - 1) - r] = cube[now][idx][r][c];
                }
            }//l,r,c
            for(int l = 0; l < n; l++){
                if(l == idx) continue;
                for(int r = 0; r < n; r++){//r-th row
                    for(int c = 0; c < n; c++){//c-th col
                        cube[next][l][r][c] = cube[now][l][r][c];
                    }
                }
            }
        }
        else if(rot == 1){
            
            for(int l = n - 1; l >= 0; l--){
                for(int r = n - 1; r >= 0; r--){
                   cube[next][r][(n - 1) - l][idx] = cube[now][l][r][idx];
                   //c0~n, r0~n, ln~0; l r c
                }
            }
            for(int l = 0; l < n; l++){
                for(int r = 0; r < n; r++){//r-th row
                    for(int c = 0; c < n; c++){//c-th col
                        if(c == idx) continue;
                        cube[next][l][r][c] = cube[now][l][r][c];
                    }
                }
            }
        }
        now ^= 1, next ^= 1;
    }//round's for loop
    for(int l = 0; l < n; l++){
        for(int r = 0; r < n; r++){//r-th row
            for(int c = 0; c < n; c++){//c-th col
                printf("%d%c", cube[now][l][r][c], " \n"[c == n - 1]);
            }
        }
    }
    return 0;
}