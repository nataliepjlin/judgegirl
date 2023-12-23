#include<stdio.h>
#include<stdint.h>
// #define debug
void printShelf(uint64_t shelf, uint64_t getbook[]){
    for(int i = 7; i >= 0; i--){
        printf("%ld%c", (shelf & getbook[i]) >> (i * 8), " \n"[i == 0]);
    }
}
int main(){
    uint64_t head[] = {0xffffffffffffff00, 0xffffffffffff0000, 0xffffffffff000000, 0xffffffff00000000, 
                       0xffffff0000000000, 0xffff000000000000, 0xff00000000000000, 0x0000000000000000};
    uint64_t tail[] = {0x0000000000000000, 0x00000000000000ff, 0x000000000000ffff, 0x0000000000ffffff,
                       0x00000000ffffffff, 0x000000ffffffffff, 0x0000ffffffffffff, 0x00ffffffffffffff};
    uint64_t shelf = 0;
    int query;
    uint64_t getbook[] = {0x00000000000000ff, 0x000000000000ff00, 0x0000000000ff0000, 0x00000000ff000000,
                          0x000000ff00000000, 0x0000ff0000000000, 0x00ff000000000000, 0xff00000000000000};
    while(scanf("%d", &query) == 1){
        int loc =   ((shelf & getbook[0]) == query) * 1 +
                    (((shelf & getbook[1]) >> 8) == query) * 2 +
                    (((shelf & getbook[2]) >> 16) == query) * 3 +
                    (((shelf & getbook[3]) >> 24) == query) * 4 +
                    (((shelf & getbook[4]) >> 32) == query) * 5 +
                    (((shelf & getbook[5]) >> 40) == query) * 6 +
                    (((shelf & getbook[6]) >> 48) == query) * 7 +
                    (((shelf & getbook[7]) >> 56) == query) * 8;
        #ifdef debug
        printf("query = %d, loc = %d\n", query, loc);
        #endif
        if(!loc){
            shelf = (shelf << 8) | query;
        }
        else{
            shelf = (shelf & head[loc - 1]) | ((shelf & tail[loc - 1]) << (4 + 4)) | query;
        }
        #ifdef debug
        printShelf(shelf, getbook);
        printf("\n");
        #endif
    }
    printShelf(shelf, getbook);
}