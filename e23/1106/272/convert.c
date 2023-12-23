#include<stdio.h>
#include<string.h>
#include<math.h>
void num2str(long long n){
    char list[][15] = {"", "one", "two", "three", "four", "five",
                        "six", "seven", "eight", "nine", "ten", 
                        "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                        "sixteen", "seventeen", "eighteen", "nineteen", 
                        "twenty"};
    char list2[][15] = {"", "", "twenty", "thirty", "forty", "fifty",
                        "sixty", "seventy", "eighty", "ninety"};
    int flag = 0;
    if(n / 100){
        printf("%s hundred ", list[(n / 100)]);
    }
    n %= 100;  
    if(n){
        if(n <= 20){
            printf("%s", list[n]);
        }
        else{
            printf("%s", list2[n / 10]);
            if(n % 10){
                printf("-%s", list[n % 10]);
            }
        }
    }
}
int main(){
    long long n;
    scanf("%lld", &n);
    char list[][15] = {"quintillion", "quadrillion", "trillion", "billion",
    "million", "thousand", ""};
    int l = 0;
    int first = 1;
    for(int i = 18; i >= 0; i -= 3, l++){
        long long ten = pow(10, i);
        if(n / ten){
            first --;
            num2str(n / ten);
            printf(" %s ", list[l]);
        }
        n %= ten;
    }
}