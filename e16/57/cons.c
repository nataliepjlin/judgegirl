#include<stdio.h>
#include<stdint.h>
#define N 10001
int printPad(int pad){
    for(int p = 0; p < pad; p++){
        printf(" ");
    }
    return 1;
}
int main(){
    int n;
    uint32_t num;
    scanf("%d", &n);
    int prev = -1;
    int pad = 0;
    for(int i = 0; i < n; i++){
        scanf("%u", &num);
        for(int j = 31; j >= 0; j--){
            int now = ((num & (uint32_t)1 << j) != 0);
            (prev != -1 && now != prev && printf("\n") && printPad(pad));
            printf("%d", now);
            prev = now;
            pad = (pad + 1) % 40;
        }
    }
    printf("\n");
}