#include<stdio.h>
#include<string.h>
int main(){
    char input[500000];
    int count = 0;
    fread(input, sizeof(input), 1, stdin);
    int len = strlen(input);
    for(int i = 0; i < len; i++){
        count += (input[i] == '.' &&
        ((i < len - 2 && input[i + 1] == ' ' && input[i + 2] == ' ')
        ||(i < len - 1 && input[i + 1] == '\n')
        ||(i == len - 1)));
    }
    printf("%d\n", count);
    return 0;
}