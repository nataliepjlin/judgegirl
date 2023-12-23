#include<stdio.h>
#include<string.h>
#define N 2000
#define MAXCHAR 50
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    char A[n] = {0};
    int visited[N] = {0};

    char cmd[MAXCHAR]; 
    int idx;
    for(int i = 0; i < m; i++){
        scanf("%s%d", cmd, &idx);
        int len = strlen(cmd), c = 0;
        for(int j = idx; j < idx + len; j++, c++){
            A[j] = cmd[c] * (A[j] == '\0') + (A[j] + cmd[c]) / 2 * (A[j] != '\0');
            visited[j] = 1;
        }
    }
    for(int i = 0; i < n; i++){
       if(visited[i]) printf("%c", A[i]);
       else if(i != n - 1) printf(" ");
    }
    printf("\n");
    return 0;
}