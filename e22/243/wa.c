#include<stdio.h>
#include<stdint.h>
#include<limits.h>
#define N 64
typedef struct{
    int pick;
    uint64_t selected;
}SELECT;
int hasAll(SELECT selection, uint64_t friends[], int n){
    for(int i = 0; i < n; i++){
        if(selection.selected & (uint64_t)1 << i)
            continue;
        if((selection.selected & friends[i]) == 0)
            return 0;
    }
    return 1;
}
SELECT getCover(uint64_t friends[N], uint64_t hasFriend, int idx, SELECT selection, int n){
    if(hasAll(selection, friends, n))
        return selection;
    if(idx >= n)
        return (SELECT){n, 0};
    SELECT new = {selection.pick + 1, selection.selected | (uint64_t)1 << idx};
    SELECT yes = getCover(friends, hasFriend, idx + 1, new, n);
    SELECT no = getCover(friends, hasFriend, idx + 1, selection, n);
    return (no.pick < yes.pick) ? no : yes;
}
void print(SELECT selection, int n){
    for(int i = 0; i < n; i++){
        if(selection.selected & (uint64_t)1 << i)
            printf("%d\n", i);
    }
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    uint64_t friends[N] = {0};
    uint64_t hasFriend = 0;
    int p1, p2;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &p1, &p2);
        friends[p1] |= ((uint64_t)1 << p2);
        friends[p2] |= ((uint64_t)1 << p1);
        hasFriend |= (((uint64_t)1 << p2) | ((uint64_t)1 << p1));
    }
    SELECT selection = {0, 0};
    SELECT ans = getCover(friends, hasFriend, 0, selection, n);
    print(ans, n);
}