#include<stdio.h>
#include<string.h>
#define DEBUG
int main(){
    char dest[4];
    int i = 10;
    char src[40] = "This is a source string.";
    #ifdef DEBUG
    printf("addr of dest = %p\n", dest);
    printf("addr of i = %p\n", &i);
    printf("addr of src = %p\n", src);
    #endif
    printf("init i = %d\n", i);
    printf("init src = %s\n\n", src);

    strncpy(dest, src, 3);
    dest[3] = '\0';
    
    printf("dest = %s\n", dest);
    printf("now i = %d\n", i);
    printf("now src = %s\n", src);
    return 0;
}