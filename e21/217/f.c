#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct listnode {
    int data;
    struct listnode *next;
    struct listnode *prev;
} ListNode;
 
typedef struct linkedlist{
    struct listnode *head;
    struct listnode *tail;
} LinkedList;

ListNode* gen(int data, ListNode* prev, ListNode* next){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->prev = node->next = NULL;
    return node;
}
void insert(LinkedList *list, int data){
    ListNode *node = gen(data, NULL, NULL);
    if(list->head == NULL && list->tail == NULL){
        list->head = list->tail = node;
    }
    else{
        ListNode *tmp = list->head;
        ListNode *prev = NULL;
        while(tmp != NULL && tmp->data < data){
            prev = tmp;
            tmp = tmp->next;
        }
        if(prev == NULL){
            node->next = list->head;
            list->head->prev = node;
            list->head = node;
        }
        else{
            node->next = prev->next;
            node->prev = prev;
            prev->next = node;
            if(tmp != NULL){
                tmp->prev = node;
            }
            else{
                list->tail = node;
            }
        }
    }
}
void delete_head(LinkedList *list){
    list->head = list->head->next;
    if(list->head != NULL)
        list->head->prev = NULL;
    else
        list->tail = NULL;
    return;
}
void delete_tail(LinkedList *list){
    list->tail = list->tail->prev;
    if(list->tail != NULL)
        list->tail->next = NULL;
    else
        list->head = NULL;
    return;
}