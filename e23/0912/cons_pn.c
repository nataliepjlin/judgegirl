#include<stdio.h>
int main(){
    int prev, input;
    scanf("%d", &prev);
    int count = 1;
    while(scanf("%d", &input) != EOF){
        if((input > 0 && prev > 0) || (input < 0 && prev < 0)){
            count ++;
        }
        else{
            if(prev < 0) count = -count;
            printf("%d ", count);
            count = 1;
        }
        prev = input;
    }

    if(prev < 0) count = -count;
    printf("%d\n", count);
    return 0;
}