#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE *left, *right;
}NODE;
void inorder(NODE *root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d\n", root->data);
    inorder(root->right);
    return;
}
void preorder(NODE *root){
    if(root == NULL)
        return;
    printf("%d\n", root->data);
    preorder(root->left);
    preorder(root->right);
    return;
}
void postorder(NODE *root){
    if(root == NULL)
        return;
    inorder(root->left);
    inorder(root->right);
    printf("%d\n", root->data);
    return;
}
NODE *insert(NODE *root, int data){
    NODE *now;
    if(root == NULL){
        now = (NODE *)malloc(sizeof(NODE));
        now->data = data;
        now->left = now->right = NULL;
        return now;
    }
    else{
        if(data < root->data){
            root->left = insert(root->left, data);
        }
        else{
            root->right = insert(root->right, data);
        }

        return root;
    }
}
#define N 5
int main(){
    int data;
    NODE *root = NULL;
    for(int i = 0; i < N; i++){
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("inorder\n");
    inorder(root);
    printf("preorder\n");
    preorder(root);
    printf("postorder\n");
    postorder(root);
}