#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#define SIZE 64
#define N 101
// #define debug
void printClubs(int selectedClubs[], int pick){
    for(int i = 0; i < pick; i++){
        printf("%d\n", selectedClubs[i]);
    }
    return;
}
void solve(uint64_t selectedMembers, int clubIdx, uint64_t clubs[N],
int selectedClubs[], int pick, int k, int n){
    #ifdef debug
    printf("clubidx = %d, pick = %d\n",clubIdx, pick);
    #endif
    if(pick == k){ 
        printClubs(selectedClubs, pick);
        exit(0);
    }
    if(pick > k || clubIdx >= n){
        #ifdef debug
        printf("out of range\n\n");
        #endif
        return;
    }
    if((clubs[clubIdx] & selectedMembers) == 0){
        selectedClubs[pick] = clubIdx;
        solve(selectedMembers | clubs[clubIdx], clubIdx + 1, clubs, selectedClubs, pick + 1, k, n);
    } 
    solve(selectedMembers, clubIdx + 1, clubs, selectedClubs, pick, k, n);
}
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    uint64_t clubs[N] = {0};
    for(int i = 0; i < n; i++){
        int m; scanf("%d", &m);
        for(int j = 0; j < m; j++){
            int member; scanf("%d", &member);
            clubs[i] |= (uint64_t)1 << member;
        }//m members
    }//n clubs
    uint64_t selectedMembers = 0; int clubCount = 0;
    int selectedClubs[N] = {0};
    solve(selectedMembers, 0, clubs, selectedClubs, 0, k, n);
}