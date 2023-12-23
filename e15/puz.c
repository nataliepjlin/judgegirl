#include<stdio.h>
#include<stdlib.h>
// #define DEBUG
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(){
    int rs[16], cs[16];
    int puzzle[4][4];
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            scanf("%d", &puzzle[r][c]);
            rs[puzzle[r][c]] = r, cs[puzzle[r][c]] = c;
        }
    }

    int n;
    while(scanf("%d", &n) != EOF){
        if(abs(rs[n] - rs[0]) + abs(cs[n] - cs[0]) == 1){
            swap(&puzzle[rs[n]][cs[n]], &puzzle[rs[0]][cs[0]]);
            swap(&rs[0], &rs[n]); 
            swap(&cs[0], &cs[n]);
            #ifdef DEBUG
            printf("debug\n");
            for(int r = 0; r < 4; r++){
                for(int c = 0; c < 4; c++){
                    printf("%d%c", puzzle[r][c], " \n"[c == 3]);
                }
            }
            printf("\n");
            #endif

            int win = 1;
            if(puzzle[3][3] != 0) win = 0;

            for(int r = 0; r < 4; r++){
                for(int c = 0; c < 4 && win; c++){
                    if(r == 3 && c == 3) continue;
                    if(puzzle[r][c] != (r * 4 + c + 1)) win = 0;
                }
            }
            
            if(win){
                printf("1 2 3 4\n5 6 7 8\n9 10 11 12\n13 14 15 0\n");
                printf("1 %d\n" , n);
                return 0;
            }//win
        }
        
    }

    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            printf("%d%c", puzzle[r][c], " \n"[c == 3]);
        }
    }
    printf("0\n");
    return 0;
}