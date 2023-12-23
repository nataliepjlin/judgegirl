#include<stdio.h>
#define DEBUG
int main(){
    int count = 0, sum = 0;
    int grade;
    scanf("%d", &grade);
    while(grade >= 0){
        sum += grade;
        count ++;
        scanf("%d", &grade);
    }
    #ifdef DEBUG
    printf("sum = %d, count = %d\n", sum, count);
    #endif
    double ave;
    ave = (double) sum / count;// NOTE THAT "(double) (sum / count)" WON'T WORK!
    printf("%f\n", ave);
    return 0;
}