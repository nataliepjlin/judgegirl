#include<stdio.h>
#include<string.h>
#define MAXCHAR 32
// #define debug
int main(){
    char input[MAXCHAR];
    char prev = 'a';
    char vowels[] = "aeiouAEIOU";
    int count = 0;
    while(scanf("%s", input) == 1){
        int len = strlen(input);
        for(int i = 0; i < len; i++){
            #ifdef debug
            printf("prev = %c, input[i] = %c, ", prev, input[i]);
            #endif
            int flag = (strchr(vowels, input[i]) == NULL);
            count += (prev != 'a' && flag && prev < input[i]);
            #ifdef debug
            printf("count = %d\n", count);
            #endif
            prev = input[i] * flag + prev * !flag;
        }
    }
    printf("%d\n", count);
    return 0;
}