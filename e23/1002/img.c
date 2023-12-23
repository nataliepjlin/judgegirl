#define MAXH 100
#define MAXW 100
#define MAXK 10
// #define debug
// #include<stdio.h>
void img2col(int h, int w, int k, int imgMatrix[MAXH][MAXW], int colMatrix[MAXK * MAXK][MAXW * MAXH]){
    #ifdef debug
    printf("%d * %d, k = %d\n", h, w, k);
    #endif
    int colCount = 0;
    for(int i = k - 1; i < h; i++){
        for(int j = k - 1; j < w; j++){
            int rowCount = 0;
            for(int r = i - (k - 1); r < i - (k - 1) + k; r++){
                for(int c = j - (k - 1); c < j - (k - 1) + k; c++){
                    #ifdef debug
                    printf("(%d, %d)%c",r, c, " \n"[c == j - (k - 1) + k - 1]);
                    #endif
                    colMatrix[rowCount][colCount] = imgMatrix[r][c];
                    rowCount ++;
                }
            }
            colCount ++;
            #ifdef debug
            printf("\n");
            #endif
        }
    }
    
}