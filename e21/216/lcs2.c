#include<stdio.h>
#include<string.h>
#define LEN 16
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
int solve(char s1[], char s2[], char s3[]){
    if(s1[0] == '\0' || s1 == NULL 
    || s2[0] == '\0' || s2 == NULL 
    || s3[0] == '\0' || s3 == NULL)
        return 0;
    if(s1[0] == s2[0] && s2[0] == s3[0])
        return 1 + solve(s1 + 1, s2 + 1, s3 + 1);
    int case2_1 = 0, case2_2 = 0, case2_3 = 0;
    char *ptr[3][3] = {{NULL, strchr(s2, s1[0]), strchr(s3, s1[0])},
                       {strchr(s1, s2[0]), NULL, strchr(s3, s2[0])},
                       {strchr(s1, s3[0]), strchr(s2, s3[0]), NULL}};
    if(ptr[0][1] != NULL && ptr[0][2] != NULL){
        case2_1 = 1 + solve(s1 + 1, ptr[0][1] + 1, ptr[0][2] + 1);
    }
    if(ptr[1][0] != NULL && ptr[1][2] != NULL){
        case2_2 = 1 + solve(ptr[1][0] + 1, s2 + 1, ptr[1][2] + 1);
    }
    if(ptr[2][0] != NULL && ptr[2][1] != NULL){
        case2_3 = 1 + solve(ptr[2][0] + 1, ptr[2][1] + 1,s3 + 1);
    }
    int case3 = solve(s1 + 1, s2 + 1, s3 + 1);
    return (max(case2_1, max(case2_2, max(case2_3, case3))));
}
int main(){
    char s1[LEN], s2[LEN], s3[LEN];
    while(scanf("%s%s%s", s1, s2, s3) == 3){
        printf("%d\n", solve(s1, s2, s3));
    }
}