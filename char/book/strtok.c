#include <stdio.h>
#include <string.h>
int main() {
    char input[] = "Hello,World,How,Are,You";
    char *token = strtok(input, ",");
    
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");//By passing NULL, you're essentially telling strtok to continue parsing the same string, starting from where it left off in the previous call, until it reaches the end of the string or can't find any more delimiters.
        // https://youtu.be/nrO_pXGZc3Y?si=quTLSxEE0ndLN-2V&t=128
    }

    return 0;
}
