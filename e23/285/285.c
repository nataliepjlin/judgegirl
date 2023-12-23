#include<stdio.h>
#include<string.h>
#define ALP 26
#define LEN 101
int perm(const int cnt[], int has[], int idx, int ans[], int n, int k){
    if(idx == n){
        int nowk = 0; 
        for(int i = 0; i < n && nowk <= k; i++){
            nowk += (cnt[ans[i]] * (i + 1));
        }
        return (nowk == k);
    }
    for(int i = 0; i < ALP; i++){
        if(has[i]){
            has[i] = 0;
            ans[idx] = i;
            if(perm(cnt, has, idx + 1, ans, n, k))
                return 1;
            has[i] = 1;
        }
    }
    return 0;
}
int main(){
    int has[ALP] = {0}, cnt[ALP] = {0};
    int k; scanf("%d", &k);
    char str[LEN]; int n = 0;
    while(scanf("%s", str) == 1){
        int len = strlen(str);
        for(int i = 0; i < len; i++){
            has[str[i] - 'a'] = 1;
            cnt[str[i] - 'a']++;
            n += (cnt[str[i] - 'a'] == 1);
        }
    }
    #ifdef debug
    printf("n = %d\n", n);
    #endif
    int ans[ALP];
    perm(cnt, has, 0, ans, n, k);
    for(int i = 0; i < n; i++){
        printf("%c%c", ans[i] + 'a', " \n"[i == n - 1]);
    }
}