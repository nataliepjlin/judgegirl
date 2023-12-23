#include<stdio.h>
#include<stdlib.h>
// #define debug
#define MAX 100
int check(int c1, int r1, int c2, int r2){
    return (c1 == c2 || r1 == r2 || abs(c1 - c2) == abs(r1 - r2));
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void sort(int *c1, int *r1, int *c2, int *r2){
    if(*c1 == *c2 && *r1 > *r2) swap(r1, r2);
    else if(*r1 == *r2 && *c1 > *c2) swap(c1, c2);
    else if(abs(*r1 - *r2) == abs(*c1 - *c2)
    && (*r1 > *r2)){
        swap(r1, r2);
        swap(c1, c2);
    } 
}
int main(){
    int L, row, col, n;
    scanf("%d%d%d", &L, &row, &col);
    int map[MAX][MAX] = {{0}};
    for(int l = 1; l <= L; l++){
        scanf("%d", &n);
        int c1, r1, c2, r2;
        scanf("%d%d", &c1, &r1);
        for(int i = 2; i <= n; i++){
            scanf("%d%d", &c2, &r2);
            int initc2 = c2, initr2 = r2;
            #ifdef debug
            printf("init: (%d, %d) ~ (%d, %d)\n", r1, c1, r2, c2);
            #endif
            if(!check(c1, r1, c2, r2)){
                printf("ERROR %d %d\n", l, i);
                return 0;
            }
            sort(&c1, &r1, &c2, &r2);
            #ifdef debug
            printf("sorted: (%d, %d) ~ (%d, %d)\n", r1, c1, r2, c2);
            #endif
            if(r1 == r2){
                for(int c = c1; c <= c2; c++){
                    map[r1][c] = 1;
                }
            }
            else if(c1 == c2){
                for(int r = r1; r <= r2; r++){
                    map[r][c1] = 1;
                }
            }
            else{
                for(int i = 0; i + r1 <= r2; i++){
                    if(c1 < c2)  map[r1 + i][c1 + i] = 1; 
                    else map[r1 + i][c1 - i] = 1; 
                }
            }
            c1 = initc2, r1 = initr2;
        }
    }
    #ifdef debug
    printf("row = %d, col = %d\n", row, col);
    #endif
    for(int r = row - 1; r >= 0; r--){
        for(int c = 0; c < col; c++){
            printf("%d", map[r][c]);
        }
        printf("\n");
    }
    return 0;
}