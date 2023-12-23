#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define N 10
typedef struct NODE{
    int v;
    struct NODE *left, *right;
}NODE;
int find(int arr[], int num, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == num)
            return i;
    }
    return -1;
}
NODE *recon(int n, int post[], int in[]){
    if(n <= 0) return NULL;

    #ifdef debug
    printf("post[0] = %d\n", post[0]);
    #endif
    int leftn = find(in, post[0], n);
    assert(leftn != -1);
    
    int rightn = n - leftn - 1;
    #ifdef debug
    printf("n = %d, leftn = %d, rightn = %d\n", n, leftn, rightn);
    #endif
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->v = post[0];
    node->right = recon(rightn, post + 1, in + leftn + 1);
    node->left = recon(leftn, post + 1 + rightn, in);
    return node;
}
void pre(NODE *root){
    if(root == NULL)
        return;
    printf("%d\n", root->v);
    pre(root->left);
    pre(root->right);
    return;
}
void swap(int *a, int *b){
    int t = *a; *a = *b, *b = t;
}
void flip(int arr[]){
    for(int i = 0; i < N / 2; i++){
        swap(&arr[i], &arr[N - 1 - i]);
    }
}
int main(){
    int post[N], in[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &post[i]);
    }
    flip(post);
    for(int i = 0; i < N; i++){
        printf("%d ", post[i]);
    }
    printf("\n");
    for(int i = 0; i < N; i++){
        scanf("%d", &in[i]);
    }
    NODE *node = recon(N, post, in);
    pre(node);
    return 0;
}