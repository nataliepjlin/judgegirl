#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 80
// #define debug
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int flag = 0;
        char str1[SIZE], str2[SIZE];
        scanf("%s%s", str1, str2);
        #ifdef debug
        printf("\nstr1 = %s, str2 = %s\n", str1, str2);
        #endif
        if(strcmp(str1, str2) == 0){
            #ifdef debug
            printf("same str\n");
            #endif
            flag = 1;
        } 
        else if(abs(strlen(str1) - strlen(str2)) == 1){
            #ifdef debug
            printf("len diff by 1\n");
            #endif
            char tmp[SIZE], tmpcut[SIZE], shortStr[SIZE];
            if(strlen(str1) > strlen(str2)){
                strcpy(tmp, str1);
                strcpy(shortStr, str2);
            } 
            else{
                strcpy(tmp, str2);
                strcpy(shortStr, str1);
            }
            for(int l = 0; l < strlen(tmp) && !flag; l++){
                strcpy(tmpcut, tmp);
                memmove(tmpcut + l, tmpcut + l + 1, strlen(tmpcut) - l);
                #ifdef debug
                printf("tmpcut = %s\n", tmpcut);
                #endif
                if(strcmp(tmpcut, shortStr) == 0){
                    #ifdef debug
                    printf("same with shortStr = %s\n", shortStr);
                    #endif
                    flag = 1;
                }
            }
        }
        else if(strlen(str1) == strlen(str2)){
            flag = 1;
            #ifdef debug
            printf("same len\n");
            #endif
            int switchCount = 0;
            for(int l = 0; l < strlen(str1) && flag; l++){
                #ifdef debug
                printf("l = %d\n", l);
                #endif
                if(str1[l] != str2[l]){
                    #ifdef debug
                    printf("checking %dth char\n", l);
                    #endif
                    if(l + 1 < strlen(str1) && !switchCount
                    && str1[l + 1] == str2[l] && str1[l] == str2[l + 1]){
                        #ifdef debug
                        printf("str1[l + 1] = %c, str2[l] = %c\n", str1[l + 1], str2[l]);
                        printf("str1[l] = %c, str2[l + 1] = %c\n", str1[l], str2[l + 1]);
                        #endif
                        l ++;
                        switchCount = 1;
                        #ifdef debug
                        printf("now l = %d\n",l);
                        #endif
                    } 
                    else flag = 0;
                }
            }
        }
        
        (flag) ? printf("yes\n") : printf("no\n");
    }
    return 0;
}