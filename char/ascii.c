#include<stdio.h>
int main(){
    for(int i = 2; i <= 7; i++){
        for(int j = 0; j <= 15; j++){
            char c = i * 16 + j;
            printf("%c%c", c, " \n"[j == 15]);
        }
    }
    return 0;
}