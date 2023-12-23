#include<stdio.h>
void f(int l, int hx, int hy, int hz, int x, int y, int z){
    if(l == 1)
        return;

    l /= 2;
    if(hx < x + l && hy < y + l && hz < z + l){
        printf("8 %d %d %d\n", x + l, y + l, z + l);
        f(l, hx, hy, hz, x, y, z);
    }
    else f(l, x + l - 1, y + l - 1, z + l - 1, x, y, z);

    if(hx < x + l && hy >= y + l && hz < z + l){
        printf("6 %d %d %d\n", x + l, y + l, z + l);
        f(l, hx, hy, hz, x, y + l, z);
    }
    else f(l, x + l - 1, y + l, z + l - 1, x, y + l, z);

    if(hx >= x + l && hy < y + l && hz < z + l){
        printf("7 %d %d %d\n", x + l, y + l, z + l);
        f(l, hx, hy, hz, x + l, y, z);
    }
    else f(l, x + l, y + l - 1, z + l - 1, x + l, y, z);

    if(hx >= x + l && hy >= y + l && hz < z + l){
        printf("5 %d %d %d\n", x + l, y + l, z + l);
        f(l, hx, hy, hz, x + l, y + l, z);
    }
    else f(l, x + l, y + l, z + l - 1, x + l, y + l, z);

    if(hx < x + l && hy < y + l && hz >= z + l){
        printf("4 %d %d %d\n", x + l, y + l, z + l);
        f(l, hx, hy, hz, x, y, z + l);
    }
    else f(l, x + l - 1, y + l - 1, z + l, x, y, z + l);

    if(hx < x + l && hy >= y + l && hz >= z + l){
        printf("2 %d %d %d\n", x + l, y + l, z + l);
        f(l, hx, hy, hz, x, y + l, z + l);
    }
    else f(l, x + l - 1, y + l, z + l, x, y + l, z + l);

    if(hx >= x + l && hy < y + l && hz >= z + l){
        printf("3 %d %d %d\n", x + l, y + l, z + l);
        f(l, hx, hy, hz, x + l, y, z + l);
    }
    else f(l, x + l, y + l - 1, z + l, x + l, y, z + l);

    if(hx >= x + l && hy >= y + l && hz >= z + l){
        printf("1 %d %d %d\n", x + l, y + l, z + l);
        f(l, hx, hy, hz, x + l, y + l, z + l);
    }
    else f(l, x + l, y + l, z + l, x + l, y + l, z + l);
    
    return;
}
int main(){
    int l, hx, hy, hz;
    scanf("%d%d%d%d", &l, &hx, &hy, &hz);
    f(l, hx, hy, hz, 0, 0, 0);
}