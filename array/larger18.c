#include<stdio.h>
 
void printmax(int arr[100][100], int i, int j, int r, int c){
    int print=1;
 
    if(i!=0){//up
        if(arr[i-1][j]>=arr[i][j]) print=0;//note that it's ">=", not ">" only
    }
    if((i!=r-1) && (print)){//down
        if(arr[i+1][j]>=arr[i][j]) print=0;
    }
    if((j!=0) && (print)){//left
        if(arr[i][j-1]>=arr[i][j]) print=0;
    }
    if((j!=c-1) && (print)){//right
        if(arr[i][j+1]>=arr[i][j]) print=0;
    }
 
    if(print){
        printf("%d\n",arr[i][j]);
    }
}
 
int main(){
    int r, c;
    int arr[100][100];
 
    scanf("%d%d", &r, &c);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%d", &arr[i][j]);
        }
    }
 
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printmax(arr, i, j, r, c);
        }
    }
    return 0;
}