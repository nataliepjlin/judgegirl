#include<stdio.h>
int mystrlen(char *s){
    if(*s == '\0')
        return 0;
    return(mystrlen(s + 1) + 1);
}
int main(){
    printf("%d\n", mystrlen("hello world"));
}