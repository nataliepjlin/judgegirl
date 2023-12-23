#include<stdio.h>
void pick(int k, int n, int m, int *count,
int nowsum, int nowpick, int arr[], int idx){
    if(nowsum > m || idx == n){
        *count += (nowpick >= k && nowsum <= m);
        return;
    }
    pick(k, n, m, count, nowsum, nowpick, arr, idx + 1);
    pick(k, n, m, count, nowsum + arr[idx], nowpick + 1, arr, idx + 1);
}
int main(){
    int k, n, m;
    scanf("%d%d%d", &k, &n, &m);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int count = 0;
    pick(k, n, m, &count, 0, 0, arr, 0);
    printf("%d\n", count);
}