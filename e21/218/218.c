#include<stdio.h>
#include<stdlib.h>
struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
};
 
struct list {
    struct treenode *head;
    struct treenode *tail;
};
 
typedef struct treenode TreeNode;
typedef struct list List;
List root2list(TreeNode *root){
    List list;
    list.head = list.tail = root;
    list.head->right = list.tail->right = NULL;
    return list;
}
List cat(List a, List b){
    if(a.head == NULL)
        return b;
    else if(b.head == NULL)
        return a;
    List c;
    c.head = a.head;
    a.tail->left = b.head;
    c.tail = b.tail;
    return c;
}
List treeToListFunc(TreeNode * root){
    if(root == NULL){
        List null;
        null.head = null.tail = NULL;
        return null;
    }
    List l = treeToListFunc(root->left);
    List r = treeToListFunc(root->right);
    if(root->value % 2){
        return cat(root2list(root), cat(r, l));
    }
    else return cat(root2list(root), cat(l, r));
}