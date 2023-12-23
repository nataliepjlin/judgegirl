#include<stdio.h>
#include<string.h>
int main(){
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    char path[40], dirs[40][40];
    int count = 0;
    char *start = path;
    scanf("%s", path);
    int skip_len = strcspn(start, letters);
    while(skip_len < strlen(start)){
        start += skip_len;
        printf("starting from %c", *start);
        int cpy_len = strspn(start, letters);
        strncpy(dirs[count], start, cpy_len);
        printf(" to %c\n", dirs[count][cpy_len - 1]);
        dirs[count][cpy_len] = '\0';
        count ++;
        start += cpy_len;
        skip_len = strcspn(start, letters);
    }
    for(int i = 0; i < count; i++){
        printf("%s%c", dirs[i], " \n"[i == count -1]);
    }
    return 0;
}