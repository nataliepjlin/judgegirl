#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct info{
    uint64_t num;
    int cnt;
}info;
int cmp(const void *a, const void *b){
    info *pa = (info*)a, *pb = (info*)b;
    if(pa->cnt > pb->cnt
    || (pa->cnt == pb->cnt && pa->num > pb->num))
        return 1;
    else if(pa->cnt < pb->cnt
    || (pa->cnt == pb->cnt && pa->num < pb->num))
        return -1;
    return 0;
}
int counter(uint64_t num){
    int cnt = 0;
    while(num){
        cnt += (num % 2);
        num /= 2;
    }
    return cnt;
}
int main(){
    info arr[1000]; int n = 0;
    while(scanf("%ld", &arr[n].num) == 1){
        arr[n].cnt = counter(arr[n].num);
        n++;
    }
    qsort(arr, n, sizeof(info), cmp);
    for(int i = 0; i < n; i++){
        printf("%ld\n", arr[i].num);
    }
}