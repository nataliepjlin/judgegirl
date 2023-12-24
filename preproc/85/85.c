#include <stdio.h>
#include <stdlib.h>
#define ull unsigned long long
int cmp(const void *a, const void *b){
    ull *pa = (ull*)a, *pb = (ull*)b;
    if(*pa > *pb)
        return 1;
    else if(*pa < *pb)
        return -1;
    return 0;
}
int main(){
    int n;
    scanf("%d", &n);
    ull dates[1000000];
    ull y, m, d;
    for(int i = 0; i < n; i++){
        scanf("%llu%llu%llu", &y, &m, &d);
        dates[i] = 10000 * y + 100 * m + d;
    }
    qsort(dates, n, sizeof(ull), cmp);
    for(int i = 0; i < n; i++){
        y = dates[i] / 10000, m = (dates[i] - y * 10000) / 100, d = dates[i] % 100;
        printf("%llu %llu %llu\n", y, m, d);
    }
    return 0;
}