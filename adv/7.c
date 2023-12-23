#include<stdio.h>
// #define debug
int main(){
    int n;
    while(scanf("%d", &n) == 1){
        int seg = 0;
        int prev, count = 1; 
        scanf("%d", &prev);
        int now;
        for(int i = 1; i < n; i++){
            scanf("%d", &now);
            seg += (prev != now);
            #ifdef debug
            printf("prev = %d, now = %d, seg = %d\n", prev, now, seg);
            #endif
            prev = now;
        }
        seg ++;
        printf("%d\n", seg);
    }
    return 0;
}