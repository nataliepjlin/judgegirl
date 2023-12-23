#include<stdio.h>
#include<string.h>
int mod(int n, int s){
    return (77 * n + 2222) % s;
}
void printHash(int table[][10][3], int s, int c){
    for(int i = 0; i < s; i++){
        for(int j = 0; j < c; j++){
            printf("%2d ", table[i][j][0]);
        }
        printf("\n");
    }
    printf("\n");
}
int buildhash(int table[][10][3], int arr[106][106][106], int r1, int c1, int r2, int c2, int layers[106][106], int s, int c){
    int l1 = layers[r1][c1], l2 = layers[r2][c2];
    int n1 = arr[l1][r1][c1], n2 = arr[l2][r2][c2];
    // printf("\nn1 = %d n2 = %d\n", n1, n2);
    int m1 = mod(n1, s), m2 = mod(n2, s);
    int row1, col1, row2, col2;
    int found1 = 0, loc1 = -1;
    for(int i = 0; i < c && n1 > 0; i ++){
        if(table[m1][i][0] == 0 && loc1 == -1){
            loc1 = i;
        }
        if(table[m1][i][0] == n1){
            printf(" %d", n1);
            table[m1][i][0] = 0;

            row2 = r1;
            col2 = c1;
            row1 = table[m1][i][1];
            col1 = table[m1][i][2];
            // printf("row1=%d, col1=%d, row2=%d, col2=%d\n", row1, col1, row2, col2);

            layers[row1][col1] ++;
            layers[row2][col2] ++;

            found1 = 1;
            break;
        }
    }
    if(!found1){
        table[m1][loc1][0] = n1;
        table[m1][loc1][1] = r1;
        table[m1][loc1][2] = c1;
    }

    int found2 = 0, loc2 = -1;
    for(int i = 0; i < c && n2 > 0; i ++){
        if(table[m2][i][0] == 0 && loc2 == -1){
            loc2 = i;
        }
        else if(table[m2][i][0] == n2){
            printf(" %d", n2);
            table[m2][i][0] = 0;
            row2 = r2;
            col2 = c2;
            row1 = table[m2][i][1];
            col1 = table[m2][i][2];

            layers[row1][col1] ++;
            layers[row2][col2] ++;

            found2 = 1;
            break;
        }
    }

    if(!found2){
        table[m2][loc2][0] = n2;
        table[m2][loc2][1] = r2;
        table[m2][loc2][2] = c2;
    }

    // printHash(table, s, c);
    
    if(found1 || found2){
        // printf("final row1=%d, col1=%d, row2=%d, col2=%d\n\n", row1, col1, row2, col2);
        return buildhash(table, arr, row1, col1, row2, col2, layers, s, c);
    }
    else return 0;
}
int main(){
    int n, s, c;
    scanf("%d%d%d", &n, &s, &c);
    int table[11025][10][3] = {{0}};
    int arr[106][106][106], tops[106][106] ={{0}};
    int layers[106][106] = {{0}};

    int r1, c1, r2, c2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= i; k++){
                scanf("%d", &arr[i][j][k]);
                if(tops[j][k] == 0){
                    tops[j][k] = arr[i][j][k];
                    layers[j][k] = i;
                    int mod_val = mod(tops[j][k], s);
                    for(int l = 0; l < c; l++){
                        if(table[mod_val][l][0] == 0){
                            table[mod_val][l][0] = tops[j][k];
                            table[mod_val][l][1] = j;
                            table[mod_val][l][2] = k;
                            break;
                        }
                        if(table[mod_val][l][0] == tops[j][k]){
                            printf("%d", table[mod_val][l][0]);
                            table[mod_val][l][0] = 0;
                            r1 = table[mod_val][l][1];
                            c1 = table[mod_val][l][2];
                            r2 = j;
                            c2 = k;

                            layers[r1][c1] ++;
                            layers[r2][c2] ++;

                            break;
                        }
                    }
                }//setting tops
            }
        }
    }
    buildhash(table, arr, r1, c1, r2, c2, layers, s, c);
    // printf("\n");
    return 0;
}