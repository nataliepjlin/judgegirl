#include<stdio.h>
#include<string.h>
#define MAXM 100
#define MAXCHAR 50
// #define debug
typedef struct AUTHOR{
    char name[MAXCHAR];
    char books[MAXM][MAXCHAR];
    int sales;
}AUTHOR;
int getAuth(AUTHOR authors[], char query[], int a, int bookIdx[]){
    for(int i = 0; i < a; i++){
        for(int b = 0; b < bookIdx[i]; b++){
            if(strcmp(authors[i].books[b], query) == 0)
                return i;
        }
    }
    return -1;
}
int findPrev(AUTHOR authors[], int i,
char name[]){
    for(int a = 0; a < i; a++){
        if(strcmp(authors[a].name, name) == 0)
            return a;
    }
    return -1;
}
int main(){
    int m;
    scanf("%d", &m);
    AUTHOR authors[m]; int a = 0;
    int bookIdx[MAXM] = {0};
    for(int i = 0; i < m; i++){
        char name[MAXCHAR], book[MAXCHAR];
        scanf("%s%s", name, book);
        int found = findPrev(authors, i, name);
        if(found != -1){
            strcpy(authors[found].books[bookIdx[found]], book);
            #ifdef debug
            printf("add another book \"%s\" to author %s\n", authors[found].books[bookIdx[found]], authors[found].name);
            #endif
            bookIdx[found] ++;
        }
        else{
            strcpy(authors[a].name, name);
            strcpy(authors[a].books[bookIdx[a]], book);
            authors[a].sales = 0;
            #ifdef debug
            printf("newly added author %s, with book \"%s\"\n", authors[a].name, authors[a].books[bookIdx[a]]);
            #endif
            bookIdx[a] ++; 
            a++;
        }
    }//auth and book
    int max = -1, maxIdx = -1;
    for(int i = 0; i < m; i++){
        char query[MAXCHAR];
        int sale;
        scanf("%s%d", query, &sale);
        int auth = getAuth(authors, query, a, bookIdx);
        authors[auth].sales += sale;
        if(max < authors[auth].sales
        || max == authors[auth].sales && strcmp(authors[maxIdx].name, authors[auth].name) > 0){
            max = authors[auth].sales;
            maxIdx = auth;
        }
    }
    printf("%s %d\n", authors[maxIdx].name, max);
    return 0;
}