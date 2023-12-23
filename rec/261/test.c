#include<stdio.h>
int convert(int arr[], int idx){
    if(idx == 4){
        for(int i = 0; i < 4; i++){
            printf("%d%c", arr[i], " \n"[i == 3]);
        }
        return 1;
    }
    for(int i = 0; i < 10; i++){
        arr[idx] = i;
        convert(arr, idx + 1);
    }
}
int main(){
    int arr[4] = {0};
    convert(arr, 0);
}