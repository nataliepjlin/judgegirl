#include<stdio.h>
// #define debug
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(){
    int up = 0, down = 0;//(up down), or (down up)
    int pprev, prev, now;
    int start = -1, peak = -1, end = -1;
    int found = 0, maxlen = 0, maxl = -1, maxstart = -1;
    scanf("%d", &prev);
    int idx = 1;
    while(scanf("%d", &now) != EOF){
        #ifdef debug
        printf("now = %d, prev = %d, up = %d, down = %d\n", now, prev, up, down);
        #endif
        if(!up && !down){
            up = (now - prev > 0); 
            down = (now - prev < 0);

            start = idx;
        }

        else if(now - prev > 0 && !up && down){
            up = 2;
            peak = idx;
            #ifdef debug
            printf("set peak idx to %d\n", peak);
            #endif
        }
        else if(now - prev < 0 && up && !down){
            down = 2;
            peak = idx;
            #ifdef debug
            printf("set peak idx to %d\n", peak);
            #endif
        }

        else if(up && down && ((prev - pprev > 0 && now - prev < 0) 
        || (prev - pprev < 0 && now - prev > 0))){
            end = idx;
            if((end - start + 1 > maxlen) 
            || ((end - start + 1 == maxlen) && (peak - start + 1 > maxl))){
                maxlen = end - start + 1;
                maxl = peak - start + 1;
                maxstart = start;
                #ifdef debug
                printf("set maxlen to %d, maxl to %d, maxstart to %d\n", maxlen, maxl, maxstart);
                #endif
            }
            start = peak;
            peak = end;
            end = - 1;
            swap(&up, &down);
        }
        pprev = prev;
        prev = now;
        idx ++;
        #ifdef debug
        printf("start = %d, peak = %d, end = %d\n\n", start, peak, end);
        #endif
    }
    if(end == - 1 
    && ((prev - pprev > 0 && up - down > 0) || (prev - pprev < 0 && up - down < 0)) 
    && up && down){
        //if same dir then extend
        end = idx;
        #ifdef debug
        printf("start = %d, peak = %d, end = %d\n\n", start, peak, end);
        #endif
        if((end - start + 1 > maxlen) 
        || ((end - start + 1 == maxlen) && (peak - start + 1 > maxl))){
            maxlen = end - start + 1;
            maxl = peak - start + 1;
            maxstart = start;
            #ifdef debug
            printf("set maxlen to %d, maxl to %d, maxstart to %d\n", maxlen, maxl, maxstart);
            #endif
        }
    }
    if(maxlen) printf("%d %d\n", maxlen, maxstart);
    else printf("0\n");
    return 0;
}