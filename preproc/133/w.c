#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 400
struct string_count {
  char seen[80];
  int count;
};
 
int compare_and_add(char *string, struct string_count strings[]){
    int first_slot = -1, i;
    for(i = 0; strings[i].count != 0; i++){
        if(!strcmp(string, strings[i].seen)){
            strings[i].count++;
            return 1;
        }
    }
    strings[i].count = 1, strcpy(strings[i].seen, string);
    #ifdef debug
    printf("copy \"%s\" to %dth slot\n", strings[i].seen, i);
    #endif
    return 0;
}
void sort(struct string_count strings[]){
    for(int i = 0; strings[i].count != 0; i++){
        for(int j = i + 1; strings[j].count != 0; j++){
            if(strings[i].count > strings[j].count
            || (strings[i].count == strings[j].count
            && strcmp(strings[i].seen, strings[j].seen) > 0)){
                struct string_count tmp = strings[i];
                tmp = strings[i];
                strings[i] = strings[j];
                strings[j] = tmp;
            }
        }
    }
}
void print(struct string_count strings[]){
    for(int i = 0; strings[i].count; i++){
        printf("%d %s\n", strings[i].count, strings[i].seen);
    }
}