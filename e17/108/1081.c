#include<stdio.h>
#include<stdlib.h>
#define MAXN 16384
#ifndef MAXLENGTH 
#define MAXLENGTH 5
#endif
typedef struct node{
    int value;
    struct node *left;
    struct node *right;
}Node;
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int find(int A[], int N){
    if(N < MAXLENGTH) return -1;
    int B[MAXLENGTH];
    for(int i = 0; i < MAXLENGTH; i++){
        B[i] = A[i];
    }
    qsort(B, MAXLENGTH, sizeof(int), cmp);
    for(int i = MAXLENGTH; i < N; i++){
        int j = 0;
        while(j < MAXLENGTH && A[i] > B[j]){
            if(j > 0){
                B[j - 1] = B[j];
            } 
            j++;
        }
        if(j > 0){
            B[j - 1] = A[i];
        }
    }
    for(int i = 0; i < N; i++){
        if(A[i] == B[0])
            return i;
    }
    return -1;
}
Node* ConstructTree(int sequence[], int N){
    int idx = find(sequence, N);
    if(idx == -1){
        Node *prev = NULL;
        for(int i = 0; i < N; i++){
            Node *node = (Node *)malloc(sizeof(Node));
            node->value = sequence[i];
            node->left = prev;
            node->right = NULL;
            prev = node;
        }
        return prev;
    }
    else{
        Node *node = (Node *)malloc(sizeof(Node));
        node->value = sequence[idx];
        node->left = ConstructTree(sequence, idx);
        node->right = ConstructTree(sequence + idx + 1, N - (idx + 1));
        return node;
    }
}