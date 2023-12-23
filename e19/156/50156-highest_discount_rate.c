#include<stdio.h>
int main(){
    int a, b, v, w, x, y, z;
    int max_rate_denom = -1, max_rate_nume = -1;// def: d/p
    int d;
    scanf("%d%d%d%d%d%d%d", &a, &b, &v, &w, &x, &y, &z);
    if(!v && !w && !x && !y && !z) max_rate_denom = 1;
    else{
        for(int p = a; p < b; p++){
            d = (p%2)? v: w;
            // printf("p = %d, d=%d\n", p, d);
            if((max_rate_denom == -1 && max_rate_nume == -1) || (d * max_rate_denom > max_rate_nume * p)){
                max_rate_nume = d;
                max_rate_denom = p;
                // printf("set max_rate_denom = %d\n", max_rate_denom);
            }
        }

        for(int p = b; p < (b + 4); p++){
            if(p % 3 == 0){
                d = x;
            }
            else if(p % 3 == 1){
                d = y;
            }
            else{
                d = z;
            }
            // printf("p = %d, d=%d\n", p, d);
            if(d * max_rate_denom > max_rate_nume * p){
                max_rate_nume = d;
                max_rate_denom = p;
                // printf("set max_rate_denom = %d\n", max_rate_denom);
            }
        }
    }
    printf("%d\n", max_rate_denom);
    return 0;
}

