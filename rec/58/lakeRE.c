#include<stdio.h>
#define SIZE 400
// #define debug
int in(int r, int c, int n, int m){
    return(r >= 0 && r < n && c >= 0 && c < m);
}
void count(int pic[SIZE][SIZE], int *lake, int r, int c, int n, int m){
    if(!in(r, c, n, m) || !pic[r][c])
        return;
    pic[r][c] = 0;
    *lake += 1;
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};
    /*
    can't be (-1, 0), (0, 1), (1, 0), (0, 1)
    not sure why...
    */
    for(int i = 0; i < 4; i++){
        count(pic, lake, r + dr[i], c + dc[i], n, m);
    }
    return;
}
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void bs(int result[], int r){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < r - i - 1; j++){
            if(result[j] < result[j + 1])
                swap(&result[j], &result[j + 1]);
        }
    }
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int pic[SIZE][SIZE];
    int result[SIZE * SIZE / 2 + 1], r = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &pic[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(pic[i][j]){
                result[r] = 0;
                count(pic, &result[r], i, j, n, m);
                #ifdef debug
                printf("result[%d] = %d\n", r, lake);
                #endif
                r++;
            }
        }
    }//for
    bs(result, r);
    for(int i = 0; i < r; i++){
        printf("%d\n", result[i]);
    }
}