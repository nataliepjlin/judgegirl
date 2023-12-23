#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 256
void PrintStr(char toPrints[SIZE][SIZE * 2], int stringCount, int max, int charCount) {
    if (stringCount == 1) {
        printf("%s", toPrints[0]);
        int pad = abs(max - strlen(toPrints[0])) % max;
        for(int i = 0; i < pad; i++){
            printf(" ");
        }
        printf("\n");
        return;
    }
    int padding = (max - charCount) / (stringCount - 1);
    int extra = (max - charCount) % (stringCount - 1);

    for (int s = 0; s < stringCount; s++) {
        printf("%s", toPrints[s]);
        if (s == stringCount - 1) {
            printf("\n");
            break;
        }
        for (int p = 0; p < padding; p++) {
            printf(" ");
        }
        if (extra > 0) {
            printf(" ");
            extra--;
        }
    }
}

int main() {
    int max;
    int charCount = 0, stringCount = 0;
    char toPrints[SIZE][SIZE * 2];
    memset(toPrints, '\0', sizeof(toPrints));
    scanf("%d", &max);
    char tmp[SIZE * 2];
    
    while (scanf("%s", tmp) != EOF) {
        int len = strlen(tmp);
        if (charCount + stringCount + len <= max) {
            strcpy(toPrints[stringCount], tmp);
            charCount += len;
            stringCount++;
        } 
        else {
            PrintStr(toPrints, stringCount, max, charCount);
            // memset(toPrints, '\0', sizeof(toPrints));
            strcpy(toPrints[0], tmp);
            stringCount = 1;
            charCount = len;
        }
    }
    
    PrintStr(toPrints, stringCount, max, charCount);
    return 0;
}
