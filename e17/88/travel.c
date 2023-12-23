#include<stdio.h>
// #define debug
int traveled[2][1024][1024] = {{0}};
int oob(int r, int c, int N, int M){
    return (r < 0 || r > N - 1 || c < 0 || c > M - 1);
}
void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[]){
    int idx = 0;
    int dr[] = {0, 0, 1, -1, 1, -1, -1, 1};
    int dc[] = {1, -1, 0, 0, 1, -1, 1, -1};
    int found1 = 1, found2 = 1;
    traveled[0][A_r][A_c] = traveled[1][B_r][B_c] = 1;
    while(found1 || found2){
        int initf1 = found1, initf2 = found2;
        found1 = 0;
        int max = map[A_r][A_c];
        for(int i = 0; i < 8 && initf1; i++){
            if(!(oob(A_r + dr[i], A_c + dc[i], N, M))){
                if(max < map[A_r + dr[i]][A_c + dc[i]]){
                    found1 = 1;
                    max = map[A_r + dr[i]][A_c + dc[i]];
                    directionA[idx] = i;
                }
            }
        }
        if(!found1) directionA[idx] = -1;
        else if(traveled[1][A_r + dr[directionA[idx]]][A_c + dc[directionA[idx]]]){
            directionA[idx + 1] = -1;
            found1 = 0;
        }
        else{
            directionA[idx] = directionA[idx];
            #ifdef debug
            printf("A moves from [%d][%d] ", A_r, A_c);
            #endif
            A_r += dr[directionA[idx]], A_c += dc[directionA[idx]];
            #ifdef debug
            printf("to [%d][%d]\n", A_r, A_c);
            #endif
        } 

        found2 = 0;
        int min = map[B_r][B_c];
        for(int i = 0; i < 8 && initf2; i++){
            if(!(oob(B_r + dr[i], B_c + dc[i], N, M))){
                if(min > map[B_r + dr[i]][B_c + dc[i]]){
                    found2 = 1;
                    min = map[B_r + dr[i]][B_c + dc[i]];
                    directionB[idx] = i;
                }
            }
        }
        if(!found2) directionB[idx] = -1;
        else if(traveled[0][B_r + dr[directionB[idx]]][B_c + dc[directionB[idx]]]){
            directionB[idx + 1] = -1;
            found2 = 0;
        }
        else{
           directionB[idx] = directionB[idx];
           #ifdef debug
           printf("B moves from [%d][%d] ", B_r, B_c);
           #endif
           B_r += dr[directionB[idx]], B_c += dc[directionB[idx]];
           #ifdef debug
           printf("to [%d][%d]\n\n", B_r, B_c);
           #endif 
        } 

        traveled[0][A_r][A_c] = traveled[1][B_r][B_c] = 1;
        idx ++;
        if(A_r == B_r && A_c == B_c && found1 && found2){
            directionA[idx] = directionB[idx] = -1;
            found1 = found2 = 0;
        }
    }//while found
}
int main() {
    int N, M;
    int map[1024][1024];
    int A_r, A_c, B_r, B_c;
    int directionA[1024], directionB[1024];
 
    scanf("%d%d", &N, &M);
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
 
    scanf("%d%d%d%d", &A_r, &A_c, &B_r, &B_c);
 
    travel(map, N, M, A_r, A_c, B_r, B_c, directionA, directionB);
 
    int i = 0;
    while (directionA[i] != -1) {
        printf("%d ", directionA[i]);
        i++;
    }
    printf("-1\n");
    i = 0;
    while (directionB[i] != -1) {
        printf("%d ", directionB[i]);
        i++;
    }
    printf("-1\n");
 
    return 0;
}