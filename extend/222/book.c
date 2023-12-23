#include<stdio.h>
#include<stdint.h>
int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
int main() {
    int x;
    uint64_t head[] = {0xffffffffffffff00, 0xffffffffffff0000, 0xffffffffff000000, 0xffffffff00000000, 
                       0xffffff0000000000, 0xffff000000000000, 0xff00000000000000, 0x0000000000000000};
    uint64_t tail[] = {0x0000000000000000, 0x00000000000000ff, 0x000000000000ffff, 0x0000000000ffffff,
                       0x00000000ffffffff, 0x000000ffffffffff, 0x0000ffffffffffff, 0x00ffffffffffffff};
    uint64_t shelf = 0;
    uint64_t getbook[] = {0x00000000000000ff, 0x000000000000ff00, 0x0000000000ff0000, 0x00000000ff000000,
                          0x000000ff00000000, 0x0000ff0000000000, 0x00ff000000000000, 0xff00000000000000};
    while(ReadInt(&x)){
        int loc =   ((shelf & getbook[0]) == x)  * 1 +
                    (((shelf & getbook[1]) >> 8) == x) * 2 +
                    (((shelf & getbook[2]) >> 16) == x) * 3 +
                    (((shelf & getbook[3]) >> 24) == x) * 4 +
                    (((shelf & getbook[4]) >> 32) == x) * 5 +
                    (((shelf & getbook[5]) >> 40) == x) * 6 +
                    (((shelf & getbook[6]) >> 48) == x) * 7 +
                    (((shelf & getbook[7]) >> 56) == x) * 8;
        #ifdef debug
        printf("x = %d, loc = %d\n", x, loc);
        #endif
        if(!loc){
            shelf = (shelf << 8) | x;
        }
        else{
            shelf = (shelf & head[loc - 1]) | ((shelf & tail[loc - 1]) << (4 + 4)) | x;
        }
    }
    // output your answer
    for(int i = 7; i >= 0; i--){
        printf("%ld%c", (shelf & getbook[i]) >> (i * 8), " \n"[i == 0]);
    }
    return 0;
}