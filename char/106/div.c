#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000
int main(){
    char input[MAX];
    while(scanf("%s", input) == 1){
        if(strcmp(input, "-1") == 0)
            return 0;
        int len = strlen(input);
        !((input[len - 1] - '0') % 2) ? printf("yes") : printf("no");
        int odd = 0, even = 0;
        for(int i = 0; i < len; i++){
            odd += (input[i] - '0') * (i % 2);
            even += (input[i] - '0') * (i % 2 == 0);
        }
        !((odd + even) % 3) ? printf(" yes") : printf(" no");
        (input[len - 1] == '5' || input[len - 1] == '0') ? printf(" yes") : printf(" no");
        !(abs(odd - even) % 11) ? printf(" yes\n") : printf(" no\n");
    }
}