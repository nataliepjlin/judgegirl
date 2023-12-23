#include<stdio.h>
#include<stdint.h>
#define SIZE 32
// #define debug
void print(int arr[]){
    for(int i = 0; i < 32; i++){
        printf("%d%c", arr[i], "\0 "[(i + 1) % 4 == 0]);
    }
    printf("\n");
}
int checking(int arr[], int start, int len){
    int count = 0;
    for(int i = start; i < start + len; i++){
        count += (arr[i] == 1);
    }
    return (count % 2);
}
void X(int arr[SIZE], int start, int len){
    int tmp[SIZE] = {0}, idx = 0;
    for(int s = start; s < start + (len / 2); s++, idx++){
        tmp[idx] = arr[s];
        arr[s] = arr[s + (len / 2)];
    }
    idx = 0;
    for(int s = start + (len / 2); s < start + len; s++, idx++){
        arr[s] = tmp[idx];
    }
}
uint32_t bin2dec(int arr[]){
    uint32_t dec = 0;
    for(int i = 31; i >= 0; i--){
        dec += arr[31 - i] * (unsigned int)(1 << i);
    }
    return dec;
}
int main(){
    uint32_t n;
    int arr[SIZE] = {0};
    scanf("%u", &n);
    for(int i = 31; i >= 0; i--){
        arr[31 - i] = n / (unsigned int)(1 << i);
        n %= (unsigned int)(1 << i);
        #ifdef debug
        printf("%d", arr[31 - i]);
        if((32 - i) % 4 == 0 ) printf(" ");
        #endif
    }
    #ifdef debug
    printf("\n");
    #endif
    for(int len = 32; len >= 2; len /= 2){
        #ifdef debug
        printf("\nlen = %d\n", len);
        #endif
        for(int start = 0; start < 32; start += len){
            int check = checking(arr, start, len);
            #ifdef debug
            printf("start = %d, check = %d;\n", start, check);
            #endif
            if(check){
                X(arr, start, len);
                #ifdef debug
                print(arr);
                #endif
            }//check
        }//start
    }//len
    printf("%u\n", bin2dec(arr));
    return 0;
}