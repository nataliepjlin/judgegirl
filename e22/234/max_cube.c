#include<stdio.h>
#include<string.h>
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b; *b = tmp;
}

int PARENT(int i){
    return i / 2;
}
int LEFT(int i){
    return 2 * i;
}
int RIGHT(int i){
    return 2 * i + 1;
}
int getLargest(int A[][3], int i, int heapSize){
    int l = LEFT(i), r = RIGHT(i);
    int largest;

    if(l <= heapSize && A[l][0] > A[i][0]) largest = l;
    else largest = i;

    if(r <= heapSize && A[r][0] > A[largest][0]) largest = r;

    return largest;
}
int maxHeapify(int A[][3], int i, int heapSize){
    int largest = getLargest(A, i, heapSize);
    while(largest != i){
        swap(&A[i][0], &A[largest][0]);
        swap(&A[i][1], &A[largest][1]);
        swap(&A[i][2], &A[largest][2]);

        i = largest;
        largest = getLargest(A, i, heapSize); 
    }
}
void buildMaxHeap(int A[][3], int heapSize){
    for(int i = heapSize / 2; i >= 1; i--){
        maxHeapify(A, i, heapSize);
    }
}

void heapExtractMax(int A[][3], int heapSize, int maxrc[3]){
    maxrc[0] = A[1][0]; maxrc[1] = A[1][1]; maxrc[2] = A[1][2];
    A[1][0] = A[heapSize][0];
    A[1][1] = A[heapSize][1];
    A[1][2] = A[heapSize][2];
    heapSize --;
    maxHeapify(A, 1, heapSize);
}

void maxHeapInsert(int A[][3], int key, int keyr, int keyc, int heapSize){
    heapSize ++;
    int i = heapSize;
    A[i][0] = key;
    A[i][1] = keyr;
    A[i][2] = keyc;

    while(i > 1 && A[PARENT(i)][0] < A[i][0]){
        swap(&A[i][0], &A[PARENT(i)][0]);
        swap(&A[i][1], &A[PARENT(i)][1]);
        swap(&A[i][2], &A[PARENT(i)][2]);
        i = PARENT(i);
    }
}



int main(){
    int elements[10201][3];
    int arr[101][101][101]; int layers[101][101] = {{0}};
    int tops[101][101]; 
    int n;
    scanf("%d", &n);

    memset(tops, -1, sizeof(tops));
    int len = 1;
    int maxrc[3] = {0, -1, -1};

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= i; k++){
                scanf("%d", &arr[i][j][k]);
                if(tops[j][k] == -1){
                    tops[j][k] = elements[len][0] = arr[i][j][k]; 
                    elements[len][1] = j, elements[len][2] = k;
                    len ++;
                    layers[j][k] = i;
                }
            }
        }
        // printf("\n");
    }// i < n

    len --;
    buildMaxHeap(elements, len);

    int cubes = (n * (n + 1) * (2 * n + 1)) / 6;
    for(int i = 1; i <= cubes; i++){
        heapExtractMax(elements, len, maxrc);
        len --;
        printf("%d%c", maxrc[0], " \n"[i == cubes]);
        layers[maxrc[1]][maxrc[2]] ++;
        if(layers[maxrc[1]][maxrc[2]] < n){
            maxHeapInsert(elements, arr[layers[maxrc[1]][maxrc[2]]][maxrc[1]][maxrc[2]], maxrc[1], maxrc[2], len);
            len ++;
        }
        else{
            buildMaxHeap(elements, len);
        }
    }
    return 0;
}