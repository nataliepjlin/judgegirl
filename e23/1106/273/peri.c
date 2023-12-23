#include<stdio.h>
#include<string.h>
#define MAXCHAR 1001
// #define debug
int getIdx(char *prev, char *now){
    int n = strlen(now);
    for(int i = 0; i < n; i++){
        char *ptr = strchr(prev, now[i]);
        if(ptr != NULL){
            return ptr - prev;
        }
    }
}
int main(){
    int p = 0;
    char one[MAXCHAR];
    scanf("%s", one);

    char prev[MAXCHAR];//two
    scanf("%s", prev);
    int onetail = getIdx(one, prev);
    int twohead = strchr(prev, one[onetail]) - prev;
    #ifdef debug
    printf("one[%d] = %c, twohead = %d\n", onetail, one[onetail], twohead);
    #endif
    char now[MAXCHAR];
    int prevhead = twohead;
    int prevtail;
    while(scanf("%s", now) != EOF){
        prevtail = getIdx(prev, now);
        #ifdef debug
        printf("prev[%d] = %c\n", prevtail, prev[prevtail]);
        #endif
        p += (prevtail - prevhead);
        #ifdef debug
        printf("now p = %d\n", p);
        #endif
        prevhead = strchr(now, prev[prevtail]) - now;
        strcpy(prev, now);
    }
    prevtail = getIdx(prev, one);
    #ifdef debug
    printf("end of while loop, prev[%d] = %c\n", prevtail, prev[prevtail]);
    #endif
    p += (prevtail - prevhead);
    #ifdef debug
    printf("now p = %d\n", p);
    #endif
    int onehead = strchr(one, prev[prevtail]) - one;
    p += (onetail - onehead);
    printf("%d\n", p);
    return 0;
}