#include<stdio.h>
#include<string.h>
#define MAX 100000
// #define debug
int cmp(char *a, char *b){
    if(*a != *b) return *a - *b;
    a++, b++;
    if(*a != *b) return *a - *b;
    a++, b++;
    return *a - *b;
}
void merge(char a[], char b[], char c[]){
    int len1 = strlen(a), len2 = strlen(b);
    int idx1 = 0, idx2 = 0, idx = 0;
    while(idx1 < len1 && idx2 < len2){
        if(cmp(a + idx1, b + idx2) <= 0){
            memcpy(c + idx, a + idx1, sizeof(char) * 3);
            idx1 += 3;
        }
        else{
           memcpy(c + idx, b + idx2, sizeof(char) * 3);
           idx2 += 3; 
        }
        idx += 3;
    }
    while(idx1 < len1){
        memcpy(c + idx, a + idx1, sizeof(char) * 3);
        idx1 += 3;
        idx += 3;
    }
    while(idx2 < len2){
        memcpy(c + idx, b + idx2, sizeof(char) * 3);
        idx2 += 3;
        idx += 3;
    }
}
int main(){
    char a[MAX], b[MAX], c[MAX];
    scanf("%s", a);
    int flag = 1;
    while(scanf("%s", b) == 1){
        if(flag){
            merge(a, b, c);
            printf("%s\n", c);
            flag = 0;
        }
        else{
           merge(c, b, a);
           printf("%s\n", a);
           flag = 1; 
        }
    }
    return 0;
}