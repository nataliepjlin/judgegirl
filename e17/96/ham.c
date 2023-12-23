#include<stdint.h>
#include<stdio.h>
#define N 24
#define M 4
// #define debug
void decode(uint64_t encoded[], int codes[], int n, int m){
    int c = 0;
    for(int e = 0; e < m && c < n; e++){
        for(int i = 56; i >= 0 && c < n; i-= 8){
            codes[c] = (encoded[e] >> i) & 0xff;
            #ifdef debug
            printf("codes[%d] = %d\n", c, codes[c]);
            #endif
            c++;
        }
    }
}
int getDist(int a, int b){
    int dist = 0;
    for(int i = 0; i < 8; i++){
        dist += (((a >> i) & 1) != ((b >> i) & 1));
    }
    #ifdef debug
    printf("dist = %d\n", dist);
    #endif
    return dist;
}
int main(){
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    int codes[N] = {0};
    uint64_t encoded[M];
    for(int i = 0; i < m; i++){
        scanf("%lu", &encoded[i]);
    }
    decode(encoded, codes, n, m);
    int text;
    for(int i = 0; i < p; i++){
        scanf("%d", &text);
        int valid = 0;
        int tmp = -1;
        for(int j = 0; j < n && !valid; j++){
            #ifdef debug
            printf("\n%dth code = %d\n", j, codes[j]);
            #endif
            int dist = getDist(text, codes[j]);
            if(!dist){
                printf("%d\n", text);
                valid = 1;
            }
            else if(dist == 1){
                tmp = j;
            }
        }
        if(!valid && tmp != -1){
            printf("%d\n", codes[tmp]);
        }
    }
}