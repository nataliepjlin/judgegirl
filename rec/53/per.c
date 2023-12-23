#include<stdio.h>
#define MAXN 10
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void bs(int n, int arr[MAXN]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void perm(int arr[], int idx, int n, int print[], int used[]){
    if(idx == n){
        for(int i = 0; i < n; i++){
            printf("%d%c", print[i], " \n"[i == n - 1]);
        }
        return;
    }
    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        used[i] = 1;
        print[idx] = arr[i];
        perm(arr, idx + 1, n, print, used);
        used[i] = 0;
    }
}
int main(){
    int n, arr[MAXN], used[MAXN] = {0}, print[MAXN];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    } 
    bs(n, arr);
    perm(arr, 0, n, print, used);
}