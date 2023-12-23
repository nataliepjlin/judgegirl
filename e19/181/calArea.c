#include "calArea.h"
int calArea(NODE* head){
    NODE *ptrr = head, *ptrd = head;
    int sum = 0;
    int r = 0, d = 0;
    while(ptrr->rightPtr != NULL){
        r++;
        #ifdef debug
        printf("r = %d\n", r);
        #endif
        ptrr = ptrr->rightPtr;
    }
    while(r != d){
        sum += (r - d);
        ptrr = ptrr->downPtr, ptrd = ptrd->downPtr;
        while(ptrr->rightPtr != NULL){
            ptrr = ptrr->rightPtr;
            r++;
        }
        while(ptrd->rightPtr != NULL){
            ptrd = ptrd->rightPtr;
            d++;
        }
    }
    return sum;
}