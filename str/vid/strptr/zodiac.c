#include<stdio.h>
#include<string.h>
#define ZODIAC 12
int main(){
    char zodiac[ZODIAC][40];
    char *zptr[ZODIAC];
    for(int i = 0; i < ZODIAC; i++){
        scanf("%s", zodiac[i]);
        zptr[i] = zodiac[i];
    }
    for(int i = 0; i < ZODIAC; i++){
        for(int j = 0; j < ZODIAC - i - 1; j++){
            if(strcmp(zptr[j], zptr[j + 1]) > 0){
                char *tmp = zptr[j];
                zptr[j] = zptr[j + 1];
                zptr[j + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < ZODIAC; i++){
        printf("%s%c", zptr[i], " \n"[i == ZODIAC - 1]);
    }
}