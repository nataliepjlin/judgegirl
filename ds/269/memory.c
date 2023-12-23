#include "memory.h"
#include "assert.h"
//https://judgegirl.csie.org/source/highlight/547529
int TAIL(Memory *memory){
    return(memory->start + memory->length);
}
void initMemory(Memory *memory, int length){
    memory->start = 0;
    memory->length = length;
    memory->next = NULL;
    return;
}
void printMemory(Memory *memory){
    Memory* now = memory;
    printf("==========\n");
    while(now != NULL){
        (now->length != 0
        && (printf("start %d, length %d\n", now->start, now->length)));
        now = now->next;
    }
    return;
}
void allocateMemory(Memory *memory, int start, int length){
    Memory *now = memory, *prev = NULL;
    while(!(now->start <= start && (start + length) <= TAIL(now))){
        #ifdef debug
        printf("now: %d ~ %d\n", now->start, TAIL(now));
        #endif
        prev = now;
        now = now->next;
        // assert(now != NULL);
    }
    // assert(now->start <= start && (start + length) <= TAIL(now));
    int samehead = (start == now->start);
    int sametail = (start + length == TAIL(now));
    if(samehead && sametail){
        if(prev != NULL) prev->next = now->next;
        else if(now == memory) memory->length = 0;
        else *memory = *(now->next);
    }
    else if(samehead){
        now->start += length;
        now->length -= length;
    }
    else if(sametail){
        now->length -= length;
    }
    else{
        Memory *after = (Memory*)malloc(sizeof(Memory));
        after->start = start + length, after->length = TAIL(now) - after->start;
        after->next = now ->next, now->next = after, now->length = start - now->start;
    }
}
void freeMemory(Memory *memory, int start, int length){
    Memory *prev = NULL, *now = memory;
    while(now != NULL && (start > now->start)){
        prev = now;
        now = now->next;
    }
    int prevtail_overlap = (prev != NULL && (start == TAIL(prev)));
    int nowhead_overlap = (now != NULL && (start + length == now->start));
    if(prevtail_overlap && nowhead_overlap){
        prev->length += (length + now->length);
        prev->next = now->next;
        free(now);
    }
    else if(prevtail_overlap) prev->length += length;
    else if(nowhead_overlap){
        now->start = start;
        now->length += length;
    }
    else{
        Memory *mid = (Memory*)malloc(sizeof(Memory));
        mid->start = start, mid->length = length, mid->next = now;
        if(prev == NULL) *memory = *mid;
        else prev->next = mid;
    }
}