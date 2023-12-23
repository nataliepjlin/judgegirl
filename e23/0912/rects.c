#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int x1, y1, w1, h1;
    scanf("%d%d%d%d", &x1, &y1, &w1, &h1);
    int area = w1 * h1;
    int prevx = x1 + w1, prevy = y1 + h1;

    int xi, yi, wi, hi;
    for(int i = 1; i < n; i++){
        scanf("%d%d%d%d", &xi, &yi, &wi, &hi);

        area += wi * hi;
        area -= (xi - prevx) * (yi - prevy);

        prevx = xi + wi, prevy = yi + hi;
    }

    printf("%d\n", area);
    return 0;
}