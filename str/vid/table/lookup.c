#include<stdio.h>
#include<string.h>
int find(char *str, char *table[]){
    int idx = -1;
    int i = 0;
    while(table[i] != NULL && idx == -1){
        printf("table[%d] = %s\n", i, table[i]);
        if(!strcmp(str, table[i]))
            idx = i;
        i++;
    }
    return idx;
}
int main(){
    char *table[] = {"+", "-", "*", "/", "%", "<", ">", ">=", "<="};
    char str[80];
    while(scanf("%s", str) == 1){
        int idx = find(str, table);
        printf("idx = %d\n", idx);
    }
}