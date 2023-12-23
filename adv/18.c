#include<stdio.h>
#define MAXN 100000
int main(){
    int count[MAXN] = {0};
    int n;
    scanf("%d", &n);
    int x;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        count[x] ++;
        if(count[x] == 2){
            printf("%d\n", x);
            return 0;
        }
    }
}