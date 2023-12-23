#include<stdio.h>
#include<string.h>
// #define DEBUG
int main(){
    char str[10] = "!@#$%^&*()"; char *start = str;
    char c;
    int total = 0, now = 0, tomul = 0;
    while(scanf("%c", &c) != EOF){
        int n = (strchr(start, c) - start + 1) % 10;
        #ifdef DEBUG
        printf("n = %d\n", n);
        #endif
        if(!(c == '*' || c == '+')) now = now * 10 + n;
        else if(c == '+'){
            total += (tomul) ? (tomul * now) : (now);
            tomul = now = 0;
        }
        else if(c == '*' && !tomul){
            tomul = now;
            now = 0;
        }
        else if(c == '*' && tomul){
            tomul *= now;
            now = 0;
        }

        #ifdef DEBUG
        printf("now = %d, tomul = %d, total = %d\n", now, tomul, total);
        #endif
    }

    if(now) total += (tomul) ? (tomul * now) : (now);
    printf("%d\n", total);
    return 0;
}