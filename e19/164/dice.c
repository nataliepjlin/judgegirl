#include<stdio.h>
#define MAXR 1000
#define MAXC 1000
// #define debug
int main(){
    int row, col;
    int arr[MAXR][MAXC];
    scanf("%d%d", &row, &col);
    int count = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &arr[i][j]);
        }//col
    }//row

    for(int i = 1; i < row - 1; i++){
        for(int j = 0; j < col - 3; j++){
            int checks[7] = {0}, isDice = 1;
            if(arr[i][j] + arr[i][j + 2] != 7 
            || arr[i][j + 1] + arr[i][j + 3] != 7) isDice = 0;

            for(int c = 0; c < 4 && isDice; c++){
                #ifdef debug
                printf("checking arr[%d][%d] = %d\n", i, j + c, arr[i][j + c]);
                #endif
                checks[arr[i][j + c]] ++;
                if(checks[arr[i][j + c]] > 1) isDice = 0;
            }
            int topval = -1;
            for(int c = 0; c < 4 && isDice; c++){
                if(!checks[arr[i - 1][j + c]]){
                    topval = arr[i - 1][j + c];
                    #ifdef debug
                    printf("\nset topval = %d, from arr[%d][%d]\n", topval, i - 1, j + c);
                    #endif
                } 
                if(topval != -1){
                    for(int c = 0; c < 4 && isDice; c++){
                        if(arr[i + 1][j + c] + topval == 7){
                            count ++;
                            #ifdef debug
                            printf("paired val = %d, from arr[%d][%d] ", arr[i + 1][j + c], i + 1, j + c);
                            printf("count = %d\n", count);
                            #endif  
                        } 
                    }//pairing bottom val
                    topval = -1;//reset topval
                }
            }//find topval
        }
    }
    printf("%d\n", count);
    return 0;
}