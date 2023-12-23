#include<stdio.h>
// #define debug
int calRectArea(int N, int M, int* ptrMat, int* ptrLeft[], int* ptrRight[]){
    int len1 = ptrLeft[0]- ptrMat, len2 = ptrRight[0] - ptrMat;
    int x1 = len1 / N, y1 = len1 % N, x2 = len2 / N, y2 = len2 % N;
    int area = (x2 - x1 + 1) * (y2 - y1 + 1);
    #ifdef debug
    printf("(%d, %d) ~ (%d, %d)\n", x1, y1, x2, y2);
    printf("init area = %d\n", area);
    #endif
    int prevx = x2, prevy = y2;
    for(int i = 1; i < M; i++){
        int l1 = ptrLeft[i]- ptrMat;
        int l2 = ptrRight[i] - ptrMat;
        x1 = l1 / N, y1 = l1 % N, x2 = l2 / N, y2 = l2 % N;
        #ifdef debug
        printf("(%d, %d) ~ (%d, %d)\n", x1, y1, x2, y2);
        #endif
        area -= (prevx - x1 + 1) * (prevy - y1 + 1);
        area += (x2 - x1 + 1) * (y2 - y1 + 1);
        prevx = x2, prevy = y2;
    }
    return area;
}