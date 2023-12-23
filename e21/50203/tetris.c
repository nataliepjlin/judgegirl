#include<stdio.h>
int max(int a, int b){
    if(a > b) return a;
    else return b;
}
int main(){
    int n; int heights[100001] = {0};
    scanf("%d", &n);
    int leftmost, type;
    while(scanf("%d%d", &leftmost, &type) == 2){
        if(type == 0){
            if((heights[leftmost] > heights[leftmost + 1]) && (heights[leftmost] >heights[leftmost + 2])){
                // printf("leftmost\n");
                heights[leftmost] += 1;
                heights[leftmost + 1] = heights[leftmost];
                heights[leftmost + 2] = heights[leftmost] - 1;
            }// leftmost as base
            else if((heights[leftmost + 2] > heights[leftmost]) && (heights[leftmost + 2] > heights[leftmost + 1])){
                // printf("leftmost + 2\n");
                heights[leftmost + 2] += 1;
                heights[leftmost] = heights[leftmost + 1] = heights[leftmost + 2] + 1;
            }// leftmost + 2 as base
            else if((heights[leftmost + 1] > heights[leftmost]) && (heights[leftmost + 1] > heights[leftmost + 2])){
                // printf("leftmost+1\n");
                heights[leftmost + 1] += 2;
                heights[leftmost] = heights[leftmost + 1];
                heights[leftmost + 2] = heights[leftmost + 1] - 1;
            }// leftmost + 1 as base
            else{
                int base = max(max(heights[leftmost + 2], heights[leftmost + 1]), heights[leftmost]);
                heights[leftmost + 1] = base + 2;
                heights[leftmost] = heights[leftmost + 1];
                heights[leftmost + 2] = heights[leftmost + 1] - 1;
            }
        }//type 0
        else if(type == 1){
            if((heights[leftmost + 2] > heights[leftmost + 1]) && (heights[leftmost + 2] >heights[leftmost])){
                // printf("leftmost + 2\n");
                heights[leftmost + 2] += 1;
                heights[leftmost + 1] = heights[leftmost + 2];
                heights[leftmost] = heights[leftmost + 2] - 1;
            }// leftmost as base
            else if((heights[leftmost] > heights[leftmost + 2]) && (heights[leftmost] > heights[leftmost + 1])){
                // printf("leftmost\n");
                heights[leftmost] += 1;
                heights[leftmost + 2] = heights[leftmost + 1] = heights[leftmost] + 1;
            }// leftmost + 2 as base
            else if((heights[leftmost + 1] > heights[leftmost + 2]) && (heights[leftmost + 1] > heights[leftmost])){
                // printf("leftmost+1\n");
                heights[leftmost + 1] += 2;
                heights[leftmost + 2] = heights[leftmost + 1];
                heights[leftmost] = heights[leftmost + 1] - 1;
            }// leftmost + 1 as base
            else{
                int base = max(max(heights[leftmost + 2], heights[leftmost + 1]), heights[leftmost]);
                heights[leftmost + 1] = base + 2;
                heights[leftmost + 2] = heights[leftmost + 1];
                heights[leftmost] = heights[leftmost + 1] - 1;
            }
        }
        else if(type == 2){
            int base = max(max(heights[leftmost + 2], heights[leftmost + 1]), heights[leftmost]);
            heights[leftmost] = heights[leftmost + 2] = base + 1;
            heights[leftmost + 1] = base + 2;
        }
        else if(type == 3){
            if(heights[leftmost] > heights[leftmost + 1] || heights[leftmost + 2] > heights[leftmost + 1]){
                int base = max(heights[leftmost], heights[leftmost + 2]);
                heights[leftmost] = heights[leftmost + 1] = heights[leftmost + 2] = base + 1;
            }
            else{
                heights[leftmost + 1] += 2;
                heights[leftmost] = heights[leftmost + 2] = heights[leftmost + 1];
            }
        }
    }
    
    for(int i = 0; i < n; i ++){
        printf("%d%c", heights[i], " \n"[i == n - 1]);
    }
    return 0;
}