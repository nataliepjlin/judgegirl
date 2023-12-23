#include<stdio.h>
#include<string.h>
#define MAXCHAR 81
#define MAXN 51
typedef struct{
    char lastname[MAXCHAR];
    char firstname[MAXCHAR];
    char ID[MAXCHAR];
    int salary;
    int age;
}DATA;
int getIdx(char *field){
    return ((field[0] == 'f') * 1 
            + (field[0] == 'I') * 2 
            + (field[0] == 's') * 3 
            + (field[0] == 'a') * 4);
}
void markField(int pfield[5], char *field, int *p){
    pfield[*p] = getIdx(field);
    *p += 1;
}
int main(){
    int n;
    scanf("%d", &n);
    DATA data[MAXN];
    for(int i = 0; i < n; i++){
        scanf("%s", data[i].lastname);
        scanf("%s", data[i].firstname);
        scanf("%s", data[i].ID);
        scanf("%d", &data[i].salary);
        scanf("%d", &data[i].age);
    }
    int query;
    int pdata[MAXN] = {0}, pfield[8 * 4] = {0};
    scanf("%d", &query);
    for(int q = 0; q < query; q++){
        char field[MAXCHAR];
        char op[3], cond[MAXCHAR];
        int num;
        int p = 0;
        scanf("%s", field);//select
        while(scanf("%s", field) == 1){
            if(field[0] == 'w')
                break;
            markField(pfield, field, &p);
        }
        scanf("%s%s", field, op);
        int idx = getIdx(field);
        if(idx == 3 || idx == 4){
            scanf("%d", &num);
            for(int i = 0; idx == 3 && i < n; i++){
                pdata[i] = (data[i].salary == num && op[0] == '='
                || data[i].salary > num && op[0] == '>'
                || data[i].salary < num && op[0] == '<');
            }
            for(int i = 0; idx == 4 && i < n; i++){
                pdata[i] = (data[i].age == num && op[0] == '='
                ||  data[i].age > num && op[0] == '>'
                ||  data[i].age < num && op[0] == '<');
            } 
        }//int
        else{
            scanf("%s", cond);
            for(int i = 0; !idx && i < n; i++){
                pdata[i] = ((op[0] == '=' && !strcmp(data[i].lastname, cond))
                || (op[0] == '!' && strcmp(data[i].lastname, cond) != 0));
            }
            for(int i = 0; idx == 1 && i < n; i++){
                pdata[i] = ((op[0] == '=' && !strcmp(data[i].firstname, cond))
                || (op[0] == '!' && strcmp(data[i].firstname, cond) != 0));
            }
            for(int i = 0; idx == 2 && i < n; i++){
                pdata[i] = ((op[0] == '=' && !strcmp(data[i].ID, cond))
                || (op[0] == '!' && strcmp(data[i].ID, cond) != 0));
            }
        }//str
        for(int i = 0; i < n; i++){
            for(int j = 0; pdata[i] && j < p; j++){
                (pfield[j] == 0 && printf("%s", data[i].lastname));
                (pfield[j] == 1 && printf("%s", data[i].firstname));
                (pfield[j] == 2 && printf("%s", data[i].ID));
                (pfield[j] == 3 && printf("%d", data[i].salary));
                (pfield[j] == 4 && printf("%d", data[i].age));
                printf("%c", " \n"[j == p - 1]);
            }
        }
    }//qth query
    return 0;
}