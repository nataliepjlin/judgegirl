#include<stdio.h>
void f(int l, int hx, int hy, int hz, int x, int y, int z, int ty[2][2][2]){
    if(l <= 0)
        return;
    int xx = (x - hx <= 0), yy = (y - hy <= 0), zz = (z - hz <= 0);
    int t = ty[xx][yy][zz];
    printf("%d %d %d %d\n", t, x, y, z);
    int dx[8] = {1, -1, 1, -1, 1, -1, 1, -1};
    int dy[8] = {1, 1, -1, -1, 1, 1, -1, -1};
    int dz[8] = {1, 1, 1, 1, -1, -1, -1, -1};
    int hdx[8] = {0, -1, 0, -1, 0, -1, 0, -1};
    int hdy[8] = {0, 0, -1, -1, 0, 0, -1, -1};
    int hdz[8] = {0, 0, 0, 0, -1, -1, -1, -1};
    int nl = l / 2;
    for(int i = 0; i < 8; i++){
        if(t - 1 == i){
            f(nl, hx, hy, hz, x + dx[i] * nl, y + dy[i] * nl, z + dz[i] * nl, ty);
        }
        else{
            f(nl, x + hdx[i], y + hdy[i], z + hdz[i], x + dx[i] * nl, y + dy[i] * nl, z + dz[i] * nl, ty);
        }
    }
    return;
}
int main(){
    int l, hx, hy, hz;
    scanf("%d%d%d%d", &l, &hx, &hy, &hz);
    int ty[2][2][2];
    ty[1][1][1] = 1, ty[0][1][1] = 2, ty[0][0][1] = 4, ty[1][0][1] = 3;
    ty[1][1][0] = 5, ty[0][1][0] = 6, ty[0][0][0] = 8, ty[1][0][0] = 7;
    f(l / 2, hx, hy, hz, l / 2, l / 2, l / 2, ty);
}