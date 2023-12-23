#include<stdio.h>
#include<string.h>
int main(){
    char path[40];
    char files[40][40];
    int count = 0;
    scanf("%s", path);
    printf("path = %s\n", path);

    char *start = path;
    char *slash;
    if(*start == '/'){
        printf("first char is a slash\n");
        start ++;
    } 

    while(start != NULL){
        slash = strchr(start, '/');
        if(slash == NULL){
            strcpy(files[count], start);
            count ++;
            start = NULL;
        }
        else{
            strncpy(files[count], start, slash - start);
            printf("slash = %p, start = %p, len = %ld\n", slash, start, slash - start);
            files[count][slash - start] = '\0';
            printf("found file: %s\n", files[count]);
            count ++;
            start = slash + 1;
        }
    }     

     for(int i = 0; i < count; i++){
        printf("%s%c", files[i], " \n"[i == count - 1]);
    }
    return 0;  
}