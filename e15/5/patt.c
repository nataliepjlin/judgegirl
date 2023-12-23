#include<stdio.h>
#include<stdlib.h>
// #define debug
#define SIZE 10
int main(){
    int n, k, m, d;//k*k pattern in n*n matrix, d->diff, m->mismatch
    scanf("%d%d%d%d", &n, &k, &m, &d);
    int pattern[SIZE][SIZE], matrix[SIZE][SIZE];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            scanf("%d", &pattern[i][j]);
        }
    }

    int ansr = -1, ansc = -1;
    for(int r = 0; (r + k - 1) < n; r++){//check pattern by moving downward
        for(int c = 0; (c + k - 1) < n; c++){//check pattern by moving right
            #ifdef debug
            printf("\n###(r, c) = (%d,%d)###\n", r, c);
            #endif
            int sumM = 0, sumP = 0, mis = 0;
            for(int ri = r; ri < r + k; ri++){
                for(int ci = c; ci < c + k; ci++){
                    #ifdef debug
                    printf("(ri, ci) = (%d,%d)\n", ri, ci);
                    #endif
                    sumM += matrix[ri][ci];
                    sumP += pattern[ri - r][ci - c];
                    mis += (matrix[ri][ci] != pattern[ri - r][ci - c]);
                }
            }
            if(abs(sumM - sumP) <= d && mis <= m
            && ((r > ansr) || (r == ansr && c > ansc))){
                ansr = r, ansc = c;
                #ifdef debug
                printf("sumM = %d, sumP = %d, abs(sumM - sumP) = %d, ", sumM, sumP, abs(sumM - sumP));
                printf("d = %d\nmis = %d, m = %d\n", d, mis, m);
                printf("set (ansr, ansc) to (%d, %d)\n", ansr, ansc);
                #endif
            }
        }
    }
    printf("%d %d\n", ansr, ansc);
    return 0;
}