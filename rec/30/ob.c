#include<stdio.h>
#define MAX 13
int count(int r, int c, int map[MAX][MAX]){
    #ifdef debug
    printf("(%d, %d)\n", r, c);
    #endif
    if(!map[r][c])
        return 0;
    if(r == 1 && c == 1)
        return 1;
    if(r == 1)
        return count(r, c - 1, map);
    if(c == 1)
        return count(r - 1, c, map);
    return count(r - 1, c, map) + count(r, c - 1, map);
}
int main(){
    int r, c;
    scanf("%d%d", &r, &c);
    int map[MAX][MAX];
    for(int i = r; i >= 1; i--){
        for(int j = 1; j <= c; j++){
            scanf("%d", &map[i][j]);
        }
    }
    printf("%d\n", count(r, c, map));
}