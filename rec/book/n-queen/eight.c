#include<stdio.h>
#include<stdlib.h>
void place(int idx, int pos[]){
    for(int q = 0; q < idx; q++){
        printf("%d%c", pos[q], " \n"[q == idx - 1]);
    }
    if(idx == 8)
        exit(-1);
    for(int col = 0; col < 8; col++){
        int conflict = 0;
        for(int q = 0; q < idx && !conflict; q++){
            conflict = (pos[q] == col
            || abs(col - pos[q]) == idx - q);
        }
        if(!conflict){
            pos[idx] = col;
            place(idx + 1, pos);
        }
    }
}
int main(){
    int pos[8] = {0};
    place(0, pos);
    return 0;
}