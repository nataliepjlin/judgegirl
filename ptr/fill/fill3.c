#include<stdio.h>
// #define debug
void fill_array(int *ptr[], int n){
    for(int *i = ptr[0]; i < ptr[n - 1]; i++){
        *i = 0;
    }
    for(int i = 0; i < n; i++){
        *ptr[i] = i;
    }
 
    int *temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(ptr[j] > ptr[j + 1]){
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
    int *left;
    int *right;
    left = ptr[0];
    right = ptr[1];
 
    int a = 1;
    int len = ptr[n - 1] - ptr[0];
    #ifdef debug
    printf("%d\n", len);
    #endif
    for(int i = 1; i <= len; i++){
        if(ptr[0][i] == 0){
            ptr[0][i] = *left + *right;
        }
        else{
            if(a == n - 1) break;
            left = ptr[a];
            right = ptr[a + 1];
            a++;
        }
    }
}