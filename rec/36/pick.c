#include<stdio.h>
// #define debug
int pick(int k, int n, int m, int arr[], int nowSum, int nowPick, int idx){
    #ifdef debug
    printf("pick(k, n, m, arr, %d, %d, %d)\n", nowSum, nowPick, idx);
    #endif
    if(idx == n || nowSum > m){
        #ifdef debug
        printf("\n");
        #endif
        return ((idx == n ) && (nowSum <= m) && (nowPick >= k));
    }
    return pick(k, n, m, arr, nowSum + arr[idx], nowPick + 1, idx + 1)
    + pick(k, n, m, arr, nowSum, nowPick, idx + 1);
}
int main(){
    int k, n, m;
    scanf("%d%d%d", &k, &n, &m);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d\n", pick(k, n, m, arr, 0, 0, 0));
}