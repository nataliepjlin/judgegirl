#include<stdio.h>
#include<stdlib.h>
// #define debug
int main(){
    int fuel = 0;
    int n; 
    scanf("%d", &n);
    int prev, now;
    scanf("%d%d", &prev, &now);
    int dir = 0;
    if(now - prev > 0){
        fuel = (now - prev) * 3;
        dir = 1;
    }
    else{
        fuel = (prev - now) * 2;
        dir = -1;
    }
    #ifdef debug
    printf("1st trans done, fuel = %d, dir = %d\n", fuel, dir);
    #endif
    prev = now;
    for(int i = 1; i < n - 1; i++){
        scanf("%d", &now);
        if(now - prev > 0){
            if(dir > 0) fuel += abs(now - prev) * 4;
            else fuel += abs(now - prev) * 3;
            dir = 1;
        }
        else{
            if(dir > 0) fuel += abs(now - prev) * 3;
            else fuel += abs(now - prev) * 2;
            dir = -1;
        }
        #ifdef debug
        printf("i = %d, now fuel = %d, dir = %d\n", i, fuel, dir);
        #endif
        prev = now;
    }
    printf("%d\n", fuel);
    return 0;
}