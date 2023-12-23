#include<stdio.h>
#include<string.h>
#include<stdint.h>
#define debug
void print(uint64_t num){
    for(int i = 0; i < 12; i++){
        int c = (num & 31);
        printf("%c", c + 'a');
        num >>= 5;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    uint64_t num;
    while(n --){
        scanf("%lu", &num);
        print(num);
    }
    printf("\n");
    return 0;
}