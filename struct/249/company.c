#include<stdio.h>
#include<string.h>
#define MAXN 32
// #define debug
typedef struct{
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
}EMPLOYEE;
void getRelation(char *f1, char *l1, char *f2, char *l2,
EMPLOYEE employees[], int n, int boss[]){
    int idx1 = -1, idx2 = -1;
    for(int i = 0; i < n && (idx1 == -1 || idx2 == -1); i++){
        if(!strcmp(f1, employees[i].first_name) && !strcmp(l1, employees[i].last_name))
            idx1 = i;
        if(!strcmp(f2, employees[i].first_name) && !strcmp(l2, employees[i].last_name))
            idx2 = i;
    }
    int i = idx1;
    while(boss[i] != i){
        i = boss[i];
        if(i == idx2){
            printf("subordinate\n");
            return;
        }
    }
    int j = idx2;
    while(boss[j] != j){
        j = boss[j];
        if(j == idx1){
            printf("supervisor\n");
            return;
        }
    }
    if(i == j){
        printf("colleague\n");
        return;
    }
    printf("unrelated\n");
}
int main(){
    int n;
    scanf("%d", &n);
    EMPLOYEE employees[MAXN];
    for(int i = 0; i < n; i++){
        scanf("%d", &employees[i].id);
        scanf("%s", employees[i].first_name);
        scanf("%s", employees[i].last_name);
        scanf("%d", &employees[i].boss_id);
    }
    int boss[MAXN];
    for(int i = 0; i < n; i++){
        int found = 0;
        for(int j = 0; j < n && !found; j++){
            if(employees[i].boss_id == employees[j].id){
                boss[i] = j;
                found = 1;
            }
        }
    }//get first related boss
    int query;
    scanf("%d", &query);
    char f1[32], l1[32], f2[32], l2[32]; 
    for(int q = 0; q < query; q++){
        scanf("%s%s%s%s", f1, l1, f2, l2);
        getRelation(f1, l1, f2, l2, employees, n, boss);
    }
}