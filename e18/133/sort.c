#include<stdio.h>
#include<string.h>
#define MAXLEN 100000
void merge(char a[], char b[], char c[]){
    char tmp1[4] = {0}, tmp2[4] = {0};
    int i = 0, j = 0;
    int len1 = strlen(a), len2 = strlen(b);
    for(int k = 0; k < len1 + len2; k += 3){
        if(i < len1 && j < len2){
            tmp1[0] = a[i], tmp1[1] = a[i + 1], tmp1[2] = a[i + 2];
            tmp2[0] = b[j], tmp2[1] = b[j + 1], tmp2[2] = b[j + 2];
            if(strcmp(tmp1, tmp2) < 0){
                c[k] = a[i], c[k + 1] = a[i + 1], c[k + 2] = a[i + 2];
                i += 3;
            }
            else{
               c[k] = b[j], c[k + 1] = b[j + 1], c[k + 2] = b[j + 2];
               j += 3; 
            }
        }
        else if(i == len1){
            c[k] = b[j], c[k + 1] = b[j + 1], c[k + 2] = b[j + 2];
            j += 3; 
        }
        else{
            c[k] = a[i], c[k + 1] = a[i + 1], c[k + 2] = a[i + 2];
            i += 3;
        }
    }
}
int main(){
    char a[MAXLEN] = {0}, b[MAXLEN] = {0}, c[MAXLEN] = {0};
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
}