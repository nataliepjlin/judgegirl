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
int main(){
    INFO infos[N]; int n = 0;
    while(scanf("%lld%lld%lld%s%d", &infos[n].y, &infos[n].m, &infos[n].d, infos[n].name, &infos[n].amount) == 5){
        infos[n].date = infos[n].y * 10000 + infos[n].m * 100 + infos[n].d;
        n++;
    }
    qsort(infos, n, sizeof(INFO), cmp);
    INFO *prev = &infos[0];
    for(int i = 1; i < n; i++){
        if(prev->date == infos[i].date && !strcmp(prev->name, infos[i].name)){
            infos[i].amount += prev->amount;
        }
        else{
            printf("%lld %lld %lld %s %d\n", prev->y, prev->m, prev->d, prev->name, prev->amount);
        }
        prev = &infos[i];
    }
    (n != 0
    && printf("%lld %lld %lld %s %d\n", prev->y, prev->m, prev->d, prev->name, prev->amount));
}