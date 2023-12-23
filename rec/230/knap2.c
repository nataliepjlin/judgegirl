#include<stdio.h>
#define MAXN 20
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
int getMaxVal(int maxw, int values[], int weights[], int idx, int n){
    if(idx >= n)
        return 0;
    if(weights[idx] > maxw)
        return getMaxVal(maxw, values, weights, idx + 1, n);
    return max(getMaxVal(maxw, values, weights, idx + 1, n), 
    getMaxVal(maxw - weights[idx], values, weights, idx + 1, n) + values[idx]);
}
int main(){
    int n, maxw;
    scanf("%d%d", &n, &maxw);
    int values[MAXN], weights[MAXN];
    for(int i = 0; i < n; i++){
        scanf("%d%d", &weights[i], &values[i]);
    }
    printf("%d\n", getMaxVal(maxw, values, weights, 0, n));
    return 0;
}