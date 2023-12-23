#include<stdio.h>
void fill(int l, int m, int type, int size, int x, int y){
    if((x > l - m && y > l - m) || !size)
        return;
    printf("%d %d %d\n", type, x, y);
    int newType[][4] = {{1, 2, 1, 4}, 
                        {3, 2, 1, 2}, 
                        {3, 2, 3, 4}, 
                        {3, 4, 1, 4}};
    int dx[] = {1, 1, -1, -1};
    int dy[] = {1, -1, -1, 1};
    for(int i = 0; i < 4; i++){
        fill(l, m, newType[type - 1][i], size >> 1, x + dx[i] * (size >> 1), y + dy[i] * (size >> 1));
    }
}
int main(){
    int l, m;
    scanf("%d%d", &l, &m);
    fill(l, m, 1, l >> 1, l >> 1, l >> 1);
}