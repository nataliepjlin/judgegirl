#include<assert.h>
#include<stdio.h>
#define MAXHEAP 100
struct Heap{
    int ary[MAXHEAP];
    int num;
};
int isFull(struct Heap *heap){
    return(heap->num == MAXHEAP);
}
int isEmpty(struct Heap *heap){
    return(heap->num == 0);
}
void initialize(struct Heap *heap){
    heap->num = 0;
}
int removeMin(struct Heap *heap){
    if(!isEmpty(heap)){
        int min = heap->ary[heap->num - 1];
        heap->num -= 1;
        return min;
    }
}
void add(struct Heap *heap, int i){
    if(!isFull(heap)){
        for(int idx = 0; idx < heap->num; idx++){
            if(i > heap->ary[idx]){
                for(int j = (heap->num) - 1; j >= idx; j--){
                    heap->ary[j + 1] = heap->ary[j];
                }
                heap->ary[idx] = i;
                heap->num ++;
                return;
            }
        }
        heap->ary[heap->num] = i;
        heap->num ++;
    }
    return;
}