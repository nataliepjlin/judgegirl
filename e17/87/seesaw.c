#include<stdio.h>
// #define debug
#define MAX 2048
int swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(){
    int n, arr[MAX];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int found = 0, round = 0;
    int balanceIdx = 1;
    while(!found){
        balanceIdx = 1;
        for(balanceIdx; balanceIdx < n - 1 && !found; balanceIdx++){
            int left = balanceIdx, right = balanceIdx;
            int suml = 0, sumr = 0;
            for(int i = 1; left - i >= 0; i++){
                suml += arr[left - i] * i;
                #ifdef debug
                printf("arr[%d] * %d\n", left - i, i);
                #endif
            }
            #ifdef debug
            printf("\n");
            #endif
            for(int i = 1; right + i <= n - 1; i++){
                sumr += arr[right + i] * i;
                #ifdef debug
                printf("arr[%d] * %d\n", right + i, i);
                #endif
            }
            #ifdef debug
            printf("suml = %d, sumr = %d\n\n", suml, sumr);
            #endif
            found = (suml == sumr);
        }//find balance 
        if(!found){
            #ifdef debug
            printf("swap arr[%d] with arr[%d]\n", round, n - 1 - round);
            #endif
            swap(&arr[round], &arr[n - 1 - round]);
            round ++;
        }
    }
    balanceIdx --;
    #ifdef debug
    printf("balanceIdx = %d\n", balanceIdx);
    #endif
    for(int i = 0; i < n; i++){
        if(i == balanceIdx) 
            printf("v ");
        else printf("%d%c", arr[i], " \n"[i == n - 1]);
    }
    return 0;
}