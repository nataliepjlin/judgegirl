#include<stdio.h>
int main(){
    char s1[5], s2[5];
    scanf("%s%s", s1, s2);
    int a = 0, b = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            a += (s1[i] == s2[j] && i == j);
            b += (s1[i] == s2[j] && i != j);
        }
    }
    printf("%dA%dB\n", a, b);
    return 0;
}