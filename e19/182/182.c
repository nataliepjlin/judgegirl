#include<stdio.h>
#include<stdlib.h> 
#define second(n) n / 2
#define first(n) n - second(n)
typedef struct Node{
    int val;
    struct Node *left, *right;
}Node;
int counter(Node *list){
    int cnt = 0;
    Node *now = list;
    while(now != NULL){
        cnt++;
        now = now->left;
    }
    return cnt;
}
Node *node2generator(Node *old, const int skipcnt){
    for(int i = 0; i < skipcnt - 1; i++){
        old = old->left;
    }
    Node *node2 = old->left;
    old->left = NULL;
    return node2;
}
void split(Node* old, Node** n1, Node** n2, const int cnt){
    if(old == NULL){
        *n1 = *n2 = NULL;
        return;
    }
    *n1 = old;
    *n2 = node2generator(old, first(cnt));
    return;    
}
Node* BuildTree(Node* list1, Node* list2){
    if(list1 == NULL && list2 == NULL){
        return NULL;
    }
    else if(list1 == NULL)
        return list2;
    else if(list2 == NULL)
        return list1;
    
    Node *root;
    if(list1->val < list2->val){
        root = list1;
        list1 = list1->left;
    }
    else{
        root = list2;
        list2 = list2->left;
    }
    int cnt1 = counter(list1), cnt2 = counter(list2);
    Node *l1n1, *l1n2, *l2n1, *l2n2;
    split(list1, &l1n1, &l1n2, cnt1);
    split(list2, &l2n1, &l2n2, cnt2);
    root->left = BuildTree(l1n1, l2n1);
    root->right = BuildTree(l1n2, l2n2);
    return root;
}