#include<stdio.h>
int fib(int n){
    if(n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
int main(){
    for(int i = 1; i <= 10; i++){
        printf("%d%c", fib(i), " \n"[i == 10]);
    }
}