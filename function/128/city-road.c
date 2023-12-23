#include<stdio.h>
#include<stdbool.h>
void intersection(int map[100][100], int result[4]){
    for(int i=0;i<4;i++){
        result[i]=0;
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(map[i][j]==1){
                int neighbor=0;
                if((map[i+1][j]==1)&&(i<99)) neighbor++;
                if((map[i-1][j]==1)&&(i>0)) neighbor++;
                if((map[i][j+1]==1)&&(j<99)) neighbor++;
                if((map[i][j-1]==1)&&(j>0)) neighbor++;
                if(neighbor==4) result[0]++;
                else if(neighbor==3) result[1]++;
                else if(neighbor==1) result[3]++;
                else if(neighbor==2){
                    int straightline = 1;
                    if((i>0&&i<99)&&(map[i-1][j]==map[i+1][j]))
                        straightline = 0;
                    else if((j>0&&j<99)&&(map[i][j-1]==map[i][j+1]))
                        straightline = 0;
                    if(straightline == 1) 
                        result[2]++;
                }
            }
        }
    }
}

int main(){
    int map[100][100];
    int result[4];
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            scanf("%d",&map[i][j]);
        }
    }
    intersection(map,result);
    for(int i = 0; i < 4; i++){
        printf("%d\n", result[i]);
    }
}

