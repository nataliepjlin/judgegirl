#include<stdio.h>
int count(int r, int c){
    if(r == 1 || c == 1){
        return 1;
    }
    return count(r - 1, c) + count(r, c - 1);
}
int main(){
    int r, c;
    scanf("%d%d", &r, &c);
    printf("%d\n", count(r, c));
    return 0;
}