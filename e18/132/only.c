#include<stdio.h>
#include<string.h>
#define SIZE 32
// #define debug
int main(){
    char str[SIZE];
    char vowel[] = "aeiou";
    int count = 0;
    char prev = 'a';
    while(scanf("%s", str) != EOF){
        int len = strlen(str);
        for(int i = 0; i < len; i++){
            char now = str[i];
            #ifdef debug
            printf("prev = %c, now = %c\n", prev, now);
            #endif
            count += (strchr(vowel, now) == NULL
            && (strchr(vowel, prev) == NULL && now > prev));
            prev = now * (strchr(vowel, now) == NULL) 
            + prev * (strchr(vowel, now) != NULL);
        }
    }
    printf("%d\n", count);
    return 0;
}