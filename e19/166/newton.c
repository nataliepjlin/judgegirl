#include<stdio.h>
#define MAXD 11
double power(double base, int exp){
    double val = 1.0;
    for(int i = 0; i < exp; i++){
        val *= base;
    }
    return val;
}
int main(){
    int d;
    double coe[MAXD], dcoe[MAXD - 1];
    int k;
    double x;
    scanf("%d", &d);
    for(int i = 0; i < d; i++){
        scanf("%lf", &coe[i]);
        dcoe[i] = coe[i] * (d - i);
    }
    scanf("%lf", &coe[d]);
    scanf("%d", &k);
    scanf("%lf", &x);
    double slope, y;
    for(int round = 0; round < k; round ++){
        slope = y = 0.0;
        for(int i = 0; i < d; i++){
            slope += power(x, d - i - 1) * dcoe[i];
            y += power(x, d - i) * coe[i];
        }
        y += coe[d];
        printf("%.4f %.4f\n", x, y);
        x = x - y/slope;
    }
    return 0;
}