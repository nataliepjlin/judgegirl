#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
typedef struct Node{
    int value;
    struct Node *left, *right;
} Node;
Node* genNode(Node *left, Node *right, int val){
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = val;
    node->left = left, node->right = right;
    return node;
}
int balancing(int start, int end, int T[]){
    if(end - start < 2)
        return -1;
    uint64_t mx = 0, m = 0;
    for(int i = start; i <= end; i++){
        m += T[i];
        mx += T[i] * i;
    }
    if(mx % m == 0)
        return mx / m;
    return -1;
}
Node *genList(int T[], int N, int start, int end){
    if(end < start)
        return NULL;
    return(genNode(genList(T, N, start, end - 1), NULL, T[end]));
}
Node *genTree(int T[], int N, int start, int end){
    if(end < start)
        return NULL;
    int balance = balancing(start, end, T);
    if(balance == -1)
        return genList(T, N, start, end);
    else
        return(genNode(genTree(T, N, start, balance - 1), genTree(T, N, balance + 1, end), T[balance]));
}
Node *ConstructTree(int T[], int N){
    return(genTree(T, N, 0, N - 1));
}