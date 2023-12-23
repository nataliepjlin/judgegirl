#include<stdio.h>
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;
 
void visit(Node* node, const Node* base){
    if(node == NULL) return;
    node->value += 1;
    #ifdef debug
    printf("idx = %d, val = %d\n", (int)(node - base), node->value);
    #endif
    visit(node->left, base);
    visit(node->right, base);
}
void build_Pascal(Node* arr, int height){
    int n = height * (height + 1) / 2;
    for(int i = 0; i < n; i++){
        arr[i].value = 0;
    }
    int d = height, cnt = 0;
    for(int i = 0; i < n - 1; i++){
        arr[i].right = &arr[i + 1];
        
        if(i + d < n)
            arr[i].left = &arr[i + d];
        cnt++;
        if(cnt == d)
            cnt = 0, d--;
    }
    int btm = n - 1;
    for(int i = 0; i < height; i++){
        btm -= i;
        #ifdef debug
        printf("btm = %d\n", btm);
        #endif
        arr[btm].left = NULL, arr[btm].right = NULL;
    }
    visit(&arr[0], &arr[0]);
}