#include<stdio.h>
#include<string.h>
int main(){
    char word[] = "abcdef";  
    printf("init %s\n", word);
    int idxToDel = 2; 
    memmove(word + idxToDel, word + (idxToDel + 1), strlen(word) - idxToDel);
    printf("%s\n", word);
    // char frag[6];
    // strncpy(frag, word, strlen(word) - 2);
    // printf("strlen(frag) = %ld\n", strlen(frag));
    // frag[strlen(frag)] = '\0';
    // printf("%s\n", frag);
    return 0;
}
