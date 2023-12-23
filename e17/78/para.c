#include<stdio.h>
int main(){
    int xa, ya, xb, yb, xc, yc;
    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
    int xd = (xb + xc) - xa,  yd = (yb + yc) - ya;
    int xe = (xa + xc) - xb,  ye = (ya + yc) - yb;
    int xf = (xa + xb) - xc,  yf = (ya + yb) - yc;
    printf("%d\n%d\n%d\n%d\n%d\n%d\n", xd, yd, xe, ye, xf, yf);
    return 0;
}