#include<stdio.h>
void f(int l, int hx, int hy, int x, int y){
    if(l <= 0)
        return;
    #ifdef debug
    printf("hx, hy = %d, %d, x, y = %d, %d\n", hx, hy, x, y);
    #endif
    int xx = (x - hx <= 0), yy = (y - hy <= 0);
    int ty[2][2] = {{4, 2}, {3, 1}};
    #ifdef debug
    printf("ty[%d][%d] = %d\n", xx, yy, ty[xx][yy]);
    #endif
    printf("%d %d %d\n", ty[xx][yy], x, y);

    int nl = l / 2;
    int dx[] = {1, -1, 1, -1};
    int dy[] = {1, 1, -1, -1};
    int hdx[] = {0, -1, 0, -1};
    int hdy[] = {0, 0, -1, -1};
    for(int i = 0; i < 4; i++){
        if(ty[xx][yy] - 1 == i){
            f(nl, hx, hy, x + nl * dx[i], y + nl * dy[i]);
        }
        else{
            f(nl, x + hdx[i], y + hdy[i], x + nl * dx[i], y + nl * dy[i]);
        }
    }
    return;
}
int main(){
    int l, hx, hy;
    scanf("%d%d%d", &l, &hx, &hy);
    f(l / 2, hx, hy, l / 2, l / 2);
}