#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 101
#define left(i) 2 * i
#define right(i) 2 * i + 1
#define parent(i) i / 2 
// #define debug
typedef struct{
    int a[MAX * MAX + 1];
    int size;
}heap;
int getID(int r, int c, int l){
    return (r * MAX * MAX + c * MAX + l);
}
int cmp(int id1, int id2, char tower[]){
    return strcmp(&tower[id1], &tower[id2]);
}
int getLargest(heap *h, int i, char tower[]){
    int l = left(i), r = right(i);
    int flag = (l <= h->size && cmp(h->a[l], h->a[i], tower) > 0);
    int largest = l * flag + i * !flag; 
    
    flag = r <= h->size && cmp(h->a[r], h->a[largest], tower) > 0;
    largest = r * flag + largest * !flag;
    return largest;
}
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void maxHeapify(heap *h, int i, char tower[]){
    int largest = getLargest(h, i, tower);
    while(largest != i){
        swap(&(h->a[i]), &(h->a[largest]));
        i = largest;
        largest = getLargest(h, i, tower);
    }
}
void buildMaxHeap(heap *h, char tower[]){
    for(int i = (h->size / 2); i >= 1; i--){
        maxHeapify(h, i, tower);
    }
}
int heapExtractMax(heap *h, char tower[]){
    if(h->size < 1) return -1;
    int max = h->a[1];
    h->a[1] = h->a[h->size];
    h->size -= 1;
    maxHeapify(h, 1, tower);
    return max;
}
void maxHeapInsert(heap *h, int key, char tower[]){
    h->size += 1;
    int i = h->size;
    h->a[i] = key;
    while(i > 1 && cmp((h->a[parent(i)]), (h->a[i]), tower) < 0){
        swap(&(h->a[i]), &(h->a[parent(i)]));
        i = parent(i);
    }
}
int main(){
    int n, m;
    char tower[MAX * MAX * MAX];//m x n x n
    scanf("%d%d", &n, &m);
    getchar();
    for(int l = 0; l < m; l++){
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                int id = getID(r, c, l);
                scanf("%c", &tower[id]);
                tower[id] = (tower[id]) * (tower[id] != '0');
            }
            getchar();
        }
    }//input

    heap *h = (heap *) malloc(sizeof(heap));
    h->size = 0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            int id = getID(r, c, 0);
            maxHeapInsert(h, id, tower);
        }
    }
    while(h->size > 0){
        int max = heapExtractMax(h, tower);
        printf("%s\n", &tower[max]);
        int len = strlen(&tower[max]);
        if(tower[max + len + 1] != '\0'){
            maxHeapInsert(h, max + len + 1 , tower);
        }
    }
    free(h);
    return 0;
}