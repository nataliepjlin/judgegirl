#include<stdio.h>
#define DEPTH 1001
#include "node.h"
typedef struct node NODE;
void go(NODE *root, int p, int paths[]){
    paths[p] = root->data;
    #ifdef debug
    printf("paths[%d] = %d\n", p, paths[p]);
    #endif
    if(root->left == NULL && root->right == NULL){
        for(int i = 0; i <= p; i++){
            printf("%d%c", paths[i], " \n"[i == p]);
        }
        return;
    }
    if(root->left != NULL)
        go(root->left, p + 1, paths);
    if(root->right != NULL)
        go(root->right, p + 1, paths);
    return;
}
void print_all_paths(struct node *root){
    int paths[DEPTH];
    go(root, 0, paths);
}