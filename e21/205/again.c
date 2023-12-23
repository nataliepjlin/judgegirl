#include<stdio.h>
#include<string.h>
// #define debug
int main(){
    char keys[] = "!@#$%^&*()";
    char c;
    int n = 0, sum = 0;
    int tomul = 0;
    while(scanf("%c", &c) == 1){
        if(c != '*' && c != '+' && strchr(keys, c) != NULL){
            n = n * 10 + ((strchr(keys, c) - keys) + 1) % 10;
            #ifdef debug
            printf("n = %d\n", n);
            #endif
        }
        else if(c == '*'){
            tomul += (!tomul);
            tomul *= n;
            #ifdef debug
            printf("tomul = %d\n", tomul);
            #endif
            n = 0;
        }
        else if(c == '+'){
            sum += (n * (!tomul) + (n * tomul));
            #ifdef debug
            printf("sum = %d\n", sum);
            #endif
            tomul = 0;
            n = 0;
        }
    }
    sum += (n * (!tomul) + (n * tomul));
    printf("%d\n", sum);

}