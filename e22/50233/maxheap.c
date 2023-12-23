#include<stdio.h>
int PARENT(int i){
    return i / 2;
}
int LEFT(int i){
    return 2 * i;
}
int RIGHT(int i){
    return 2 * i + 1;
}
int getLargest(int A[], int i, int heapSize){
    int l = LEFT(i), r = RIGHT(i);
    int largest;

    if(l <= heapSize && A[l] > A[i])
        largest = l;
    else largest = i;

    if(r <= heapSize && A[r] > A[largest])
        largest = r;

    return largest;
}

void maxHeapify(int A[], int i, int heapSize){
    int largest = getLargest(A, i, heapSize);
    while(largest != i){
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;

        i = largest;
        largest = getLargest(A, i, heapSize);
    }
}

void buildMaxHeap(int A[], int heapSize){
    for(int i = heapSize / 2; i >= 1; i--){
        maxHeapify(A, i, heapSize);
    }
}

int heapExtractMax(int A[], int heapSize){
    if(heapSize < 1) return -1;

    int max = A[1];
    A[1] = A[heapSize];
    heapSize --;
    maxHeapify(A, 1, heapSize);
    return max;
}

void MaxHeapInsert(int A[], int key, int heapSize){
    heapSize ++;
    int i = heapSize;
    A[i] = key;
    // printf("A[%d] = %d\n", i, A[i]);
    while(i > 1 && A[PARENT(i)] < A[i]){
        int tmp = A[i];
        A[i] = A[PARENT(i)];
        A[PARENT(i)] = tmp;

        i = PARENT(i);
        // printf("now i = %d\n", i);
    }
}

int main(){
    int n;
    int arr[300001];
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }

    buildMaxHeap(arr, n);

    for(int i = 1; i <= n; i++){
        (i == n) ? printf("%d\n", arr[i]) : printf("%d ", arr[i]);
    }

    int m, ope, first = 1;
    scanf("%d", &m);
    while(m --){
        scanf("%d", &ope);
        if(ope == -1){
            int max = heapExtractMax(arr, n);
            if(max != -1){
                n --;
                // printf("remove %d from arr, now heapSize = %d\n", max, n);
                if(first){
                    printf("%d", max);
                    first = 0;
                }
                else printf(" %d", max);
            }
        }
        else{
            MaxHeapInsert(arr, ope, n);
            n ++;
        }
    }

    printf("\n");
    return 0;
}