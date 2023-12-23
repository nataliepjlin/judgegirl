#include <stdio.h>
// #define debug
int snake(int *ptr, int *row, int *column) {
    int len = 1;
    while(*(ptr + len)) len++;
    *row = 1, *column = len;
    #ifdef debug
    printf("len = %d\n", len);
    #endif
    int res = 1;
    int bpR = -1, bpC = -1;
    while(*column >= 2){
        res = 1;
        bpR = -1, bpC = -1;
        #ifdef debug
        printf("now row = %d, col = %d\n", *row, *column);
        #endif
        if((*row) * (*column) != len){
            #ifdef debug
            printf("bad\n");
            #endif
            res = 0;
        }
        int count = 0;
        for(int r = 0; r < *row && res; r ++){
            for(int c = 0; c < *column && res; c++){
                if(r % 2){
                    if(*(ptr + count) != (*column - 1) - c  + (*column) * r){
                        bpR = r, bpC = (*column - 1) - c;
                        res = 0;
                    } 
                }
                else{
                    if(*(ptr + count) != count){
                        bpR = r, bpC = c;
                        res = 0;
                    } 
                }
                count ++;
            }
            #ifdef debug
            printf("\n");
            #endif
        }
        #ifdef debug
        printf("bpR = %d, bpC = %d\n\n", bpR, bpC);
        #endif
        if(res) return res;
        else if(bpR > 1 || (bpR == 1 && bpC != *(column) - 1)){
            *row = bpR, *column = bpC;
            return res;
        }
        *row += 1, *column = len / *row;
    }
    return res;
}
int main(void)
{
    int trav[1024] = {0}, row = 0, column = 0, res = 0;
    scanf("%d %d", &trav[0], &trav[1]);
    for(int i = 1; trav[i]; i++)
      scanf("%d", &trav[i + 1]);
    res = snake(trav, &row, &column);
    if(res) printf("%d %d\n", row, column);
    else printf("err %d %d\n", row, column);
    return 0;
}