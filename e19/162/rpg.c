#include<stdio.h>
#define MAXP 5000
// #define debug
int main(){
    int players[3][MAXP] = {{0}};
    int count[3] = {0}, next[3] = {0};
    int n;
    int round = 0;
    while(scanf("%d", &n) != EOF){
        #ifdef debug
        printf("n = %d\n", n);
        #endif
        int mod_val = n % 3;
        players[mod_val][(count[mod_val]+next[mod_val]) % MAXP] = n;
        #ifdef debug
        // printf("(count[%d]+next[%d]) mod MAXP = ", mod_val, mod_val);
        // printf("(%d+%d) mod %d = %d\n", count[mod_val], next[mod_val], MAXP, (count[mod_val]+next[mod_val]) % MAXP);
        printf("store %d at players[%d][%d]\n", players[mod_val][(count[mod_val]+next[mod_val]) % MAXP], mod_val, (count[mod_val]+next[mod_val]) % MAXP);
        #endif
        count[mod_val] ++;
        #ifdef debug
        printf("now counts: %d %d %d\n", count[0], count[1], count[2]);
        #endif

        if(count[0] >= 3 && count[1] >= 1 && count[2] >= 1){
            printf("%d %d %d ", players[0][next[0] % MAXP], players[0][(next[0] + 1) % MAXP], players[0][(next[0] + 2) % MAXP]);
            printf("%d ", players[1][(next[1]) % MAXP]);
            printf("%d\n", players[2][(next[2]) % MAXP]);
            count[0] -= 3; count[1] --; count[2] --;
            next[0] = (next[0] + 3) % MAXP;
            next[1] = (next[1] + 1) % MAXP;
            next[2] = (next[2] + 1) % MAXP;
            #ifdef debug
            printf("\nnexts: %d %d %d\n", next[0], next[1], next[2]);
            printf("counts: %d %d %d\n\n", count[0], count[1], count[2]);
            #endif
        }
    }
    return 0;
}