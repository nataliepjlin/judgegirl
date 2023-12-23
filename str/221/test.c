#include <stdio.h>
#include <string.h>
void printLine(int max, int charCount, int stringCount, char currentLine[256][512]){
    if(stringCount == 1){
        printf("%s", currentLine[0]);
        for(int i = 0; i < max - strlen(currentLine[0]); i++)
            putchar(' ');
        puts("");
        return;
    }
    int spacing =(max - charCount) /(stringCount - 1);
    int extra =(max - charCount) %(stringCount - 1);
    for(int i = 0; i < stringCount; i++){
        printf("%s", currentLine[i]);
        if(i == stringCount - 1){
            puts("");
            break;
        }
        for(int j = 0; j < spacing; j++)
            putchar(' ');
        if(extra > 0){
            putchar(' ');
            extra--;
        }
    }
}
 
int main(){
    int max, charCount = 0, stringCount = 0;
    char string[512], currentLine[256][512];
    memset(currentLine, '\0', sizeof(currentLine));
    scanf("%d", &max);
    while(scanf("%s", string) == 1){
        int len = strlen(string);
        if(charCount + stringCount + len <= max){
            strcpy(currentLine[stringCount], string);
            stringCount++;
            charCount += len;
        }
        else{
            printLine(max, charCount, stringCount, currentLine);
            strcpy(currentLine[0], string);
            stringCount = 1;
            charCount = len;
        }
    }
    printLine(max, charCount, stringCount, currentLine);
    return 0;
}