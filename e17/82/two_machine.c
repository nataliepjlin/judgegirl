#include<stdio.h>
int max(int a, int b){
    return (a > b) ? (a) : (b);
}
int main(){
    int arriveTime = 0, timeOnA = 0, timeOnB = 0;
    int count = 0, time = 0;
    int readyA = 0, readyB = 0;
    while(scanf("%d%d%d", &arriveTime, &timeOnA, &timeOnB) == 3){
        readyA = max(arriveTime, readyA) + timeOnA; 
        readyB = max(readyB, readyA) + timeOnB;
        time = readyB;
        printf("%d\n", time);
    }
    return 0;
}