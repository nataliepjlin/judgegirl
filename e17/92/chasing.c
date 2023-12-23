#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 64
// #define debug
void chasing(int **A[], int a, int *B[], int b, int C[], int c){
    memset(A, 0, sizeof(A[0]) * a);
    memset(B, 0, sizeof(B[0]) * b);

    int sizes[3] = {a, b, c};
    char cmd[SIZE], *frag[5];
    while(fgets(cmd, SIZE, stdin) != NULL){
        frag[0] = strtok(cmd, " ");
        #ifdef debug
        printf("frag[0] = %s\n", frag[0]);
        #endif
        for(int i = 1; i < 5; i++){
            frag[i] = strtok(NULL, " ");
            #ifdef debug
            printf("frag[%d] = %s\n", i, frag[i]);
            #endif
        }
        if(frag[0] == NULL || frag[1] == NULL || frag[2] == NULL
        || frag[3] == NULL || frag[4] != NULL
        || strlen(frag[0]) != 1 || strlen(frag[2]) != 1
        || frag[0][0] - 'A' < 0 || frag[0][0] - 'A' > 1
        || frag[2][0] - 'A' < 1 || frag[2][0] - 'A' > 2){
            printf("0\n");
            continue;
        }

        int from = frag[0][0] - 'A', to = frag[2][0] - 'A';
        int valid = (to - from == 1);
        #ifdef debug
        printf("from = %d, to = %d\n", from, to);
        #endif
        int idx1 = 0, idx2 = 0;
        int len1 = strlen(frag[1]), len2 = strlen(frag[3]);
        len2 -= (frag[3][len2 - 1] == '\n');

        for(int i = 0; i < len1 && valid; i++){
            valid = (isdigit(frag[1][i]));
            idx1 = idx1 * 10 + (frag[1][i] - '0');
        }
        if(!valid || idx1 < 0 || idx1 >= sizes[from]){
            printf("0\n");
            continue;
        }
        
        for(int i = 0; i < len2 && valid; i++){
            valid = (isdigit(frag[3][i]));
            idx2 = idx2 * 10 + (frag[3][i] - '0');
        }
        if(!valid || idx2 < 0 || idx2 >= sizes[to]){
            printf("0\n");
            continue;
        }
        #ifdef debug
        printf("idx1 = %d, idx2 = %d\n", idx1, idx2);
        #endif

        printf("1\n");

        if(frag[0][0] == 'A'){
            A[idx1] = &B[idx2];
        }
        else{
            B[idx1] = &C[idx2];
        }
    }
}