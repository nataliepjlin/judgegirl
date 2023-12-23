#include<stdio.h>
#define N 100001
void print(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d%c", arr[i], " \n"[i == size - 1]);
    }
}
void sort(int arr[], int size){
    print(arr, size);
    if(size == 1)
        return;
    int l = size / 2, r = size - l;
    int lefts[l], rights[r];
    for(int i = 0; i < l; i++){
        lefts[i] = arr[i];
    }
    for(int i = 0; i < r; i++){
        rights[i] = arr[l + i];
    }
    sort(lefts, l); sort(rights, r);
    int li = 0, ri = 0, i = 0;
    while(li < l || ri < r){
        if(li == l){
            arr[i++] = rights[ri++];
        }
        else if(ri == r){
            arr[i++] = lefts[li++];
        }
        else{//both have left
            if(lefts[li] < rights[ri]){
                arr[i++] = lefts[li++];
            }
            else{
                arr[i++] = rights[ri++];
            }
        }
    }
    print(arr, size);
}
int main(){
    int arr[N], n = 0;
    while(scanf("%d", &arr[n]) == 1)
        n++;
    sort(arr, n);
}