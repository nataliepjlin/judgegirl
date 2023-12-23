#include<stdio.h>
#include<string.h>
#include<ctype.h>
// #define debug
#define MAX 50000
int getIdx(char loc[]){
    int len = strlen(loc);
    int idx = 0;
    for(int i = 0; i < len; i++){
        idx = idx * 10 + (loc[i] - '0');
    }
    return idx - 1;
}
void insert(char out[], int idx, char new[]){
    int len = strlen(out);
    out[len + 1] = '\0';
    for(int i = len - 1; i >= idx; i--){
        out[i + 1] = out[i];
    }
    out[idx] = new[0];
}
int main(){
    char out[MAX] = {0};
    char ope[7], loc[6], new[2];
    while(scanf("%s", ope) == 1){
        int len = strlen(out);
        if(strcmp(ope, "insert") == 0){
            scanf("%s%s", loc, new);
            if(strcmp(loc, "left") == 0){
                insert(out, 0, new);
            }
            else if(strcmp(loc, "right") == 0){
                strcat(out, new);
            }
            else{
                int idx = getIdx(loc);
                insert(out, idx, new);
            }
        }//insert
        else{
            scanf("%s", loc);
            if(strcmp(loc, "left") == 0){
                memmove(out, out + 1, len);
            }
            else if(strcmp(loc, "right") == 0){
                out[len - 1] = '\0';
            }
            else{
                int idx = getIdx(loc);
                memmove(out + idx, out + idx + 1, len - idx);
            }
        }//del
    }//get output
    #ifdef debug
    printf("out = %s\n", out);
    #endif
    int len = strlen(out);
    char maxchars[MAX] = {0};
    int maxCount = 0;
    int count = 0;
    for(int i = 0; i < len; i++){
        count = (count + 1) * (!i || out[i] == out[i - 1]) + 1 * !(!i || out[i] == out[i - 1]);
        if(maxCount < count){
            maxCount = count;
            memset(maxchars, '\0', MAX);
            maxchars[0] = out[i];
        }
        else if(maxCount == count){
            int mlen = strlen(maxchars);
            maxchars[mlen] = ' ';
            maxchars[mlen + 1] = out[i];
            maxchars[mlen + 2] = '\0';
        }
    }
    if(maxCount) printf("%s ", maxchars);
    printf("%d\n", maxCount);
}