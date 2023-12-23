#include<stdio.h>
#include<ctype.h>
int main(){
    char c;
    int count = 0, check = 0, endl = 0, space = 0;
    while(scanf("%c", &c) == 1){
        if(check && !(isspace(c) || c == '\n')){
            check = 0;
            space = 0;
            endl = 0;
        }
        if(c == '.'){
            check = 1;
            space = 0;
            endl = 0;
        }
        else if(c == ' '){
            space ++;
            if(space == 2 && check && !endl){
                check = 0;
                count ++;
            }
        }
        else if(c == '\n'){
            endl = 1;
            if(check && !space){
                count ++;
                check = 0;
            }
        }
    }//while
    count += (check);
    printf("%d\n", count);
}