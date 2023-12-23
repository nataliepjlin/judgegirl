#include<stdio.h>
#include<string.h>
#define LEN 2005
// #define debug
typedef struct{
    int val;
    int valid;
    int next;
}info;
enum exp{TRUE, FALSE, AND, OR, NOT, LBR, RBR};
info solve(int idx, int n, int cmd[]){
    #ifdef debug
    printf("idx = %d\n", idx);
    #endif
    if(idx >= n || cmd[idx] == AND || cmd[idx] == OR || cmd[idx] == RBR)
        return (info){0, 0, 0};/*invalid*/

    else if(cmd[idx] == TRUE || cmd[idx] == FALSE){
        #ifdef debug
        printf("true false\n");
        #endif
        return (info){cmd[idx] == TRUE, 1, idx + 1};
    }
    else if(cmd[idx] == NOT){
        #ifdef debug
        printf("NOT\n");
        #endif
        info next_info = solve(idx + 1, n, cmd);
        if(next_info.valid)
            return (info){!next_info.val, 1, next_info.next};
        else
            return (info){0, 0, 0};/*invalid*/
    }
    else if(cmd[idx] == LBR){
        #ifdef debug
        printf("(\n");
        #endif
        info left = solve(idx + 1, n, cmd);
        if(!left.valid)
            return (info){0, 0, 0};
        int op = cmd[left.next];
        info right = solve(left.next + 1, n, cmd);
        if(!right.valid 
        || right.next == n || cmd[right.next] != RBR)
            return (info){0, 0, 0};
        #ifdef debug
        printf("left.val = %d, right.val = %d\n", left.val, right.val);
        #endif
        if(op == OR)
            return(info){left.val || right.val, 1, right.next + 1};
        else if(op == AND)
            return(info){left.val && right.val, 1, right.next + 1};
        else   
            return (info){0, 0, 0}; 
    }
    else
        return (info){0, 0, 0}; 
}
int main(){
    char str[LEN];
    char delims[] = " \t\n";
    while(fgets(str, sizeof(str), stdin) != NULL){
        int cmd[LEN] = {0}, n = 0;
        char *tok = strtok(str, delims);
        int valid = 1;
        while(tok != NULL && valid){
            if(!strcmp(tok, "!"))
                cmd[n++] = NOT;
            else if(!strcmp(tok, "&&"))
                cmd[n++] = AND;
            else if(!strcmp(tok, "||"))
                cmd[n++] = OR;
            else if(!strcmp(tok, "("))
                cmd[n++] = LBR;
            else if(!strcmp(tok, ")"))
                cmd[n++] = RBR;
            else if(!strcmp(tok, "true"))
                cmd[n++] = TRUE;
            else if(!strcmp(tok, "false"))
                cmd[n++] = FALSE;
            else
                valid = 0;
            tok = strtok(NULL, delims);
        }/*toking input*/
        if(valid){
            info sol = solve(0, n, cmd);
            if(sol.valid && sol.next == n){
                (sol.val) ? printf("true\n") : printf("false\n");
            }
            else
                printf("invalid\n");
        }
        else
            printf("invalid\n");
    }/*fgets*/
}