#include<stdio.h>
#include<stdlib.h>
typedef struct LISTNODE{
    int data;
    struct LISTNODE *next;
}LISTNODE;
void print(LISTNODE *node){
    if(node == NULL) return;
    
    printf("%d\n", node->data);
    print(node->next);
}
LISTNODE *insert(int data, LISTNODE *head){//returning new head
    LISTNODE *now = (LISTNODE *)malloc(sizeof(LISTNODE));
    now->data = data;
    if(head == NULL || data < head->data){// `now` as new head
        now->next = head;
        return now;
    }
    head->next = insert(data, head->next);// the list after `head` may be modified, need to update
    return head;
}
void freeNode(LISTNODE *node){
    if(node == NULL)
        return;
    
    LISTNODE *next = node->next;
    free(node);
    freeNode(next);
}
LISTNODE *del(LISTNODE *head, int data){
    if(head == NULL)
        return NULL;

    LISTNODE *tmp;
    if(head->data == data){
        tmp = head->next;
        free(head);
        return tmp;
    }
    head->next = del(head->next, data);
    return head;
}
#define SIZE 5
#define DEL 3
int main(){
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++){
        scanf("%d", &arr[i]);
    }
    LISTNODE *head = NULL;
    for(int i = 0; i < SIZE; i++){
        head = insert(arr[i], head);
    }
    print(head);
    printf("\n");
    
    int dkey;
    for(int i = 0; i < DEL; i++){
        scanf("%d", &dkey);
        head = del(head, dkey);
    }
    print(head);
    freeNode(head);
}
