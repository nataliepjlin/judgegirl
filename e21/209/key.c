#include<stdio.h>
#include<string.h>
// #define debug
int oob(int row, int col, int dr, int dc, int lens[]){
    return (row + dr < 0 || col + dc < 0
        || row + dr >= 3
        || col + dc >= lens[row + dr]);
}
int main(){
    char keyboard[][11] = {"qwertyuiop", 
                           "asdfghjkl", 
                           "zxcvbnm"};
    int dr[] = {0,-1,-1, 0, 1, 1};
    int dc[] = {1, 1, 0,-1,-1, 0};
    char c;
    scanf("%c", &c);
    printf("%c\n", c);
    int row = -1, col = -1;
    int lens[] = {10, 9, 7};
    for(int i = 0; i < 3 && row == -1; i++){
        for(int j = 0; j < lens[i] && row == -1; j++){
            if(keyboard[i][j] == c){
                row = i, col = j;
            }
        }
    }
    #ifdef debug
    printf("row = %d, col = %d\n", row, col);
    #endif
    int cmd;
    while(scanf("%d", &cmd) == 1){
        if(!oob(row, col, dr[cmd], dc[cmd], lens)){
            row += dr[cmd];
            col += dc[cmd];
            printf("%c\n", keyboard[row][col]);
        }
    }
    return 0;
}