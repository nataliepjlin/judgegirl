#include<stdio.h>
int main(){
    int xmin = 10001, ymin = 10001, xmax = -10001, ymax = -10001;
    int x, y;
    while(scanf("%d%d", &x, &y) == 2){
        if(x > xmax) xmax = x;
        if(x < xmin) xmin = x;
        if(y > ymax) ymax = y;
        if(y < ymin) ymin = y;
    }
    printf("%d", (xmax - xmin) * (ymax - ymin));
    return 0;
}