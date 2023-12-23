#include<stdio.h>
#define SIZE 50000
int main(){
    int n, points[SIZE][2] = {{0}};
    int nearest[SIZE] = {0}, nearestIdx = 0, minVal = -1;
    int nowminStartIdx = -1, nowminEndIdx = -1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &points[i][0], &points[i][1]);
    }
    int r, c;
    scanf("%d%d", &r, &c);
    for(int i = 0; i < n; i++){
        int dist = (points[i][0] - r) * (points[i][0] - r) 
                + (points[i][1] - c) * (points[i][1] - c);
        if(minVal == -1 || dist < minVal){
            minVal = dist;
            nearest[nearestIdx] = i;
            nowminStartIdx = nowminEndIdx = nearestIdx;
            nearestIdx ++;
        }
        else if(dist == minVal && minVal != -1){
            nearest[nearestIdx] = i;
            nowminEndIdx = nearestIdx;
            nearestIdx ++;
        }
    }
    for(int i = nowminStartIdx; i <= nowminEndIdx; i++){
        printf("%d\n", nearest[i]);
    }
    return 0;
}