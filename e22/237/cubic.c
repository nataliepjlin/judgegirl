#include<stdio.h>
#include<string.h>
#define N 100
#define LEN 6
// #define debug
int f(char str[]){
    int len = strlen(str);
    int val = 0;
    for(int i = 0; i < len; i++){
        val = (val * 29 + str[i]) % (N * N);
    }
    val %= (N * N);
    return val;
}
int hashing(char hashT[N * N][10][LEN], int hashLoc[N * N][10][2]
, char cubes[N][N][N][LEN],
int r1, int c1, int r2, int c2,
int layers[N][N]){
    int l1 = layers[r1][c1], l2 = layers[r2][c2];
    int hashVal1 = f(cubes[l1][r1][c1]), hashVal2 = f(cubes[l2][r2][c2]);
    int found1 = 0, found2 = 0;
    int loc1 = -1, loc2 = -1;
    int rr1, cc1, rr2, cc2;
    for(int i = 0; i < 10; i++){
        int len = strlen(hashT[hashVal1][i]);
        if(!len && loc1 == -1)
            loc1 = i;
        else if(strcmp(hashT[hashVal1][i], cubes[l1][r1][c1]) == 0
        && len > 0){
            printf("%s\n", cubes[l1][r1][c1]);
            memset(hashT[hashVal1][i], '\0', len);
            rr1 = hashLoc[hashVal1][i][0];
            cc1 = hashLoc[hashVal1][i][1];
            rr2 = r1;
            cc2 = c1;
            layers[rr1][cc1] ++;
            layers[rr2][cc2] ++;
            found1 = 1;
            break;
        }
    }//finding r1,c1
    if(!found1){
        strcpy(hashT[hashVal1][loc1], cubes[l1][r1][c1]);
        hashLoc[hashVal1][loc1][0] = r1; 
        hashLoc[hashVal1][loc1][1] = c1; 
    }
    for(int i = 0; i < 10; i++){
        int len = strlen(hashT[hashVal2][i]);
        if(!len && loc2 == -1){
            loc2 = i;
            if(found1) break;
        }
        else if(strcmp(hashT[hashVal2][i], cubes[l2][r2][c2]) == 0
        && len > 0){
            printf("%s\n", cubes[l2][r2][c2]);
            memset(hashT[hashVal2][i], '\0', len);
            rr1 = hashLoc[hashVal2][i][0];
            cc1 = hashLoc[hashVal2][i][1];
            rr2 = r2;
            cc2 = c2;
            layers[rr1][cc1] ++;
            layers[rr2][cc2] ++;
            found2 = 1;
            break;
        }
    }//finding r2,c2
    if(!found2){
        strcpy(hashT[hashVal2][loc2], cubes[l2][r2][c2]);
        hashLoc[hashVal2][loc2][0] = r2; 
        hashLoc[hashVal2][loc2][1] = c2; 
    }
    
    if(found1 || found2){
        return hashing(hashT, hashLoc, cubes, rr1, cc1, rr2, cc2, layers);
    }
    else return 0;
}
int main(){
    int n;
    char cubes[N][N][N][LEN];
    int layers[N][N];
    memset(layers, -1, sizeof(layers));
    char hashT[N * N][10][LEN];
    int hashLoc[N * N][10][2] = {{{0}}};
    int r1 = -1, c1 = -1, r2 = -1, c2 = -1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= i; k++){
                scanf("%s", cubes[i][j][k]);
                if(layers[j][k] == -1){
                    layers[j][k] = i;
                    int hashVal = f(cubes[i][j][k]);
                    for(int h = 0; h < 10; h++){
                        int len = strlen(hashT[hashVal][h]);
                        if(len == 0){
                            strcpy(hashT[hashVal][h], cubes[i][j][k]);
                            hashLoc[hashVal][h][0] = j;
                            hashLoc[hashVal][h][1] = k;
                            break;
                        }
                        if(strcmp(hashT[hashVal][h], cubes[i][j][k]) == 0){
                            printf("%s\n", cubes[i][j][k]);
                            memset(hashT[hashVal][h], '\0', len);
                            r1 = hashLoc[hashVal][h][0];
                            c1 = hashLoc[hashVal][h][1];
                            r2 = j;
                            c2 = k;
                            layers[r1][c1] ++;
                            layers[r2][c2] ++;
                            break;
                        }//same
                    }//for c
                }//set tops
            }//k
        }//j
    }//i
    #ifdef debug
    printf("%d,%d %d,%d\n", r1, c1, r2, c2);
    #endif
    hashing(hashT, hashLoc, cubes, r1, c1, r2, c2, layers);
    return 0;
}