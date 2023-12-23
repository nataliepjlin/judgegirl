#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<ctype.h>
#define debug
int shiftAmount(char p){
    return ((p == 'L') * 32 + (p == 'S') * 16 + (p == 'C') * 8);
}
int main(){
    int type;
    scanf("%d", &type);
    if(!type){
        char pat[5];
        uint32_t L; uint16_t S; char chars[3] = {0}; int c = 0;
        while(scanf("%s%u%hu%s", pat, &L, &S, chars) == 4){
            c = 0;
            uint64_t ans = 0;
            for(int i = 0; i < 4; i++){
                if(i){
                    ans <<= shiftAmount(pat[i]);
                }
                if(pat[i] == 'L' || pat[i] == 'S'){
                    ans |= (L * (pat[i] == 'L') + S * (pat[i] == 'S'));
                }
                else{//char
                    ans |= chars[c];
                    c++;
                }
            }
            printf("%lu\n", ans);
        }
    }/*type 0*/
    else{
        char pat[5];
        while(scanf("%s", pat) == 1){
            uint64_t result;
            scanf("%lu", &result);
            uint32_t L; uint16_t S; char chars[3] = {0}; int c = 1;
            for(int i = 3; i >= 0; i--){
                if(pat[i] == 'L'){
                    L = result & (uint32_t)0xffffffff;
                    result >>= 32;
                }
                else if(pat[i] == 'S'){
                    S = result & (uint16_t)0xffff;
                    result >>= 16;
                }
                else{
                    chars[c] = result & 0xff;
                    c--;
                    result >>= 8;
                }
            }//getting values back
            printf("%u %hu %s\n", L, S, chars);
        }
    }/*type1*/
}