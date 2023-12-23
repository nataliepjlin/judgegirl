#include<stdio.h>
#define MAXN 1000
// #define debug
int main(){
    int n;
    int max = 0;
    int arr[MAXN][MAXN];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j ++){
            scanf("%d", &arr[i][j]);
            if(j == n - 1){
                int start = -1;
                for(int k = j; k >= 0; k --){
                    if(arr[i][k] == 1){
                        if(!max) max = 1;
                        if(start == -1) start = k;
                        else{
                            if(max < start - k + 1){
                                max = start - k + 1;
                                #ifdef debug
                                printf("max change by start = %d, k = %d\n", start, k);
                                #endif
                            }
                        }
                        #ifdef debug
                        printf("%dth row, now max = %d, start = %d\n", i, max, start);
                        #endif
                    }//is 1
                    else{
                        #ifdef debug
                        printf("break search\n");
                        #endif
                        start = -1;
                    }//is NOT 1
                }
            }//row check
        }//col
    }//row
    for(int c = 0; c < n; c++){
        int start = -1;
        for(int r = 0; r < n; r++){
            if(arr[r][c] == 1){
                if(!max) max = 1;
                if(start == -1) start = r;
                else if(max < r - start + 1){
                    max = r - start + 1;
                    #ifdef debug
                    printf("max change by start = %d, r = %d\n", start, r);
                    #endif
                }
                #ifdef debug
                printf("%dth col, now max = %d, start = %d\n", c, max, start);
                #endif
            }//is 1
            else{
                #ifdef debug
                printf("break search\n");
                #endif
                start = -1;
            }//is NOT 1
        }//r
    }//col check
    
    int startd1 = -1, startd2 = -1;
    for(int count = 0; count < n - 1; count++){
        for(int i = 0; i + count < n; i++){
            if(arr[i][i + count]){
                if(!max) max = 1;
                if(startd1 == -1) startd1 = i;
                else if(max < i - startd1 + 1) max = i - startd1 + 1;
            }
            else startd1 = -1;

            if(arr[i + count][i]){
                if(!max) max = 1;
                if(startd2 == -1) startd2 = i + count;
                else if(max < (i + count) - startd2 + 1) max = (i + count) - startd2 + 1;
            }
            else startd2 = -1;
        }//i
    }//count
    
    printf("%d\n", max);
    return 0;
}