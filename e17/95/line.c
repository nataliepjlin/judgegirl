#include<stdio.h>
#include<string.h>
char **first[1024];
char *second[16384];
char base[10000000];
int count[1024] = {0};
int main(){
    int n;
    scanf("%d", &n);
    int b = 0, s = 0;
    for(int i = 0; i < n; i++){
        first[i] = &second[s];
        char c;
        while(scanf("%s%c", &base[b], &c) == 2){
            second[s] = &base[b];
            s++;
            count[i] ++;
            b += (strlen(&base[b]) + 1);
            if(c == '\n')
                break;
        }
    }
    int m;
    scanf("%d", &m);
    int r1, c1, r2, c2;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        char *tmp = first[r1][c1];
        first[r1][c1] = first[r2][c2];
        first[r2][c2] = tmp;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < count[i]; j++){
            printf("%s%c", first[i][j], " \n"[j == count[i] - 1]);
        }
    }
}