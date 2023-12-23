#include "node.h"
#include<stdio.h>
typedef struct node NODE;
NODE *getNode(NODE *head, unsigned int i){
    unsigned int n = 0;
    NODE *now = head;
    while(now != NULL){
        n++;
        now = now->next;
    }
    if(i >= n) return NULL;
    
    unsigned int cnt = n - 1;
    now = head;
    while(cnt > i){
        cnt--;
        now = now->next;
    }
    return now;
}