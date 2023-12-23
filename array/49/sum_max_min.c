#include<stdio.h>
#include<string.h>
int main(){
    int n, m;
    int sum[1000]={0};
    int max[1000]={0};
    int min[1000];
    for(int i = 0; i < 1000; i++){
        min[i] = 100000;
    }
    // printf("min[0]=%d\n",min[0]);
    
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        int input;
        scanf("%d", &input);
        int mod_val = input % m;
        sum[mod_val] += input;
        if(input > max[mod_val]) max[mod_val] = input;
        if(input < min[mod_val]) min[mod_val] = input;
    }

    for(int mod_val = 0; mod_val < m; mod_val++){
        printf("%d %d %d\n", sum[mod_val], max[mod_val], min[mod_val]);
    }
    return 0;
}