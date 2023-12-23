#include<stdio.h>
#include<stdint.h>
int main(){
    int w, h;
    scanf("%d%d", &w, &h);
    char out[2][2];
    scanf("%s%s", out[1], out[0]);
    uint32_t n;
    int p = 0;
    while(scanf("%u", &n) == 1 && p < w * h){
        for(int i = 31; i >= 0 && p < w * h; i--){
            // printf("%u", (n & ((unsigned int)1 << i)) >> i);
            printf("%c", out[(n & ((unsigned int)1 << i)) >> i][0]);
            if(p % w == w - 1) printf("\n");
            p++;
        }
    }
}