#include<stdio.h>
#include<string.h>
#include<stdint.h>
#define CHAR 33
#define debug
void print(char dict[], int now[]){
    int val = 0;
    int p = 1;
    for(int i = 4; i >= 0; i--){
        val += (now[i] * p);
        p *= 2;
    }
    printf("%c", dict[val]);
}
int main(){
    char dict[CHAR];
    scanf("%s", dict);
    int n;
    scanf("%d", &n);
    int now[5] = {0}, idx = 0;
    uint32_t num;
    for(int i = 0; i < n; i++){
        scanf("%u", &num);
        for(int j = 31; j >= 0; j--){
            now[idx ++] = (num >> j) & 1;
            if(idx == 5){
                print(dict, now);
                idx = 0;
            }
        }
    }
    return 0;
}