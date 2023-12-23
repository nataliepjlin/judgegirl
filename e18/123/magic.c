#include<stdio.h>
#include<assert.h>
#define MAXN 1000
// #define debug
void printSquare(int square[MAXN][MAXN], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d%c", square[i][j], " \n"[j == n - 1]);
        }
    }
}
int main(){
    int square[MAXN][MAXN] = {{0}};
    int n, k;
    scanf("%d%d", &n, &k);
    // assert(k == 1);
    int r, c;
    scanf("%d%d", &r, &c);
    int initr = r, initc = c;
    square[r][c] = k;
    if(k != 1){
        for(int i = k - 1; i > 0; i--){
            #ifdef debug
            printf("i = %d\n", i);
            #endif
            int dr = 1,  dc = -1;
            if(square[(r + dr + n) % n][(c + dc + n) % n]){
                square[(r - 1) % n][c] = i;
                r = (r - 1) % n;
            }
            else{
                square[(r + dr + n) % n][(c + dc + n) % n] = i;
                r = (r + dr + n) % n;
                c = (c + dc + n) % n;
            }
            #ifdef debug
            printSquare(square, n);
            printf("now r = %d, c = %d\n", r, c);
            printf("\n");
            #endif
        }
        r = initr, c = initc;
        #ifdef debug
        printf("end of reversing\n");
        printf("\n");
        #endif
    }
    for(int i = k + 1; i <= n * n; i++){
        int dr = -1,  dc = 1;
        if(square[(r + dr + n) % n][(c + dc + n) % n]){
            square[(r + 1) % n][c] = i;
            r = (r + 1) % n;
        }
        else{
            square[(r + dr + n) % n][(c + dc + n) % n] = i;
            r = (r + dr + n) % n;
            c = (c + dc + n) % n;
        }
        #ifdef debug
        printSquare(square, n);
        printf("now r = %d, c = %d\n", r, c);
        printf("\n");
        #endif
    }
    printSquare(square, n);
    return 0;
}