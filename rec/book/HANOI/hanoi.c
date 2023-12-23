#include<stdio.h>
void hanoi(int n, char from, char to, char buf){
    printf("hanoi(%d, %c, %c, %c)\n", n, from, to, buf);
    
    if(n == 1){
        printf("from %c to %c\n\n", from, to);//A to C directly
    }
    else{
        hanoi(n - 1, from, buf, to);//A to B, C as buf
        printf("from %c to %c\n", from, to);
        hanoi(n - 1, buf, to, from);//B to C, A as buf
    }
}
int main(){
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}