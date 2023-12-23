#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#define LEN 1001
#define VLEN 33
#define N 51
typedef struct VAR{
    char name[VLEN];
    int val;
}VAR;
typedef struct NODE{
    char op[VLEN];
    struct NODE *left, *right;
}NODE;
NODE *build(){
    NODE *root = (NODE *)malloc(sizeof(NODE));
    root->left = root->right = NULL;
    
    char op[VLEN]; scanf("%s", op);
    #ifdef debug
    printf("op = %s, ", op);
    #endif
    if(op[0] == '('){
        #ifdef debug
        printf("get operator\n");
        #endif
        scanf("%s", root->op); //operator
        #ifdef debug
        printf("left tree\n");
        #endif
        root->left = build(root->left);
        #ifdef debug
        printf("right tree\n");
        #endif
        root->right = build(root->right);
        scanf("%s", op); // )
    }
    else{
        #ifdef debug
        printf("copy to root\n");
        #endif
        strcpy(root->op, op);
    }
    return root;
}
int eval(NODE *root, VAR var[], int n){
    if(root->op[0] == '+')
        return(eval(root->left, var, n) + eval(root->right, var, n));
    else if(root->op[0] == '-')
        return(eval(root->left, var, n) - eval(root->right, var, n));
    else if(root->op[0] == '*')
        return(eval(root->left, var, n) * eval(root->right, var, n));
    else if (root->op[0] == '/')
        return(eval(root->left, var, n) / eval(root->right, var, n));
    else{
        if(isdigit(root->op[0]))
            return atoi(root->op);
        else{
            int f = 0;
            for(int i = 0; i < n; i++){
                if(!strcmp(root->op, var[i].name)){
                    f = 1;
                    return var[i].val;
                }  
            }
            assert(f);
        }
    }
}
int main(){
    NODE *root = build();
    VAR var[N];
    int n = 0;
    while(scanf("%s = %d", var[n].name, &var[n].val) != EOF){
        #ifdef debug
        printf("var[%d].name = %s, var[%d].val = %d\n", n, var[n].name, n, var[n].val);
        #endif
        n++;
    }
    printf("%d\n", eval(root, var, n));
}