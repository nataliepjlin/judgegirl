#include<stdio.h>
#include<string.h>
#define SIZE 32
// #define debug
int findName(char names[SIZE][SIZE], char name[SIZE], int N){
    int idx = -1;
    for(int i = 0; i < N && idx == -1; i++){
        if(!strcmp(names[i], name)){
            idx = i;
        }
    }
    return idx;
}
int main(){ 
    char names[SIZE][SIZE];
    int money[SIZE] = {0};
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s%d", names[i], &money[i]);
    }
    char name[SIZE];
    while(scanf("%s", name) == 1){
        int idx1 = findName(names, name, N);
        if(idx1 != -1){
            #ifdef debug
            printf("idx1 = %d\n", idx1);
            #endif
            char cmd1[SIZE];
            scanf("%s", cmd1);
            #ifdef debug
            printf("cmd1 = %s\n", cmd1);
            #endif
            if(strstr(cmd1, "earns")){
                int m; scanf("%d", &m);
                money[idx1] += m;
            }
            else if(strstr(cmd1, "spends")){
                int m; scanf("%d", &m);
                if(money[idx1] - m >= 0){
                    money[idx1] -= m;
                }
            }
            else if(strstr(cmd1, "becomes")){
                int m; scanf("%d", &m);
                money[idx1] = m;
            }
            else if(strstr(cmd1, "gives")){
                char name2[SIZE];
                scanf("%s", name2);
                int idx2 = findName(names, name2, N);
                if(idx2 != -1){
                    #ifdef debug
                    printf("idx2 = %d\n", idx2);
                    #endif
                    int m; scanf("%d", &m);
                    if(money[idx1] - m >= 0){
                        money[idx1] -= m;
                        money[idx2] += m;
                    }
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        printf("%s %d\n", names[i], money[i]);
    }
    return 0;
}