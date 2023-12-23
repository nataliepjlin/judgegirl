#include<stdio.h>
#define MAXN 100001
#define HALFN 1001
// #define debug
int mod(int k){
    return (77 * k + 2222) % HALFN;
}
int main(){
    int n;
    int hash[HALFN][10][2] = {{0}};//s, c, (val, idx)
    scanf("%d", &n);
    int found = 0;
    int val;
    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        int firstSlot = -1, same = 0;
        int mod_val = mod(val);
        for(int j = 0; j < 10 && !same; j++){
            if(!hash[mod_val][j][0] && firstSlot == -1){
                firstSlot = j;
            }
            if(hash[mod_val][j][0] == val){
                same = 1;
                printf("%d %d %d\n", i, hash[mod_val][j][1], val);
                hash[mod_val][j][0] = 0;
            }
        }
        if(!same){
            #ifdef debug
            printf("store val at hash[%d][%d][0]\n", mod_val, firstSlot);
            printf("i = %d, hash[%d][%d][1] = %d", i, mod_val, firstSlot, hash[mod_val][firstSlot][1]);
            #endif
            printf("%d\n", i);
            hash[mod_val][firstSlot][0] = val;
            hash[mod_val][firstSlot][1] = i;
        }
    }
    return 0;
}