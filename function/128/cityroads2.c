#include<stdio.h>
int map[100][100];
int oob(int r, int c, int checklist[][2], int cidx){
    int flag = 0;
    if(r + checklist[cidx][0] < 0 || r + checklist[cidx][0] >= 100
    || c + checklist[cidx][1] < 0 || c + checklist[cidx][1] >= 100)
        flag = 1;
    return flag;
}
void intersection(int map[100][100], int result[4]){
    for(int i = 0; i < 4; i++){
        result[i] = 0;
    }

    int checklist[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(map[i][j] == 0) continue;

            int count = 0;
            for(int cidx = 0; cidx < 4; cidx ++){
                if(oob(i, j, checklist, cidx)) continue;
                count += map[i + checklist[cidx][0]][j + checklist[cidx][1]];
            }

            if(count == 2){
                count = 0;
                for(int cidx = 0; cidx < 4; cidx ++){
                    if(oob(i, j, checklist, cidx) ||
                    oob(i, j, checklist, (cidx + 1) % 4)) continue;

                    if(map[i + checklist[cidx][0]][j + checklist[cidx][1]] && map[i + checklist[(cidx + 1) % 4][0]][j + checklist[(cidx + 1) % 4][1]]){
                        count = 2;
                        break;
                    } 
                }
            }

            if(4 - count < 4){
                result[4 - count] ++;
            }
        }//j
    }//i
    
}
int main(){
    int result[4] = {0};
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    intersection(map, result);
    for(int i = 0; i < 4; i++){
        printf("%d\n", result[i]);
    }
    return 0;
}