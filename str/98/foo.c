#include<stdio.h>
#include<string.h>
#define MAXN 100
#define MAXI 10
#define MAXCHAR 65
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void bs(char ingredients[MAXN][MAXI][MAXCHAR], int out[], int idx, int idx1){
    for(int i = 0; i < idx; i++){
        for(int j = 0; j < idx - i - 1; j++){
            if(strcmp(ingredients[idx1][out[j]], ingredients[idx1][out[j + 1]]) > 0){
                swap(&out[j], &out[j + 1]);
            }
        }
    }
}
int main(){
    char food[MAXN][MAXCHAR];
    int lens[MAXN];
    char ingredients[MAXN][MAXI][MAXCHAR];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s%d", food[i], &lens[i]);
        for(int j = 0; j < lens[i]; j++){
            scanf("%s", ingredients[i][j]);
        }
    }
    int query;
    scanf("%d", &query);
    char q1[MAXCHAR], q2[MAXCHAR];
    for(int i = 0; i < query; i++){
        scanf("%s%s", q1, q2);
        int idx1 = -1, len1 = -1, idx2 = -1, len2 = -1;
        for(int j = 0; j < n && (idx1 == -1 || idx2 == -1); j++){
            if(idx1 == -1 && strcmp(q1, food[j]) == 0){
                idx1 = j;
                len1 = lens[j];
            }
            if(idx2 == -1 && strcmp(q2, food[j]) == 0){
                idx2 = j;
                len2 = lens[j];
            }
        }//get idx
        int idx = 0;
        int out[MAXI] = {0};
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                if(strcmp(ingredients[idx1][i], ingredients[idx2][j]) == 0){
                    out[idx] = i;
                    idx ++;
                }
            }
        }
        if(!idx) printf("nothing\n");
        else{
            bs(ingredients, out, idx, idx1);
            for(int i = 0; i < idx; i++){
                printf("%s%c", ingredients[idx1][out[i]], " \n"[i == idx - 1]);
            }
        }
    }
    return 0;
}