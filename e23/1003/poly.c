#include <stdio.h>
#define MAX 2000 + 1
// #define debug
void dividePolynomial(int f[], int g[]){
    #ifdef debug
    printf("\n%d times poly / %d times poly\n", f[0], g[0]);
    #endif
    for(int i = 1; i <= f[0] - g[0] + 1; i++){
        #ifdef debug
        printf("calculating %d/%d th quotient\n", i, f[0] - g[0] + 1);
        #endif
        f[i] /= g[1];
        for(int j = 1; j < g[0] + 1; j++){//1 + (g[0] + 1) elements in g
            #ifdef debug
            printf("i + j = %d, j + 1 = %d\n", i, j + 1);
            #endif
            f[i + j] -= (f[i] * g[j + 1]);
        }
    }
    int initG0 = g[0];
    if(!g[0]){
        g[0] = 0;
        g[1] = 0;
    }
    else{
        int start = (f[0] + 1) - (g[0] - 1);
                    //push to constant, go back g[0] - 1
        #ifdef debug
        printf("init start = %d\n", start);
        #endif
        g[0] --;
        while(!f[start] && start < f[0] + 1 && g[0] > 0){
            start ++;
            g[0] --;
        }
        #ifdef debug
        printf("g[0] = %d, f[%d] = %d\n", g[0], start, f[start]);
        #endif
        for(int idx = 1; idx <= g[0] + 1; idx ++){
            g[idx] = f[start];
            start ++;
        }
    }
    f[0] -= initG0;
}
 
