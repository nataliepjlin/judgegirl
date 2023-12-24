#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 33
#define N 10001
#define ull unsigned long long
typedef struct INFO{
    char name[LEN];
    ull y, m, d, date;
    int amount;
}INFO;
int cmp(const void *a, const void *b){
    INFO *pa = (INFO*)a, *pb = (INFO*)b;
    if(pa->date > pb->date) return 1;
    else if(pa->date < pb->date) return -1;
    return strcmp(pa->name, pb->name);
}
int printable(INFO *infos, int i, int j){
    return(infos[i].date != infos[j].date
    || strcmp(infos[i].name, infos[j].name));
}
int main(){
    INFO infos[N]; int n = 0;
    while(scanf("%lld%lld%lld%s%d", &infos[n].y, &infos[n].m, &infos[n].d, infos[n].name, &infos[n].amount) == 5){
        infos[n].date = infos[n].y * 10000 + infos[n].m * 100 + infos[n].d;
        n++;
    }
    qsort(infos, n, sizeof(INFO), cmp);
    infos[n] = (INFO){"", 0, 0, 0, 0};
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += infos[i].amount;
        if(printable(infos, i, i + 1)){
            printf("%lld %lld %lld %s %d\n", infos[i].y, infos[i].m, infos[i].d, infos[i].name, sum);
            sum = 0;
        }
    }
}