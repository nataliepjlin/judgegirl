#include <stdio.h>
#include<string.h>
// #define DEBUG
int main() {
    int count = 0;
    int check = 0, space = 0, endl = 0;
    char input;

    while (scanf("%c", &input) != EOF) {
        if(!(input == ' ' || input == '\n' || input == '.') && check){
            #ifdef DEBUG
            printf("kill check\n");
            #endif
            check = 0, space = 0, endl = 0;
        }

        if (input == '.'){
            check = 1;
            space = 0;
        } 
        else if((input == ' ') && check && !space) space = 1;
        else if((input == ' ') && check && space && !endl){
            check = space = 0;
            count ++;
        }
        else if(input == '\n'){
            if(check){
                if(!space){
                    check = 0;
                    count ++;
                    endl = 0;
                }
                else if(!endl){
                    endl = 1;
                }// . space, \n, \0
            }
        }
        
        #ifdef DEBUG
        printf("input = %c, check = %d, space = %d, count = %d, endl = %d\n", input, check, space, count, endl);
        #endif
    }

    if(check) count++;//.\0
    printf("%d\n", count);
    return 0;
}
