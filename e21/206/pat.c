#include<stdio.h>
#include<string.h>
#define MAX 100000 + 1
#define N 26
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
int main(){
    char input[MAX];
    int freq[N][N][N] = {{{0}}};
    while(scanf("%s", input) == 1){
        int len = strlen(input);
        if(len >= 3){
            for(int i = 0; i <= len - 3; i++){
                freq[input[i] - 'a'][input[i + 1] - 'a'][input[i + 2] - 'a'] ++;
            }
        }
    }
    for(int round = 0; round < 3; round ++){
        int maxf = -1;
        int mi = -1, mj = -1, mk = -1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0; k < N; k++){
                    if(maxf < freq[i][j][k]){
                        maxf = freq[i][j][k];
                        mi = i;
                        mj = j;
                        mk = k;
                    }
                }
            }
        }
        printf("%c%c%c\n", mi + 'a', mj + 'a', mk + 'a');
        freq[mi][mj][mk] = 0;
    }
    return 0;
}