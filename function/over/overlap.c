#include<stdio.h>
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void findMid(int a, int b, int c, int d, int mids[2]){
    int arr[4] = {a, b, c, d};
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 4 - i - 1; j++){
            if(arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
        }
    }
    mids[0] = arr[1], mids[1] = arr[2];
}
int overlap(int x[3][2], int y[3][2], int a, int b){
    return ((x[a][0] < x[b][1]) && (x[a][1] > x[b][0]) && (y[a][0] < y[b][1]) && (y[a][1] > y[b][0]));
}
int overlap3(int x[3][2], int y[3][2], int a, int left, int right, int bottom, int top){
    return ((x[a][0] < right) && (x[a][1] > left) && (y[a][0] < top) && (y[a][1] > bottom));
}
int main(){
    int x[3][2], y[3][2];
    scanf("%d%d%d%d", &x[0][0], &y[0][0], &x[0][1], &y[0][1]);
    scanf("%d%d%d%d", &x[1][0], &y[1][0], &x[1][1], &y[1][1]);
    scanf("%d%d%d%d", &x[2][0], &y[2][0], &x[2][1], &y[2][1]);

    int area = (x[0][1] - x[0][0]) * (y[0][1] - y[0][0]) + (x[1][1] - x[1][0]) * (y[1][1] - y[1][0]) + (x[2][1] - x[2][0]) * (y[2][1] - y[2][0]);
    // printf("init area = %d\n", area);

    int mids[2] = {-1, -1};
    int triple = 1;
    for(int i = 0; i < 3; i ++){
        if(overlap(x, y, i, (i + 1) % 3)){
            findMid(x[i][0], x[i][1], x[(i + 1) % 3][0], x[(i + 1) % 3][1], mids);
            int left = mids[0], right = mids[1];

            findMid(y[i][0], y[i][1], y[(i + 1) % 3][0], y[(i + 1) % 3][1], mids);
            int bottom = mids[0], top = mids[1];
            area -= (right - left) * (top - bottom);
            // printf("now area = %d\n", area);
            if(triple && overlap3(x, y, (i + 2) % 3, left, right, bottom, top)){
                findMid(left, right, x[(i + 2) % 3][0], x[(i + 2) % 3][1], mids);
                left = mids[0], right = mids[1];

                findMid(bottom, top, y[(i + 2) % 3][0], y[(i + 2) % 3][1], mids);
                bottom = mids[0], top = mids[1];
                area += (right - left) * (top - bottom);
                // printf("triple overlap, now area = %d\n", area);
                triple = 0;
            }
        } 
    }
    
    printf("%d\n", area);
    return 0;
}