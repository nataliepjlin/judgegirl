#include<stdio.h>
#define MAXM 500
#define MAXJ 500
#define MAXT 100
#define MAXtime 1000000
#define debug
int max(int a, int b){
    return (a > b) ? (a) : (b);
}
int main(){
    int machines, jobs;
    int jobArrive[MAXJ] = {0},  todo[MAXJ] = {0};
    int machineForTask[MAXJ][MAXT] = {{0}}, timeForTask[MAXJ][MAXT] = {{0}};
    scanf("%d%d", &machines, &jobs);
    int total = 0;
    for(int j = 0; j < jobs; j++){
        scanf("%d%d", &jobArrive[j], &todo[j]);
        total += todo[j];
        for(int task = 0; task < todo[j]; task ++){
            scanf("%d%d", &machineForTask[j][task], &timeForTask[j][task]);
            #ifdef debug
            printf("machineForTask[%d][%d] = %d, ", j, task, machineForTask[j][task]);
            printf("timeForTask[%d][%d] = %d\n", j, task, timeForTask[j][task]);
            #endif
        }
    }//reading input

    #ifdef debug
    printf("total = %d\n", total);
    #endif
    int machineTime[MAXM] = {0};
    int nowTaskIdx[MAXJ] = {0};
    for(int t = 0; t < total; t++){
        int minidx = -1, minTime = MAXtime;
        for(int j = 0; j < jobs; j++){
            int tidx = nowTaskIdx[j];
            if(tidx == todo[j]) continue;
            int time = max(machineTime[machineForTask[j][tidx]], jobArrive[j]) + timeForTask[j][tidx];
            #ifdef debug
            printf("%dth job's %dth task's time = %d\n", j, tidx, time);
            #endif
            if(minTime > time){
                minidx = j;
                minTime = time;
            }
        }//finding minTime
        #ifdef debug
        printf("minidx = %d, minTime = %d\n", minidx, minTime);
        #endif
        machineTime[machineForTask[minidx][nowTaskIdx[minidx]]] = jobArrive[minidx] = minTime;
        nowTaskIdx[minidx] ++;
    }
    for(int j = 0; j < jobs; j++){
        printf("%d\n", jobArrive[j]);
    }
    return 0;
}