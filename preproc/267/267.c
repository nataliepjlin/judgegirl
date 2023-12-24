#include <stdio.h>
#include <stdlib.h>
typedef struct info{
    int x, y, dist;
}info;
int cmp(const void *a, const void *b){
    info *pa = (info*)a, *pb = (info*)b;
    if(pa->dist > pb->dist
    || (pa->dist == pb->dist && (pa->x > pb->x
    || (pa->x == pb->x && pa->y > pb->y))))
        return 1;
    else if(pa->dist < pb->dist
    || (pa->dist == pb->dist && (pa->x < pb->x
    || (pa->x == pb->x && pa->y < pb->y))))
        return -1;
    return 0;
}
int main(){
    info infos[100000];
    int n = 0;
    while(scanf("%d%d", &infos[n].x, &infos[n].y) == 2){
        infos[n].dist = infos[n].x * infos[n].x + infos[n].y * infos[n].y;
        n++;
    }
    qsort(infos, n, sizeof(info), cmp);
    // for(int i = 0; i < n; i++){
    //     printf("%d %d\n", infos[i].x, infos[i].y);
    // }
    int px = 0, py = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += ((infos[i].x - px) * (infos[i].x - px) + (infos[i].y - py) * (infos[i].y - py));
        px = infos[i].x, py = infos[i].y;
    }
    printf("%d\n", sum);
}