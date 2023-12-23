#include<stdio.h>
#include<string.h>
#include<stdint.h>
#define LEN 100001
// #define debug
int main(){
    int t;
    scanf("%d", &t);
    if(t == 0){
        char str[LEN] = {0};
        scanf("%s", str);
        int len = strlen(str);
        uint64_t num = 0; int cnt = 0;
        for(int i = 0; i <= len; i++){
            num <<= 8;
            num |= str[i];
            #ifdef debug
            printf("char = %c, now num = %lu\n", str[i], num);
            #endif
            cnt++;
            if(cnt == 8){
                printf("%lu\n", num);
                num = (uint64_t)0;
                cnt = 0;
            }
        }
        if(cnt != 0){
            while(cnt != 8){
                num <<= 8;
                cnt ++;
            }
            printf("%lu\n", num);
        }
    }//type 0
    else{
        int n; scanf("%d", &n);
        uint64_t num;
        int flag = 1;
        for(int i = 0; i < n && flag; i++){
            scanf("%lu", &num);
            for(int j = 56; j >= 0 && flag; j-= 8){
                char c = (num >> j) & 0xff;
                if(c != 0){
                    printf("%c", c);
                }
                else{
                    printf("\n");
                    flag = 0;
                }
            }
        }
    }
}