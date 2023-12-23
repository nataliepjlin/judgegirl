#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define N 1024
typedef struct KEY{
    int val, lv;
}KEY;
typedef struct NODE{
    int val, lv;
    struct NODE *left, *right;
}NODE;
int cmp(const void *a, const void *b){
    KEY *ka = (KEY *)a, *kb = (KEY *)b;
    return ka->lv - kb->lv;
}
NODE* insert(NODE *root, KEY *key){
    if(root == NULL){
        NODE *new = (NODE*)malloc(sizeof(NODE));
        new->val = key->val, new->lv = key->lv;
        new->left = new->right = NULL;
        return new;
    }
    else{
        if(key->val > root->val)
            root->right = insert(root->right, key);
        else
            root->left = insert(root->left, key);
        return root;
    }
}
int find(NODE *root, const int val){
    NODE *cur = root;
    while(cur != NULL){
        if(cur->val == val){
            #ifdef debug
            printf("found cur->val = %d, cur->lv = %d\n", cur->val, cur->lv);
            #endif
            return cur->lv;
        }
        cur = (val > cur->val) ? cur->right : cur->left;
    }
    return -1;
}
void dist(NODE *root, const int x, const int y){
    assert(root != NULL);
    if(y < root->val) dist(root->left, x, y);
    else if(x > root->val) dist(root->right, x, y);
    else{
        assert(x <= root->val && root->val <= y);
        int xlv = find(root, x), ylv = find(root, y);
        assert(xlv != -1 && ylv != -1);
        printf("%d\n", (xlv - root->lv) + (ylv - root->lv));
    }
}
int min(int a, int b){
    return(a * (a < b) + b * (a >= b));
}
int max(int a, int b){
    return(a * (a > b) + b * (a <= b));
}
int main(){
    KEY keys[N];
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &keys[i].val, &keys[i].lv);
    }
    qsort(keys, n, sizeof(KEY), cmp);
 
    NODE *root = NULL;
    for(int i = 0; i < n; i++){
        root = insert(root, &keys[i]);
    }
    int q; scanf("%d", &q);
    int tx, ty;
    int x, y;
    for(int i = 0; i < q; i++){
        scanf("%d%d", &tx, &ty);
        x = min(tx, ty), y = max(tx, ty);
        dist(root, x, y);
    }
}