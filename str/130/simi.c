#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 81
int main(){
    char str1[MAX], str2[MAX];
    int n;
    scanf("%d", &n);
    while(n--){
        scanf("%s%s", str1, str2);
        int len1 = strlen(str1), len2 = strlen(str2);
        if(strcmp(str1, str2) == 0){
            printf("yes\n");
        }
        else if(abs(len1 - len2) > 1){
            printf("no\n");
        }
        else{
            int valid = 1;
            if(abs(len1 - len2) == 1){
                int i = 0, j = 0, diff = 0;
                if(len1 > len2){
                    while(i < len1 && j < len2 && valid){
                        if(str1[i] == str2[j]){
                            i++, j++;
                        }
                        else{
                            if(!diff){
                                i++;
                                diff++;
                            } 
                            else valid = 0;
                        }
                    }
                }
                else{//len1 < len2
                    while(i < len1 && j < len2 && valid){
                        if(str1[i] == str2[j]){
                            i++, j++;
                        }
                        else{
                            if(!diff){
                                j++;
                                diff++;
                            } 
                            else valid = 0;
                        }
                    }
                }
            }
            else{//same len
                int switchCount = 0;
                for(int i = 0; i < len1 && valid; i++){
                    if(str1[i] != str2[i]){
                        valid = (str1[i] == str2[i + 1]
                        && str1[i + 1] == str2[i] && !switchCount);
                        switchCount ++;
                        i += 2;
                    }
                }
            }
            (valid) ? printf("yes\n") : printf("no\n");
        }
    }
    return 0;
}