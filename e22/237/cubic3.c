#include<stdio.h>
#include<string.h>
#define MAXN 100
#define HASHSIZE MAXN * MAXN
#define MAXCAP 10
#define MAXCHAR 6
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
int f(char *s, int k){
    int val = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        val = (val * 29 + s[i]) % k;
    }
    return val;
}
void insert(int r, int c, int n, int height[MAXN][MAXN], char tower[MAXN][MAXN][MAXN][MAXCHAR],
int hashT[HASHSIZE][MAXCAP], int hashTlen[HASHSIZE]){
    int hashVal = f(tower[height[r][c]][r][c], n * n);
    for(int i = 0; i < hashTlen[hashVal]; i++){
        int hr = hashT[hashVal][i] / n, hc = hashT[hashVal][i] % n;
        if(strcmp(tower[height[r][c]][r][c], tower[height[hr][hc]][hr][hc]) == 0){
            printf("%s\n", tower[height[r][c]][r][c]);
            hashT[hashVal][i] = hashT[hashVal][hashTlen[hashVal] - 1];
            hashTlen[hashVal] --;
            if(height[r][c] > 0){
                height[r][c] --;
                insert(r, c, n, height, tower, hashT, hashTlen);
            }
            if(height[hr][hc] > 0){
                height[hr][hc] --;
                insert(hr, hc, n, height, tower, hashT, hashTlen);
            }
            return;
        }//same
    }
    //no same
    hashT[hashVal][hashTlen[hashVal]] = r * n + c;
    hashTlen[hashVal] ++;
    return;
}
int main(){
    int n;
    int height[MAXN][MAXN];
    char tower[MAXN][MAXN][MAXN][MAXCHAR];
    scanf("%d", &n);
    for(int l = 1; l <= n; l++){
        for(int r = 0; r < l; r++){
            for(int c = 0; c < l; c++){
                scanf("%s", tower[n - l][r][c]);
                height[r][c] = (n - 1) - max(r, c);
            }
        }
    }//input
    int hashT[HASHSIZE][MAXCAP];
    int hashTlen[HASHSIZE] = {0};
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            insert(r, c, n, height, tower, hashT, hashTlen);
        }
    }
}