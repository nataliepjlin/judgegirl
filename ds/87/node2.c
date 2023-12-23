#include "node.h"
#include<stdio.h>
NODE *merge(NODE *list1, NODE *list2){
    if(list1 == NULL)
        return list2;
    else if(list2 == NULL)
        return list1;  
    if(list1->value < list2->value){
        list1->next = merge(list1->next, list2);
        return list1;
    }
    else{
        list2->next = merge(list1, list2->next);
        return list2;
    }
}