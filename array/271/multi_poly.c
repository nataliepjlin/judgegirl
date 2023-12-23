#include<stdio.h>
int main(){
    int n, m;
    int p1[101], p2[101];
    int p[202] = {0};
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d",&p1[(n - 1) - i]);
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d",&p2[(m - 1) - i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            p[i + j] += p1[i] * p2[j];
        }
    }

    for(int i = (n - 1) + (m - 1); i >= 0; i--){
        (i > 0)?printf("%d ", p[i]):printf("%d", p[i]);
    }
    // printf("\n");
}