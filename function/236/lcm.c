#include<stdio.h>
int gcd(int a, int b){
    if(a % b) return gcd(b, a % b);
    else return b;
}
int lcm(int a, int b){
    int g = gcd(a, b);
    return g * (a / g) * (b / g);
}
int main(){
    int input;
    int lcm_val = -1;
    while(scanf("%d", &input) != EOF){
        if(lcm_val == -1) lcm_val = input;
        else lcm_val = lcm(lcm_val, input);
    }
    printf("%d", lcm_val);
    return 0;
}
