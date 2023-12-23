#include<stdio.h>
#include<string.h>
// #define DEBUG
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void bs(int cons[3]){
    #ifdef DEBUG
    printf("before\n");
    for(int i = 0; i < 3; i++){
        printf("%d%c", cons[i], " \n"[i == 2]);
    }
    #endif
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3 - 1 - i; j++){
            if(cons[j] > cons[j + 1]) swap(&cons[j], &cons[j + 1]);
        }
    }
    #ifdef DEBUG
    printf("after\n");
    for(int i = 0; i < 3; i++){
        printf("%d%c", cons[i], " \n"[i == 2]);
    }
    printf("\n");
    #endif
}
int main(){
    int a, b, c, d, e;
    int found  = 0;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    int x;
    int init[3], initc[3],cons[3], idx = 0;
    while(scanf("%d", &x) != EOF && !found){
        int count = 0;
        init[idx] = x;
        #ifdef DEBUG
        printf("init x = %d\n", x);
        #endif
        while(x < d || x > e){
            x = (a * x + b) % c;
            count ++;
            #ifdef DEBUG
            printf("x = %d, count = %d\n", x, count);
            #endif
        }
        #ifdef DEBUG
        printf("\n");
        #endif
        initc[idx] = cons[idx] = count;
        idx ++;
        if(idx == 3){
            bs(cons);
            if(cons[1] - cons[0] == 1 && cons[2] - cons[1] == 1){
                printf("%d %d %d\n", init[0], init[1], init[2]);
                found = 1;
            } 
            initc[0] = cons[0] = initc[1];
            initc[1] = cons[1] = initc[2];

            init[0] = init[1];
            init[1] = init[2];
            idx = 2;
        }
    }
    if(!found){
        printf("Not found\n");
    }
    return 0;
}