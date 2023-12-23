#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #define DEBUG
int main(){
    char *inputs[1001];
    for(int i = 0; i < 1001; i++){
        inputs[i] = (char *)malloc(sizeof(char));
    }
    int ans[4];
    while(scanf("%s", *inputs) != EOF){
        if(strcmp(*inputs, "-1") == 0) break;
        int even = 0, odd = 0, count = 0;
        char *c = inputs[0];
        while(*c != '\0'){
            #ifdef DEBUG
            printf("c = %c, c - 48 = %d, count = %d\n", *c, *c - 48, count);
            #endif
            if(count % 2)
                odd += (*c - 48);
            else
                even += (*c - 48);

            c ++;
            count ++;
            #ifdef DEBUG
            printf("next c = %c, even = %d, odd = %d\n", *c, even, odd);
            #endif
        }
        c --;
        #ifdef DEBUG
        printf("last c = %c, even = %d, odd = %d\n", *c, even, odd);
        #endif
        ans[0] = ((*c - 48) % 2 == 0);
        ans[1] = ((even + odd) % 3 == 0);
        ans[2] = ((*c - 48) % 5 == 0);
        ans[3] = ((abs(even - odd)) % 11 == 0);
        for(int i = 0; i < 4; i++){
            (ans[i]) ? printf("yes") : printf("no");
            (i == 3) ? printf("\n") : printf(" ");
        }
        #ifdef DEBUG
        printf("\n");
        #endif
    }
    return 0;
}