#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define N 11
#define debug
int getdist(char *result, int n, int f[N][N]){
    int dist = 0;
    for(int i = 0; i < n; i++){
        #ifdef debug
        printf("\nchecking result[%d] = %c\n", i, result[i]);
        #endif
        for(int j = (result[i] - 'A') + 1; j < n; j++){
            char *ptr = strchr(result, 'A' + j);
            if(ptr != NULL && f[result[i] - 'A'][j]){
                dist += abs(ptr - (result + i));
                #ifdef debug
                printf("have relationship with %c, ", 'A' + j);
                printf("add %d to dist, now dist = %d\n", abs(ptr - (result + i)), dist);
                #endif
            }
        }//checking letters after
    }//all elements in result
    return dist;
}
int main(){
    char str[] = "ABCFGDHE";
    int n, m;
    scanf("%d%d", &n, &m);
    int used[N] = {0};
    char result[N] = {0};
    int f[N][N] = {{0}};
    char p1[2], p2[2];
    for(int i = 0; i < m; i++){
        scanf("%s%s", p1, p2);
        f[p1[0] - 'A'][p2[0] - 'A'] = 1;
        f[p2[0] - 'A'][p1[0] - 'A'] = 1;
    }
    printf("%d\n", getdist(str, n, f));
}