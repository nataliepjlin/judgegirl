#include<stdio.h>
#include<string.h>
#include<ctype.h>
// #define debug
int main(){
    int digits = 0, letters = 0, vowels = 0, consonants = 0;
    char vowelList[] = "aeiouAEIOU";
    char str[101];
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        digits += (isdigit(str[i]) != 0);
        letters += (isalpha(str[i]) != 0);
        vowels += (isalpha(str[i]) != 0 && strchr(vowelList, str[i]) != NULL);
        consonants += (isalpha(str[i]) != 0 && strchr(vowelList, str[i]) == NULL);
        #ifdef debug
        printf("str[%d] = %c\n", i, str[i]);
        printf("%d %d %d %d\n\n", digits, letters, vowels, consonants);
        #endif
    }
    printf("%d %d %d %d\n", digits, letters, vowels, consonants);
    return 0;
}