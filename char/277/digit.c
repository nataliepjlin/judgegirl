#include<stdio.h>
#include<string.h>
#define MAXLEN 11
#define debug
void printH(char str[], int pos, int w, int len, int dir[][7]){
    for(int i = 0; i < len; i++){
        int num = str[i] - '0';
        printf(" ");
        char p = (dir[num][pos]) * str[i] + ' ' * !(dir[num][pos]);
        for(int j = 0; j < w - 3; j++){
            printf("%c", p);
        }
        printf(" ");
        printf("%c", " \n"[i == len - 1]);
    }
}
void printV(char str[], int pos, int w, int len, int dir[][7]){
    for(int i = 0; i < len; i++){
        int num = str[i] - '0';
        char p1 = (dir[num][pos]) * str[i] + ' ' * !(dir[num][pos]);
        char p2 = (dir[num][pos + 1]) * str[i] + ' ' * !(dir[num][pos + 1]);
        printf("%c", p1);
        for(int j = 0; j < w - 3; j++){
            printf(" ");
        }
        printf("%c", p2);
        printf("%c", " \n"[i == len - 1]);
    }
}
int main(){
    char str[MAXLEN];
    int dir[][7] = {{1, 1, 1, 0, 1, 1, 1},
                    {0, 0, 1, 0, 0, 1, 0},
                    {1, 0, 1, 1, 1, 0, 1},
                    {1, 0, 1, 1, 0, 1, 1},
                    {0, 1, 1, 1, 0, 1, 0},
                    {1, 1, 0, 1, 0, 1, 1},
                    {1, 1, 0, 1, 1, 1, 1},
                    {1, 1, 1, 0, 0, 1, 0},
                    {1, 1, 1, 1, 1, 1, 1},
                    {1, 1, 1, 1, 0, 1, 0}};
    int w, h;
    while(scanf("%s%d%d", str, &w, &h) == 3){
        int len = strlen(str);
        for(int i = 0; i < h; i++){
            if(!i) printH(str, 0, w, len, dir);
            else if(i < h / 2) printV(str, 1, w, len, dir);
            else if(i == h / 2) printH(str, 3, w, len, dir);
            else if(i < h - 1) printV(str, 4, w, len, dir);
            else printH(str, 6, w, len, dir);
        }
    }
}