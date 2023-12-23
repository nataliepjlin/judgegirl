#include<stdio.h>
int boards[11][66049][2];
int check(int rowsum[11][257], int colsum[11][257], int dia1[11], int dia2[11], int p, int row, int col, int m){
    int found = 0;
    // printf("checking player %d, rowsum = %d, colsum = %d, dia1 = %d, dial2= %d\n", p, rowsum[p][row], colsum[p][col], dia1[p], dia2[p]);
    if(rowsum[p][row] == m || colsum[p][col] == m || dia1[p] == m || dia2[p] == m) found = 1;
    return found;
}

int main(){
    int n, m;
    int rowsum[11][257] = {{0}};
    int colsum[11][257] = {{0}};
    int dia1[11] = {0};
    int dia2[11] = {0};
    char names[11][64];
    scanf("%d%d", &n, &m);
    
    for(int p = 0; p < n; p++){
        scanf("%s", names[p]);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                int input;
                scanf("%d", &input);
                boards[p][input][0] = i;
                boards[p][input][1] = j;
            }
        }
    }//input

    int found = 0;
    for(int round = 0; round < m * m && !found; round ++){
        int call;
        scanf("%d", &call);
        // printf("\ncall = %d\n", call);
        for(int p = 0; p < n; p++){
            int row = boards[p][call][0], col = boards[p][call][1];
            rowsum[p][row] ++;
            colsum[p][col] ++;
            if(row == col) dia1[p] ++;
            if(col == (m - 1) - row) dia2[p]++;

            if(round >= 2){
                int win = check(rowsum, colsum, dia1, dia2, p, row, col, m);
                if(win){
                    if(!found){
                        printf("%d ", call);
                        printf("%s", names[p]);
                        found = 1;
                    }
                    else{
                        printf(" %s", names[p]);
                    }
                }
            }
        }
    }
    return 0;
}