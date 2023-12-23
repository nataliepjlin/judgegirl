#include<stdio.h>
#define MAXN 20
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
void put(int bagw, int maxw, int *bagV, int tmpV, int weights[], int values[], int idx, int n){
    if(bagw > maxw) return;
    *bagV = max(*bagV, tmpV);
    if(idx == n) return;
    put(bagw + weights[idx], maxw, bagV, tmpV + values[idx], weights, values, idx + 1, n);
    put(bagw, maxw, bagV, tmpV, weights, values, idx + 1, n);
}
int main(){
    int n, maxw;
    int weights[MAXN], values[MAXN];
    scanf("%d%d", &n, &maxw);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &weights[i], &values[i]);
    }
    int bagV = 0;
    put(0, maxw, &bagV, 0, weights, values, 0, n);
    printf("%d\n", bagV);
    return 0;
}