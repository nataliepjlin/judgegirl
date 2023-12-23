#include<stdio.h>
// #define DEBUG
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int arr[2][101][101], live[101][101];
    int now = 0, next = 1;
    int maxr = 0, maxc = 0, maxval = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[0][i][j]);
            live[i][j] = arr[1][i][j] = arr[0][i][j];
            if(maxval <= live[i][j]){
                maxval = live[i][j];
                maxr = i; maxc = j;
            }
        }
    }

    for(int round = 0; round < k; round ++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int count = 0;
                if(i > 0){
                    if(j > 0 && arr[now][i - 1][j - 1]) count ++;
                    if(arr[now][i - 1][j]) count ++;
                    if(j < n - 1 && arr[now][i - 1][j + 1]) count ++;
                }
                if(j > 0 && arr[now][i][j - 1]) count ++;
                if(j < n - 1 && arr[now][i][j + 1]) count ++;

                if(i < n - 1){
                    if(j > 0 && arr[now][i + 1][j - 1]) count ++;
                    if(arr[now][i + 1][j]) count ++;
                    if(j < n - 1 && arr[now][i + 1][j + 1]) count ++;
                }
                #ifdef DEBUG
                printf("arr[now][%d][%d] = %d, count = %d\n", i, j, arr[now][i][j], count);
                #endif

                if((arr[now][i][j] && (count < 2 || count > 3)) || (!arr[now][i][j] && count != 3)) arr[next][i][j] = 0;
                else if((arr[now][i][j] && (count == 2 || count == 3)) || (!arr[now][i][j] && count == 3)){
                    arr[next][i][j] = 1;
                    live[i][j] ++;
                    if(live[i][j] >= maxval){
                        maxval = live[i][j];
                        maxr = i;
                        maxc = j;
                        #ifdef DEBUG
                        // printf("maxval = %d, maxr = %d, maxc = %d\n", maxval, maxr, maxc);
                        #endif
                    }
                }
            }
        }
        #ifdef DEBUG
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    printf("%d%c", arr[next][i][j], " \n"[j == n - 1]);
                }
            }
            // printf("\n");
            // for(int i = 0; i < n; i++){
            //     for(int j = 0; j < n; j++){
            //         printf("%d%c", live[i][j], " \n"[j == n - 1]);
            //     }
            // }
            printf("###########################\n");
            #endif
        now ^= 1, next ^= 1;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d%c", arr[now][i][j], " \n"[j == n - 1]);
        }
    }
    printf("%d %d\n", maxr + 1, maxc + 1);
    return 0;
}