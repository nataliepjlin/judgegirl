#include "node.h"
#include<stdio.h>
NODE *merge(NODE *list1, NODE *list2){
    while(list2 != NULL){
        NODE *ptr1 = list1, *last = NULL;
        NODE *ptr2 = list2;
        list2 = list2->next;
        #ifdef debug
        printf("ptr1 = %d, ptr2 = %d\n", ptr1->value, ptr2->value);
        #endif
        while(ptr1 != NULL && ptr1->value < ptr2->value){
            last = ptr1;
            ptr1 = ptr1->next;
        }
        if(last == NULL){
            ptr2->next = list1;
            list1 = ptr2;
            #ifdef debug
            printf("%d %d %d\n", list1->value, list1->next->value, list1->next->next->value);
            #endif
        }
        else{
            ptr2->next = last->next;
            last->next = ptr2;
        }
    }
    return list1;
}