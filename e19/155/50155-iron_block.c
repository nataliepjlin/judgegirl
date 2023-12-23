#include<stdio.h>
int main(){
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    if(d && (e <= a) && (f <= b)){
        if (e == a && f == b && g >= c){
            d = 0;
        }
        else{
            if(g > c) g = c;
            d += (e * f * g) / (a * b);
            if(d > c) d = c;
        }
    }
    printf("%d\n", d);
    return 0;
}