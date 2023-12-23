#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<assert.h>
#include "evaluateTree.h"
#define MAXT 500001
typedef struct info{
    Node *ptr;
    int next;
}info;
Node* genNode(char* val, Node* left, Node* right){
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = left, node->right = right;
    return node;
}
info treeNode(char *toks[], int nowt, int totalt){
    if(nowt >= totalt) return (info){NULL, 0};
    
    if(isalpha(toks[nowt][0])){
        return (info){genNode(toks[nowt], NULL, NULL), nowt + 1};
    }
    else if(toks[nowt][0] == '!'){
        info after = treeNode(toks, nowt + 1, totalt);
        return (info){genNode(toks[nowt], after.ptr, NULL), after.next};
    }
    else if(toks[nowt][0] == '('){
        nowt++;
        info l, r;
        char *op;
        l = treeNode(toks, nowt, totalt);
        op = toks[l.next];
        r = treeNode(toks, l.next + 1, totalt);
        #ifdef debug
        printf("l = %s, op = %s, r = %s\n", l.ptr->val, op, r.ptr->val);
        #endif
        return(info){genNode(op, l.ptr, r.ptr), r.next + 1};
    }
}
Node* buildTree(char* expr){
    char delims[] = " \n";
    char *toks[MAXT]; int t = 0;
    char *tok = strtok(expr, delims);
    while(tok != NULL){
        toks[t] = tok;
        t++;
        tok = strtok(NULL, delims);
    }
    return treeNode(toks, 0, t).ptr;
}
Node* buildTree(char* expr);
int main(){
    char expr[1000001];
    int values[] = {1, 0, 0};
    while(fgets(expr, 1000001, stdin)){
        Node *root = buildTree(expr);
        evaluateTree(root, values);
    }
}