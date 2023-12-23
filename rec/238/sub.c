#include<stdio.h>
#define MAXN 15
int find(int arr[MAXN], int i, int n, int k, int sum){
    // printf("i = %d, sum = %d\n", i, sum);
    if(i == n - 1){
        // printf("i == n - 1\n\n");
        if(sum == k || sum + arr[i] == k) return 1;
        else return 0;
    }
    else{
        // printf("return find(arr, i + 1, n, k, sum) + find(arr, i + 1, n, k, sum + arr[i])\n\n");
        return find(arr, i + 1, n, k, sum) + find(arr, i + 1, n, k, sum + arr[i]);
    }
}
int main(){
    int n, arr[MAXN];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int k;
    while(scanf("%d", &k) == 1){
        printf("%d\n", find(arr, 0, n, k, 0));
    }
    return 0;
}