#include <stdio.h>
#define MAXN 256
// #define debug
int max(int a, int b){
    return (a > b) * a + (a <= b) * b;
}
int findLength (int array[][256], int N, int r, int c, int dr, int dc){
    int maxlen = 0, len = (array[r][c] == 1);
    maxlen = max(maxlen, len);
    while(0 < r + dr && r + dr < N 
    && 0 < c + dc && c + dc < N){
        len += (array[r + dr][c + dc] == 1);
        len *= (array[r + dr][c + dc] == 1);
        maxlen = max(maxlen, len);
        r += dr, c += dc;
    }
    #ifdef debug
    printf("tmp maxlen = %d\n", maxlen);
    #endif
    return maxlen;
}
int main () {
    int array[MAXN][MAXN];
    int N, r, c;
    int direction[4][2] = {{1,0}, {1,1}, {0,1}, {-1,1}};//d, d+r, r, u+r
    int maxlen = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &array[i][j]);
        }
    }
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            for (int k = 0; k < 4; k++){
                maxlen = max(findLength(array, N, r, c, direction[k][0], direction[k][1]),
                maxlen);
            }
        }
    }
            
    printf("%d\n", maxlen);
    return 0;
}