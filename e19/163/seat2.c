#include<stdio.h>
#include<string.h>
#define MAXR 50000
#define ROWS 20
#define seatsPerRow 5
// #define debug
void move(int *c, int *prevc, int *r, int *prevr, int *car){
    *c = (*c + 1) % seatsPerRow;
    *r = (*r + (*prevc + 1) / seatsPerRow) % ROWS;
    *car = *car + (*prevr + (*prevc + 1) / seatsPerRow) / ROWS;
    *prevc = *c, *prevr = *r;
    #ifdef debug
    printf("\nafter move, next seat: (%d, %d, %d)\n\n", *car + 1, *r + 1, *c + 1);
    #endif
}
int main(){
    int n, req;
    int car = 0, r = 0, c = 0;
    int prevr = 0, prevc = 0;
    int skips[MAXR][3];//car, row, c
    int skipStart = -1, skipsLen = 0;
    memset(skips, -1, sizeof(skips));
    scanf("%d", &n);
    while(scanf("%d", &req) != EOF){
        if(req == 1){
            if(skipStart < skipsLen && skipStart != -1){
                printf("%d %d %d\n", skips[skipStart][0] + 1, skips[skipStart][1] + 1, skips[skipStart][2] + 1);
                skipStart ++;
            }
            else{
                printf("%d %d %d\n", car + 1, r + 1, c + 1);
                move(&c, &prevc, &r, &prevr, &car);
            }
        }
        else{
            if(car + 1 > n){
                printf("%d %d %d ", skips[skipStart][0] + 1, skips[skipStart][1] + 1, skips[skipStart][2] + 1);
                skipStart ++;
                printf("%d %d %d\n", skips[skipStart][0] + 1, skips[skipStart][1] + 1, skips[skipStart][2] + 1);
                skipStart ++;
            }
            else{
                if((c + 1 == 3) 
                || (c + 1 == 5 && !(car + 1 == n && r + 1 == ROWS))){
                    if(skipStart == -1) skipStart = 0;
                    skips[skipsLen][0] = car,  skips[skipsLen][1] = r,  skips[skipsLen][2] = c;
                    skipsLen ++;
                    move(&c, &prevc, &r, &prevr, &car);
                }
                printf("%d %d %d ", car + 1, r + 1, c + 1);
                move(&c, &prevc, &r, &prevr, &car);
                printf("%d %d %d\n", car + 1, r + 1, c + 1);
                move(&c, &prevc, &r, &prevr, &car);
            }
        }
        #ifdef debug
        printf("skipStart = %d, skipsLen = %d\n\n", skipStart, skipsLen);
        #endif
    }
    return 0;
}