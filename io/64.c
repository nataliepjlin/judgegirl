#include <stdio.h>
#include <stdlib.h>
 
#define MAXN 65536
int main() {
    FILE *fin = fopen("test", "rb");
    FILE *fout = fopen("test.enc", "wb");
    int key, n;
    scanf("%d", &key);
    char buf[MAXN];
    while((n = fread(buf, 1, MAXN, fin)) != 0){
        for(int i = 0; i < n; i++)
            buf[i] ^= key;
        fwrite(buf, sizeof(char), n, fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}