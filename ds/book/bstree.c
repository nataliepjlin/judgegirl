#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int val;
    struct NODE *left, *right;
} NODE;
void print(NODE *root){
    if(root == NULL)
        return;

    print(root->left);
    printf("%d\n", root->val);
    print(root->right);
    return;
}
NODE *insert(NODE *root, int val){
    NODE *now;
    if(root == NULL){
        now = (NODE *)malloc(sizeof(NODE));
        now->val = val;
        now->left = NULL, now->right = NULL;
        return now;
    }
    else{
        if(val < root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
            
        return root;
    }
}
#define N 5
int main(){
    int keys[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &keys[i]);
    }
    NODE *root = NULL;
    for(int i = 0; i < N; i++){
        root = insert(root, keys[i]);
    }
    print(root);
}