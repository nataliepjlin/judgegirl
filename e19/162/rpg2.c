#include<stdio.h>
#define playerPerClass 5000
// #define debug
int main(){
    //A party has one tank, one healer and three DPS's
    int players[3][playerPerClass] = {{0}};
    int idx0 = 0, idx1 = 0, idx2 = 0;
    int n;
    int round = 0;
    while(scanf("%d", &n) != EOF){
        if(n % 3 == 0){
            players[0][(idx0) % 5000] = n;
            idx0 ++;
        }
        else if(n % 3 == 1){
            players[1][(idx1) % 5000] = n;
            idx1 ++;
        }
        else{
            players[2][(idx2) % 5000] = n;
            idx2 ++;
        }
        #ifdef debug
        printf("idx0 = %d, idx1 = %d, idx2 = %d\n", idx0, idx1, idx2);
        #endif
        if((idx0 >= (3 + round * 3) % 5000) 
        && idx1 >= (1 + round) % 5000
        && idx2 >= (1 + round) % 5000){
            printf("%d %d %d ", players[0][(0 + 3 * round) % 5000], players[0][(1 + 3 * round) % 5000], players[0][(2 + 3 * round) % 5000]);
            printf("%d ", players[1][round % 5000]);
            printf("%d\n", players[2][round % 5000]);
            round ++;
        }
    }
    return 0;
}