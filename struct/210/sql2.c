#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXCHAR 81
#define MAXN 51
// #define debug
typedef struct{
    char strs[3][MAXCHAR];
    int nums[5];
}DATA;
void str2cmd(char *str, char *cmd[32]){
    int c = 0;
    char *s = strtok(str, " \n");
    while(s != NULL){
        cmd[c] = s;
        c++;
        s = strtok(NULL, " \n");
    }
}
int numify(char *field){
    return ((field[0] == 'f') * 1 
            + (field[0] == 'I') * 2 
            + (field[0] == 's') * 3 
            + (field[0] == 'a') * 4);
}
void printData(DATA data, int pfield[], int p){
    for(int i = 0; i < p; i++){
        if(pfield[i] <= 2) printf("%s", data.strs[pfield[i]]);
        else printf("%d", data.nums[pfield[i]]);
        printf("%c", " \n"[i == p - 1]);
    }
}
int main(){
    DATA data[MAXN];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", data[i].strs[0]);
        scanf("%s", data[i].strs[1]);
        scanf("%s", data[i].strs[2]);
        scanf("%d", &data[i].nums[3]);
        scanf("%d", &data[i].nums[4]);
    }
    int query;
    scanf("%d", &query);
    char s[1000];
    char *cmd[32];
    int pfield[40];
    getchar();
    for(int q = 0; q < query; q++){
        fgets(s, 1000, stdin);
        #ifdef debug
        printf("s = %s\n", s);
        #endif
        str2cmd(s, cmd);
        int c = 1;//0: "select"
        int p = 0;
        while(cmd[c][0] != 'w'){
            #ifdef debug
            printf("cmd[%d] = %s\n", c, cmd[c]);
            #endif
            pfield[p] = numify(cmd[c]);
            p++, c++;
        }
        c++;//skip "where"
        int field = numify(cmd[c]);
        #ifdef debug
        printf("cmd[c] = %s, field = %d\n", cmd[c], field);
        #endif
        c++;
        if(field <= 2){
            if(cmd[c][0] == '='){
                c++;
                #ifdef debug
                printf("cmp with %s\n", cmd[c]);
                #endif
                for(int d = 0; d < n; d++){
                    if(!strcmp(data[d].strs[field], cmd[c])){
                        printData(data[d], pfield, p);
                    }
                }
            }
            else{
                c++;
                for(int d = 0; d < n; d++){
                    if(strcmp(data[d].strs[field], cmd[c])){
                        printData(data[d], pfield, p);
                    }
                }
            }
        }//str
        else{
            int cond = atoi(cmd[c + 1]);
            #ifdef debug
            printf("cond = %d\n", cond);
            #endif
            if(cmd[c][0] == '='){
                for(int d = 0; d < n; d++){
                    if(data[d].nums[field] == cond){
                        printData(data[d], pfield, p);
                    }
                }
            }
            else if(cmd[c][0] == '<'){
                c++;
                for(int d = 0; d < n; d++){
                    if(data[d].nums[field] < cond){
                        printData(data[d], pfield, p);
                    }
                }
            }
            else{
                for(int d = 0; d < n; d++){
                    if(data[d].nums[field] > cond){
                        printData(data[d], pfield, p);
                    }
                }
            }
        }//num
    }//qth query
    return 0;
}