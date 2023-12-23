#include<stdio.h>
void printArr(int arr[500][500], int row, int col){
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            (c == 0)?printf("%d", arr[r][c]) : printf(" %d", arr[r][c]);
        }
        printf("\n");
    }
}
int main(){
    int row, col;
    int arr[500][500];
    scanf("%d%d", &row, &col);

    for(int r = 0; r < row; r++){
        int prev = -1, countH = 1;
        for(int c = 0; c < col; c++){
            scanf("%d", &arr[r][c]);
            // printf("input = %d, prev = %d\n", arr[r][c], prev);
            if(prev == arr[r][c]) countH++;
            else countH = 1;

            if(countH == 3){
                // printf("found same at r=%d, c=%d\n", r, c);
                countH = 1;
                arr[r][c - 2] = arr[r][c - 1] = arr[r][c] = 0;
            }

            if(r > 0 && c > 0){
                if(arr[r][c] == arr[r - 1][c] && arr[r][c] == arr[r][c - 1])
                    arr[r][c] = arr[r - 1][c] = arr[r][c - 1] = 0;
                if(arr[r][c] == arr[r - 1][c - 1] && arr[r][c] == arr[r][c - 1])
                    arr[r][c] = arr[r - 1][c - 1] = arr[r][c - 1] = 0;
                if(arr[r][c] == arr[r - 1][c] && arr[r][c] == arr[r - 1][c - 1])
                    arr[r][c] = arr[r - 1][c] = arr[r - 1][c - 1] = 0;
            }

            if(r > 0 && c >= 0 && c < col - 1){
                if(arr[r][c] == arr[r - 1][c] && arr[r][c] == arr[r - 1][c + 1])
                    arr[r][c] = arr[r - 1][c] = arr[r - 1][c + 1] = 0;
            }

            if(r >= 2 && arr[r][c] == arr[r - 1][c] && arr[r][c] == arr[r - 2][c])
                arr[r][c] = arr[r - 1][c] = arr[r - 2][c] = 0;

            prev = arr[r][c];
        }
    }
    printArr(arr, row, col);

    return 0;
}
