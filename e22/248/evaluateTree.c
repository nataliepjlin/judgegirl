#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<assert.h>
#define MAXT 500001
#include "evaluateTree.h"
int trav(Node *root, int *values){
    if(root == NULL)
        return 0;
    int l, r;
    if(isalpha(root->val[0])){
        return values[root->val[0] - 'A'];
    }
    else if(root->val[0] == '!'){
        return !trav(root->left, values);
    }
    else{
        l = trav(root->left, values), r = trav(root->right, values);
        return (root->val[0] == '|') ? (l || r) : (l && r);
    }
}
void evaluateTree(Node *root, int *values){
    if(root == NULL) return;
    if(trav(root, values)){
        #ifdef UPPER
        printf("TRUE\n");
        #endif
        #ifdef LOWER
        printf("true\n");
        #endif
    }
    else{
        #ifdef UPPER
        printf("FALSE\n");
        #endif
        #ifdef LOWER
        printf("false\n");
        #endif
    }
    return;
}