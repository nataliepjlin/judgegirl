#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 1001
#define VARL 33
#define N 50
typedef struct Node{
    char *name;
    struct Node *left, *right;
}Node;
typedef struct Var{
    char name[VARL];
    int v;
}Var;
Node *genNode(char *name, Node *left, Node *right){
    Node *node = malloc(sizeof(Node));
    node->name = name, node->left = left, node->right = right;
    return node;
}
int findVarVal(char *name, Var vars[], int n){
    for(int i = 0; i < n; i++){
        if(!strcmp(name, vars[i].name)){
            return vars[i].v;
        }
    }
    return -1;
}
Node *Build(char *toks[], int *nowt, int totalt, Var vars[], int n){
    if(*nowt >= totalt)
        return NULL;
    if(toks[*nowt][0] == '('){
        *nowt += 1;
        char *op = toks[*nowt];
        *nowt += 1;
        Node *l = Build(toks, nowt, totalt, vars, n), *r = Build(toks, nowt, totalt, vars, n);
        *nowt += 1;
        return genNode(op, l, r);
    }
    else{
        char *num = toks[*nowt];
        *nowt += 1;
        return genNode(num, NULL, NULL);
    }
}
int trav(Node *root, Var vars[], int n){
    if(root == NULL)
        return 0;
    if(isdigit(root->name[0])){
        return atoi(root->name);
    }
    else if(root->name[0] != '+' && root->name[0] != '-'
    && root->name[0] != '*' && root->name[0] != '/'){
        return findVarVal(root->name, vars, n);
    }
    else{
        if(root->name[0] == '+')
            return trav(root->left, vars, n) + trav(root->right, vars, n);
        else if(root->name[0] == '-')
            return trav(root->left, vars, n) - trav(root->right, vars, n);
        else if(root->name[0] == '*')
            return trav(root->left, vars, n) * trav(root->right, vars, n);
        else return trav(root->left, vars, n) / trav(root->right, vars, n);
    }
}
int main(){
    char input[LEN]; fgets(input, LEN, stdin);
    input[strlen(input) - 1] = 0;
    //tokenize
    char *toks[LEN]; 
    int t = 0;
    char del[] = " ";
    char *tok = strtok(input, del);
    while(tok != NULL){
        #ifdef debug
        printf("tok = %s\n", tok);
        #endif
        toks[t++] = tok;
        tok = strtok(NULL, del);
    }
    //
    Var vars[N]; int n = 0;
    while(scanf("%s = %d", vars[n].name, &vars[n].v) == 2){
        n++;
    }
    int nowt = 0;
    Node *root = Build(toks, &nowt, t, vars, n);
    int v = trav(root, vars, n);
    printf("%d\n", v);
}