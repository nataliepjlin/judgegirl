#include<stdio.h>
#include<string.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void bubbleSort(int team[1000000], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < (size -1) - i; j++){
            if(team[j] > team[j+1]){
                swap(&team[j], &team[j+1]);
            }
        }
    }
}
int main(){
    int k;
    int team[1000000], idx = 0, cpsum = 0;

    scanf("%d", &k);
    // printf("k=%d\n", k);
    int cp;
    int attr[3]={0};
    while(scanf("%d", &cp) != EOF){
        team[idx] = cp;
        idx ++;
        // printf("cp = %d, now idx = %d\n", cp, idx);
        attr[cp % 3] ++;
        // printArr2(attr, 3);
        if(attr[0] >= k && attr[1] >= k && attr[2] >= k){
            bubbleSort(team, idx);
            // printArr(team, idx);
            cpsum += team[idx - 2];
            // printf("now cpsum = %d\n", cpsum);
            memset(team, 0, idx * sizeof(int));
            // printArr(team, idx);
            memset(attr, 0, sizeof(attr));
            idx = 0;
        }
    }
    if(idx){
        bubbleSort(team, idx);
        // printArr(team, idx);
        cpsum += (idx > 1)? team[idx - 2] : team[0];
        // printf("now cpsum = %d\n", cpsum);
    }

    printf("%d\n", cpsum);
    return 0;
}