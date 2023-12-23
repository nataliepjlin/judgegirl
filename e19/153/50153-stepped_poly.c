#include<stdio.h>
int main(){
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    int w = a + c + e, h = b + d + f;
    int perimeter = w + h + a + b + c + d + e + f;
    int area = w * h - (w - a) * b - d * e;
    printf("%d\n%d\n", perimeter, area);
    return 0;
}