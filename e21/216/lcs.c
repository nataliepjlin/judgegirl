#include<stdio.h>
#include<string.h>
#define LEN 16
#define debug
int getMax(int a, int b){
    return a * (a > b) + b * (a <= b);
}
void solve(char s1[], char s2[], char s3[], int l1, int l2, int l3
, int count, int *maxct){
    #ifdef debug
    printf("s1 = %s, s2 = %s, s3 = %s\n", s1, s2, s3);
    printf("l1 = %d, l2 = %d, l3 = %d\n", l1, l2, l3);
    #endif
    if(l1 <= 0 || l2 <= 0 || l3 <= 0){
        *maxct = getMax(count, *maxct);
        return;
    }
    if((!strcmp(s1, s2)) && !strcmp(s2, s3)){
        count += l1;
        *maxct = getMax(count, *maxct);
        return;
    }
    if(s1[0] == s2[0] && s2[0] == s3[0]){
        #ifdef debug
        printf("case 1\n");
        #endif
        solve(s1 + 1, s2 + 1, s3 + 1, l1 - 1, l2 - 1, l3 - 1, count + 1, maxct);
    }
    char *ptr2, *ptr3;
    for(int i = 0; i < l1; i++){
        ptr2 = strchr(s2, s1[i]), ptr3 = strchr(s3, s1[i]);
        if(ptr2 != NULL && ptr3 != NULL){
            #ifdef debug
            printf("case 2\n");
            #endif
            solve(s1 + i + 1, ptr2 + 1, ptr3 + 1, 
            l1 - i - 1, l2 - (ptr2 - s2) - 1, l3 - (ptr3 - s3) - 1, 
            count + 1, maxct);
        }
    }
    #ifdef debug
    printf("case 3\n");
    #endif
    solve(s1 + 1, s2 + 1, s3 + 1, l1 - 1, l2 - 1, l3 - 1, count, maxct);
}
int main(){
    char s1[LEN], s2[LEN], s3[LEN];
    while(scanf("%s%s%s", s1, s2, s3) == 3){
        int l1 = strlen(s1), l2 = strlen(s2), l3 = strlen(s3);
        int maxct = 0;
        solve(s1, s2, s3, l1, l2, l3, 0, &maxct);
        printf("%d\n", maxct);
        #ifdef debug
        printf("##########\n");
        #endif
    }
}