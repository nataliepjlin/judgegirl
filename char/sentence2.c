#include<stdio.h>
#include<string.h>
#define MAX 200000
int main(){
    char str[MAX];
    fread(str, 1, MAX, stdin);
    int count = 0;
    for(int i = 0; i < strlen(str); i++){
        count += (str[i] == '.' && ((str[i + 1] == ' ' && str[i + 2] == ' ')
                                    || str[i + 1] == '\n'
                                    || i == strlen(str) - 1));
    }
    printf("%d\n", count);
}

// buffer: It refers to the pointer to the buffer memory block where the data read will be stored.
// size: It refers to the size of each element in bytes.
// count: It refers to the count of elements to be read.
// stream: It refers to the pointer to the file stream.

// fgets reads a line -- i.e. it will stop at a newline.
// fread reads raw data -- it will stop after a specified (or default) number of bytes, independently of any newline that might or might not be present.