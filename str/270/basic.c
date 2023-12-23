#include <stdio.h>
#include <string.h>
#define MAXCHAR 8
#define MAXVAR 100
#define MAXSTA 1001
// #define debug

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}

int mod(int a, int b) {
    return a % b;
}

void readVar(char variable[MAXVAR][MAXCHAR], int value[MAXVAR], int *idx){
    char name[MAXCHAR], eq[2];
    scanf("%s", name);
    while(strcmp(name, "END") != 0){
        strcpy(variable[*idx], name);
        scanf("%s", eq);
        scanf("%d", &value[*idx]);
        #ifdef debug
        printf("variable[%d] = %s, value[%d] = %d\n", *idx, variable[*idx], *idx, value[*idx]);
        #endif
        *idx += 1;
        scanf("%s", name);
    }
}
void readSta(char statements[MAXSTA][64], int *sidx){
    while(fgets(statements[*sidx], 64, stdin) != NULL){
        #ifdef debug
        printf("statements[%d] = %s\n", *sidx, statements[*sidx]);
        #endif
        *sidx += 1;
    }
}
int getVar(char variable[MAXVAR][MAXCHAR], char query[MAXCHAR], int idx){
    int i = 0;
    for(; i < idx; i++){
        if(strcmp(variable[i], query) == 0){
            return i;
        }
    }
}
int main(){
    char variable[MAXVAR][MAXCHAR] = {{0}};
    int value[MAXVAR] = {0}, idx = 0;
    readVar(variable, value, &idx);

    char statements[MAXSTA][64] = {{0}};
    int sidx = 0;
    readSta(statements, &sidx);

    //process line
    int line = 1;
    char type[MAXCHAR];
    while(1){
        sscanf(statements[line], "%s", type);
        #ifdef debug
        printf("statement[%d] = %s\n", line, statements[line]);
        #endif
        char s[MAXCHAR];
        if(strcmp(type, "STOP") == 0){
            break;
        }//stop
        if(strcmp(type, "GOTO") == 0){
            sscanf(statements[line], "%s%d", s, &line);
        }//goto
        else if(strcmp(type, "PRINT") == 0){
            char toPrint[MAXCHAR];
            sscanf(statements[line], "%s%s", s, toPrint);
            int i = getVar(variable, toPrint, idx);
            printf("%d\n", value[i]);
            line++;
        }//print
        else if(strcmp(type, "IF") == 0){
            //IF N > HUNDRED GOTO 11
            char opd1[MAXCHAR], opr[3], opd2[MAXCHAR], go[MAXCHAR];
            int newLine;
            sscanf(statements[line], "%s%s%s%s%s%d", s, opd1, opr, opd2, go, &newLine);
            int i1 = getVar(variable, opd1, idx), i2 = getVar(variable, opd2, idx);
            if(value[i1] == value[i2] && strcmp(opr, "==") == 0
            || value[i1] != value[i2] && strcmp(opr, "!=") == 0
            || value[i1] > value[i2] && strcmp(opr, ">") == 0
            || value[i1] < value[i2] && strcmp(opr, "<") == 0
            || value[i1] >= value[i2] && strcmp(opr, ">=") == 0
            || value[i1] <= value[i2] && strcmp(opr, "<=") == 0)
                line = newLine;
            else
                line++;
        }//if
        else{
            //F = TWO + ZERO
            char var[MAXCHAR], eq[2], var1[MAXCHAR], opr[2], var2[MAXCHAR];
            sscanf(statements[line], "%s%s%s%s%s", var, eq, var1, opr, var2);
            int i = getVar(variable, var, idx), i1 = getVar(variable, var1, idx), i2 = getVar(variable, var2, idx);          
            int (*operators[5])(int, int) = {&add, &sub, &mul, &div, &mod};
            value[i] = operators[(strcmp(opr, "-") == 0) * 1
                                +(strcmp(opr, "*") == 0) * 2
                                +(strcmp(opr, "/") == 0) * 3
                                +(strcmp(opr, "%") == 0) * 4](value[i1], value[i2]);
            line++;
        }
    }//while 1
    return 0;
}