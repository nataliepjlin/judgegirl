#include<stdio.h>
int main(){
    int n, count = 0, k, val = -1, remain = 0;
    scanf("%d", &k);
    while(scanf("%d", &n) != EOF){
        val = (remain * 10 +  n) / k;
        remain = (remain * 10 +  n) % k;
        if(val != 0 || count != 0){
            printf("%d\n", val);
        }
        count ++;
    }

    if(count == 1 && val == 0){
        printf("0\n");
    }
    return 0;
}