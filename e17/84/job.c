#include<stdio.h>
#define MAXM 500
#define MAXJ 500
#define MAXT 500
// #define debug
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
int main(){
    int mCount, jCount;
    scanf("%d%d", &mCount, &jCount);
    int arriveTime[MAXJ], todo[MAXJ], total = 0;
    int taskTime[MAXJ][MAXT], taskMachine[MAXJ][MAXT];
    for(int j = 0; j < jCount; j++){
        scanf("%d%d", &arriveTime[j], &todo[j]);
        total += todo[j];
        for(int task = 0; task < todo[j]; task ++){
            scanf("%d%d", &taskMachine[j][task], &taskTime[j][task]);
            #ifdef debug
            printf("taskMachine[%d][%d] = %d, taskTime[%d][%d] = %d\n", j, task, taskMachine[j][task], j, task, taskTime[j][task]);
            #endif
        }
    }
    #ifdef debug
    printf("total = %d\n", total);
    #endif
    int idx[MAXJ] = {0}, machineTime[MAXM] = {0};
    for(int t = 0; t < total; t++){
        int minTime = 1000000, minJ = -1;
        for(int j = 0; j < jCount; j++){
            if(idx[j] == todo[j]) continue;
            int time = max(arriveTime[j], machineTime[taskMachine[j][idx[j]]]) \
             + taskTime[j][idx[j]];
             #ifdef debug
             printf("time %d = %d\n", j, time);
             #endif
             if(minTime > time){
                minTime = time;
                minJ = j;
             }
        }
        arriveTime[minJ] = machineTime[taskMachine[minJ][idx[minJ]]] = minTime;
        idx[minJ] ++;
        #ifdef debug
        printf("minTime = %d, minJ = %d\n", minTime, minJ);
        printf("arrive[0] = %d, arrive[1] = %d, arrive[2] = %d\n", arriveTime[0], arriveTime[1], arriveTime[2]);
        printf("idx[0] = %d, idx[1] = %d, idx[2] = %d\n\n", idx[0], idx[1], idx[2]);
        #endif
    }
    for(int j = 0; j < jCount; j++){
        printf("%d\n", arriveTime[j]);
    }
    return 0;
}