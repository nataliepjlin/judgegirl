#include<stdio.h>
#define MAX 200
// #define debug
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
void printSun(int sun[MAX][MAX], int N, int M
, int x, int y, int L, int W){
    for(int r = N - 1; r >= 0; r--){
        for(int c = 0; c < M; c++){
            if(y <= r && r < y + L && x <= c && c < x + W)
                printf("0");
            else
                printf("%d", sun[r][c]);
            printf("%c", " \n"[c == M - 1]);
        }
    }
    printf("\n");
}
int main(){
    int N, M, L, W, x, y, s, k;
    int sun[MAX][MAX] = {{0}};
    scanf("%d%d%d%d%d%d%d%d", &N, &M, &L, &W, &x, &y, &s, &k);
    for(int r = N - 1; r >= 0; r--){
        for(int c = 0; c < M; c++){
            scanf("%d", &sun[r][c]);
        }
    }
    int stepX = (x - M) / s + 1;
    int stepY = (y - N) / s + 1;
    int step = max(0, max(stepX, stepY));
    #ifdef debug
    printf("step = %d\n", step);
    #endif
    x -= s * step;
    y -= s * step;
    for(step; step <= k && !(x + (W - 1) < 0 || y + (L - 1) < 0);
    step++, x -= s, y -= s){
        #ifdef debug
        printf("x = %d, y = %d\n", x, y);
        #endif
        printSun(sun, N, M, x, y, L, W);
    }
    return 0;
}