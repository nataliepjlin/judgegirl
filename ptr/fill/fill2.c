#include <stdio.h>
// #define debug
void fill_array(int *ptr[], int n){
    for(int i = 0; i < n; i++){
        *ptr[i] = i;
    }
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(ptr[j] > ptr[j + 1]){
                int *tmp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < n - 1; i++){
        int len = ptr[i + 1] - ptr[i];
        for(int j = 1; j < len; j++){
            *(ptr[i] + j) = *(ptr[i + 1]) + *ptr[i];
        }
    }
}