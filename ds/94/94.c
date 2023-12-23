#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define LEN 4001
typedef struct NODE{
    int val;
    struct NODE *left, *right;
}NODE;
NODE *gen(char *str, int *i){
    #ifdef debug
    printf("i = %p\n", i);
    #endif
    if(str[*i] == '('){
        *i += 1;
        NODE *node = (NODE *)malloc(sizeof(NODE));
        node->left = gen(str, i);
        node->right = gen(str, i);
        #ifdef debug
        printf("left val = %d, right val = %d\n", node->left->val, node->right->val);
        #endif
        node->val = node->left->val + node->right->val;
        return node;
    }
    else if(str[*i] == ',' || str[*i] == ')'){
        *i += 1;
        return gen(str, i);
    }
    else{
        int val = 0;
        while(isdigit(str[*i])){
            val = val * 10 + (str[*i] - '0');
            *i += 1;
        }
        #ifdef debug
        printf("val = %d\n", val);
        #endif
        NODE *node = (NODE *)malloc(sizeof(NODE));
        node->left = NULL, node->right = NULL;
        node->val = val;
        return node;
    }
}
void traverse(NODE *root, int dir){
    if(root == NULL) return;
    if(dir){
        printf("%d\n", root->val);
        traverse(root->left, !dir);
        printf("%d\n", root->val);
        traverse(root->right, !dir);
    }
    else{
        printf("%d\n", root->val);
        traverse(root->right, !dir);
        printf("%d\n", root->val);
        traverse(root->left, !dir);
    }
}
int main(){
    char str[LEN];
    scanf("%s", str);
    #ifdef debug
    printf("str = %s\n", str);
    #endif
    int i = 0;
    NODE *root = gen(str, &i);
    traverse(root, 1);
    return 0;
}