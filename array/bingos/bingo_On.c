#include<stdio.h>
int boards[11][66049][2];
int check(int mark[11][257][257], int p, int row, int col, int m){
    int found = 0;
    int sum;

    sum = 0;
    for(int c = 0; c < m; c++){
        sum += mark[p][row][c];
    }
    // printf("player %d's row %d sum = %d\n", p, r, sum);
    if(sum == m) found = 1;

    
    sum = 0;
    for(int r = 0; r < m && !found; r++){
        sum += mark[p][r][col];
    }
    // printf("player %d's col %d sum = %d\n", p, c, sum);
    if(sum == m) found = 1;

    if(!found && (row == col)){
        sum = 0;
        for(int r = 0; r < m; r++){
            sum += mark[p][r][r];
        }
        // printf("player %d's diagonal1's sum = %d\n", p, sum);
        if(sum == m) found = 1;
    }

    if(!found && (col == (m - 1) - row)){
        sum = 0;
        for(int r = 0; r < m; r++){
            sum += mark[p][r][(m - 1) - r];
        }
        // printf("player %d's diagonal2's sum = %d\n", p, sum);
        if(sum == m) found = 1;
    }
    return found;
}

int main(){
    int n, m;
    int mark[11][257][257] = {{{0}}};
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
            mark[p][boards[p][call][0]][boards[p][call][1]] = 1;
            // printf("mark (%d, %d)\n", boards[p][call][0], boards[p][call][1]);

            if(round >= 2){
                int win = check(mark, p, boards[p][call][0], boards[p][call][1], m);
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