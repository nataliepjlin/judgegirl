#include<stdio.h>
#include<string.h>
#define MAX 50000
#define debug
int main(){
    char outstr[] = "bcccddcdd";
    int r, l, max = 0;
    char max_str[MAX * 2];
    int i = 0;
    while(i < strlen(outstr)){
        int count = 1;
        while(outstr[i] == outstr[i + count]){
            count ++;
        }
        char c = outstr[i]; 
        if(max < count){
            memset(max_str, '\0', strlen(max_str));
            max = count;
            max_str[strlen(max_str)] = c;
            max_str[strlen(max_str)] = '\0';
        }
        else if(max == count){
            max_str[strlen(max_str)] = ' ';
            max_str[strlen(max_str)] = c;
            max_str[strlen(max_str)] = '\0';
        }
        i += count;
        #ifdef debug
        printf("count = %d\n", count);
        printf("i = %d\n", i);
        #endif
    }
    if(strlen(max_str)) printf("%s ", max_str);
    printf("%d\n", max);
    return 0;
}
