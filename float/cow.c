#include<stdio.h>
#define pi 3.1415926
int main(){
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

    double area = c * c * pi * 3 / 4;
    if (c > b) area += (c - b) * (c - b) * pi * 1 / 4;
    if (c > a) area += (c - a) * (c - a) * pi * 1 / 4;
    printf("%f", area);
    return 0;
}