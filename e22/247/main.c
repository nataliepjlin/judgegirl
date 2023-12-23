#include<stdio.h>
#include<string.h>
typedef struct Node
{
    char* val;
    struct Node *left, *right;
} Node;
void print(Node* node){
    if(node == NULL)
        return;
    print(node->left);
    printf("%s", node->val);
    print(node->right);
    return;
}
Node* buildTree(char* expr);
int main(){
    char expr[1000001];
    while(fgets(expr, 1000001, stdin)){
        Node *root = buildTree(expr);
        print(root);
        printf("\n");
    }
}