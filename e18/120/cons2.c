#include<stdio.h>
#define MAXN 1000
#define debug
int max(int a, int b){
    return (a > b) * a + (a <= b) * b;
}
int main(){
    int n, arr[MAXN * MAXN];
    scanf("%d", &n);
    for(int i = 0; i < n * n; i++){
        scanf("%d", &arr[i]);
    }
    int max_len = 0;
    for(int i = 0; i < n; i++){
        int row = 0, col = 0, dia1 = 0, dia2 = 0;
        for(int j = 0; j < n; j++){
            row += (arr[i * n + j] == 1);
            row *= (arr[i * n + j] == 1);
            col += (arr[j * n + i] == 1);
            col *= (arr[j * n + i] == 1);
            if(i + j < n){
                dia1 += (arr[(i + j) * n + j] == 1);
                dia1 *= (arr[(i + j) * n + j] == 1);
                dia2 += (arr[j * n + (i + j)] == 1);
                dia2 *= (arr[j * n + (i + j)] == 1);
            }
            max_len = max(max_len, row);
            max_len = max(max_len, col);
            max_len = max(max_len, dia1);
            max_len = max(max_len, dia2);
        }
    }
    printf("%d\n", max_len);
    return 0;
}