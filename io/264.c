#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define N 65537
#define LEN 201
int main(){
    int cnt[N] = {0};
    char filename[LEN];
    scanf("%s", filename);
    FILE *fp = fopen(filename, "rb");
    int maxnum = -1, maxcnt = 0;
    int n;
    fread(&n, 4, 1, fp);
    #ifdef debug
    printf("n = %d\n", n);
    #endif
    short signed num;
    for(int i = 0; i < n; i++){
        fread(&num, 2, 1, fp);
        cnt[num + 32768] ++;
        if(maxcnt < cnt[num + 32768]
        || (maxcnt == cnt[num + 32768] && maxnum < num)){
            maxcnt = cnt[num + 32768];
            maxnum = num;
        }
    }
    fclose(fp);
    printf("%d\n%d\n", maxnum, maxcnt);
}