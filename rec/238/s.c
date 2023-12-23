#include<stdio.h>
int getCount(int arr[], int sum, int n){
    if(sum == 0)
        return 1;
    if(n == 0 || sum < 0)
        return 0;
    return getCount(arr + 1, sum - arr[0], n - 1) + getCount(arr + 1, sum, n - 1);
}
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int k;
    while(scanf("%d", &k) == 1){
        printf("%d\n", getCount(arr, k, n));
    }
}