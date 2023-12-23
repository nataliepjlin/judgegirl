#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 102
#define LEFT(n) (2 * n)
#define RIGHT(n) (2 * n + 1)
#define PARENT(n) (n / 2)
#define debug
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int getId(int r, int c, int l){
    return (MAX * MAX * r + MAX * c + l);
}
int cmpId(int id1, int id2, char tower[]){
    #ifdef debug
    printf("cmping '%s' '%s'\n", &tower[id1], &tower[id2]);
    #endif
    return strcmp(&tower[id1], &tower[id2]);
}
typedef struct{
    int a[MAX * MAX + 1];
    int size;
}heap;
int getLargest(heap *h, int i, char tower[]){
    int l = LEFT(i), r = RIGHT(i);
    int largest;
    if(l <= h->size && cmpId(h->a[l], h->a[i], tower) > 0){
        largest = l;
    }
    else{
        largest = i;
    }

    if(r <= h->size && cmpId(h->a[r], h->a[largest], tower) > 0){
        largest = r;
    }
    return largest;
}

void MaxHeapify(heap *h, int i, char tower[]){
    int largest = getLargest(h, i, tower);
    while(largest != i){
        swap(&(h->a[i]), &(h->a[largest]));
        i = largest;
        largest = getLargest(h, i, tower);
    }
}
void buildMaxHeap(heap *h, char tower[]){
    for(int i = (h->size / 2); i >= 1; i--){
        MaxHeapify(h, i, tower);
    }
}
int heapExtractMax(heap *h, char tower[]){
    if(h->size < 1)
        return -1;
    int max = h->a[1];
    h->a[1] = h->a[h->size];
    h->size -= 1;
    MaxHeapify(h, 1, tower);
    return max;
}
void MaxHeapInsert(heap *h, int key, char tower[]){
    h->size += 1;
    int i = h->size;
    h->a[i] = key;
    while(i > 1 && cmpId(h->a[PARENT(i)], h->a[i], tower) < 0){
        swap(&(h->a[i]), &(h->a[PARENT(i)]));
        i = PARENT(i);
    }
}

int main(){
    int n, m;
    char tower[MAX * MAX * MAX] = {0};
    scanf("%d%d", &n, &m);
    getchar();//for line break
    for(int l = 0; l < m; l++){
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                int id = getId(r, c, l);
                scanf("%c", &tower[id]);
                tower[id] = '\0' * (tower[id] == '0')
                        + tower[id] * (tower[id] != '0');
            }
            getchar();//for line break
        }
    }//input
    
    heap *h = (heap *) malloc(sizeof(heap));
    h->size = 0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            int id = getId(r, c, 0);
            MaxHeapInsert(h, id, tower);
        }
    }
    while(h->size != 0){
        int maxId = heapExtractMax(h, tower);
        int len = strlen(&tower[maxId]);
        printf("%s\n", &tower[maxId]);
        if(tower[maxId + len + 1] != '\0'){
            MaxHeapInsert(h, maxId + len + 1, tower);
        }
    }
    free(h);
    return 0;
}