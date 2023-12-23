#include<stdio.h>
#include<stdlib.h>
void place(int i, int pos[8]){
    for(int col = 0; col < i; col++){
        printf("%d%c", pos[col], " \n"[col == i - 1]);
    }
    if(i == 8)
        exit(0);

    for(int col = 0; col < 8; col++){
        int conflict = 0;
        for(int prev = 0; prev < i && !conflict; prev++){
            conflict = (pos[prev] == col ||
            abs(col - pos[prev]) == (i - prev));
        }
        if(!conflict){
            pos[i] = col;
            place(i + 1, pos);
        }
    }
}
int main(){
    int pos[8];
    place(0, pos);
    return 0;
}