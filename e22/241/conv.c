#include<stdio.h>
#include<stdint.h>
#define N 100000
void num2str(uint64_t num){
    for(int i = 0; i < 12; i++){
        int n = num & 31;
        printf("%c", n + 'a');
        num >>= 5;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    uint64_t num;
    for(int i = 0; i < n; i++){
        scanf("%lu", &num);
        num2str(num);
    }
    printf("\n");
}