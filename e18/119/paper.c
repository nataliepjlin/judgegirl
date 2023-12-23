#include<stdio.h>
// #define debug
int main(){
    int x, a, b, c;
    int y, d, e, f;
    int round;
    scanf("%d%d%d%d", &x, &a, &b, &c);
    scanf("%d%d%d%d", &y, &d, &e, &f);
    scanf("%d", &round);
    #ifdef debug
    printf("init x = %d, y = %d\n", x, y);
    #endif
    for(int r = 0; r < round; r++){
        int pick = 1, found = 0;
        while(!found){
            int xi = x % 3, yi = y % 3;//paper, scissors, stone
            if(xi == 0 && yi == 2 
            || xi == 1 && yi == 0
            || xi == 2 && yi == 1){
                printf("0 %d\n", pick);
                found = 1;
            }
            else if(yi == 0 && xi == 2 
            || yi == 1 && xi == 0
            || yi == 2 && xi == 1){
                printf("1 %d\n", pick);
                found = 1;
            }
            else{
                pick ++;
                x = (a * x + b) % c;
                y = (d * y + e) % f;
                #ifdef debug
                printf("x = %d, y = %d\n", x, y);
                #endif
            }
        }//!found
        x = (a * x + b) % c;
        y = (d * y + e) % f;
        #ifdef debug
        printf("x = %d, y = %d\n", x, y);
        #endif
    }
    return 0;
}