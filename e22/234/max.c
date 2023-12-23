#include<stdio.h>
#include<stdlib.h>
// #define debug
#define MAXN 100
#define left(i) 2 * i
#define right(i) 2 * i + 1
#define parent(i) i / 2
typedef struct{
    int a[MAXN * MAXN * MAXN];
    int id[MAXN * MAXN * MAXN];
    int size;
}heap;
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
int getLargest(heap *h, int i){
    int l = left(i), r = right(i);
    int largest;
    if(l <= h->size && (h->a[l] > h->a[i])){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r <= h->size && (h->a[r] > h->a[largest])){
        largest = r;
    }
    return largest;
}
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void maxHeapify(heap *h, int i){
    int largest = getLargest(h, i);
    while(largest != i){
        swap(&(h->a[i]), &(h->a[largest]));
        swap(&(h->id[i]), &(h->id[largest]));
        i = largest;
        largest = getLargest(h, i);
    }
}
void buildMaxHeap(heap *h){
    for(int i = (h->size / 2); i >= 1; i--){
        maxHeapify(h, i);
    }
}
void MaxHeapInsert(heap *h, int key, int id){
    h->size += 1;
    int i = h->size;
    h->a[i] = key;
    h->id[i] = id;
    while(i > 1 && (h->a[parent(i)] < h->a[i])){
        swap(&(h->a[i]), &(h->a[parent(i)]));
        swap(&(h->id[i]), &(h->id[parent(i)]));
        i = parent(i);
    }
}
int heapExtractMax(heap *h){
    if(h->size < 1)
        return -1;
    int max = h->id[1];
    h->a[1] = h->a[h->size];
    h->id[1] = h->id[h->size];
    h->size -= 1;
    maxHeapify(h, 1);
    return max;
}
int main(){
    int n;
    scanf("%d", &n);
    int tower[MAXN][MAXN][MAXN];
    for(int l = 0; l < n; l++){
        for(int r = 0; r <= l; r++){
            for(int c = 0; c <= l; c++){
                scanf("%d", &tower[l][r][c]);
            }
        }
    }
    heap *h = (heap *) malloc(sizeof(heap));
    h->size = 0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            MaxHeapInsert(h, tower[max(r, c)][r][c], max(r, c) * (n * n) + r * n + c);
        }
    }
    while(h->size != 0){
        int maxId = heapExtractMax(h);
        int l = maxId / (n * n), r = (maxId % (n * n)) / n, c = maxId % n;
        printf("%d ", tower[l][r][c]);
        if(l + 1 < n){
            MaxHeapInsert(h, tower[l + 1][r][c], (l + 1) * n * n + r * n + c);
        }
    }
    free(h);
    return 0;
}