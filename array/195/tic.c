#include<stdio.h>
int oob(int r, int c){
    return (r < 0 || r > 2 || c < 0 || c > 2);
}
int main(){
    int n, found = 0;
    int arr[3][3] = {{0}};
    scanf("%d", &n);
    if(n < 5){
        printf("There is a draw.\n");
        return 0;
    }
    else{
        int round = 0;
        int r, c;
        int rowsum[2][3] = {{0}}, colsum[2][3] = {{0}}, dia1[2] = {0}, dia2[2] = {0};
        while(n--){
            scanf("%d%d", &r, &c);
            if(!arr[r][c] && !(oob(r, c))){
                arr[r][c] = 1;
                if(round % 2 == 0){
                    rowsum[0][r] ++;
                    colsum[0][c] ++;
                    if(r == c) dia1[0] ++;
                    if(c == (3 - 1) - r) dia2[0] ++;

                    if(rowsum[0][r] == 3 || colsum[0][c] == 3 || dia1[0] == 3 || dia2[0] == 3){
                        printf("Black wins.\n");
                        return 0;
                    }
                }
                else{
                    rowsum[1][r] ++;
                    colsum[1][c] ++;
                    if(r == c) dia1[1] ++;
                    if(c == (3 - 1) - r) dia2[1] ++;

                    if(rowsum[1][r] == 3 || colsum[1][c] == 3 || dia1[1] == 3 || dia2[1] == 3){
                        printf("White wins.\n");
                        return 0;
                    }
                }
                round ++;
            }//valid r, c
        }
        printf("There is a draw.\n");
        return 0;
    }
}