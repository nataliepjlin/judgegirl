#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 64
void chasing(int **A[], int a, int *B[], int b, int C[], int c){
    int len[3] = {a, b, c};
    for(int i = 0; i < a; i++)
        A[i] = NULL;
    for(int i = 0; i < b; i++)
        B[i] = NULL;
    char cmd[SIZE];
    int valid = 1;
    while(fgets(cmd, SIZE, stdin) != NULL){
        int len = strlen(cmd);
    }
}