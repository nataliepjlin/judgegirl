#include<stdio.h>
#define MAXS 100000
#define MAXC 10
int f(int key, int s){
    return (77 * key + 2222) % s;
}
int main(){
    int hashT[MAXS][MAXC] = {{0}};
    int hashLen[MAXS] = {0};
    int s, c;
    scanf("%d%d", &s, &c);
    int k;
    while(scanf("%d", &k) == 1){
        int idx = f(k, s);
        int same = 0;
        int slot = hashLen[idx];
        for(int i = 0; i < hashLen[idx] && !same; i++){
            if(slot == hashLen[idx] && hashT[idx][i] == 0)
                slot = i;
            if(hashT[idx][i] == k){
                same = 1;
                printf("%d %d\n", k, idx);
                hashT[idx][i] = 0;
            }
        }
        if(!same){  
            hashT[idx][slot] = k;
            hashLen[idx] += (slot == hashLen[idx]);
        }
    }
    return 0;
}