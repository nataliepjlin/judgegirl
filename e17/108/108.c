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
    return *(int *)b - *(int *)a;
}
int find(int A[], int start, int end){
    int B[MAXN];
    int len = end - start + 1;
    if(len < MAXLENGTH) return -1;
    for(int i = 0; i < len; i++){
        B[i] = A[start + i];
    }
    qsort(B, len, sizeof(int), cmp);
    for(int i = start; i <= end; i++){
        if(A[i] == B[MAXLENGTH - 1])
            return i;
    }
    return -1;
}
Node *genNode(int val, Node *l, Node *r){
    Node *node = (Node *)malloc(sizeof(Node));
    node->left = l, node->right = r;
    node->value = val;
    return node;
}
Node *genList(int sequence[], int start, int end){
    if(end < start) return NULL;
    return(genNode(sequence[end], genList(sequence, start, end - 1), NULL));
}
Node *genTree(int sequence[], int start, int end){
    if(end < start) return NULL;
    int idx = find(sequence, start, end);
    if(idx == -1)
        return(genList(sequence, start, end));
    else return(genNode(sequence[idx], genTree(sequence, start, idx - 1), genTree(sequence, idx + 1, end)));
}
Node* ConstructTree(int sequence[], int N){
    return genTree(sequence, 0, N - 1);
}