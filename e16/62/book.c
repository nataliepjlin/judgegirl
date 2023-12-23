#include"book.h"
#include<string.h>
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int getauthidx(BookAuthor authorArr[], char *book, int N){
    for(int i = 0; i < N; i++){
        if(!strcmp(authorArr[i].book_title, book))
            return i;
    }
    return N;
}
BookInfoList merge(int N, int M, BookAuthor authorArr[], BookSelling sellingArr[]){
    BookInfoList infolist;
    infolist.num = M;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M - i - 1; j++){
            if(strcmp(sellingArr[j].book_title, sellingArr[j + 1].book_title) > 0
            || (!strcmp(sellingArr[j].book_title, sellingArr[j + 1].book_title)
            && sellingArr[j].date > sellingArr[j + 1].date)){
                char str[MAXL]; strcpy(str, sellingArr[j].book_title);
                strcpy(sellingArr[j].book_title, sellingArr[j + 1].book_title);
                strcpy(sellingArr[j + 1].book_title, str);

                swap(&sellingArr[j].date, &sellingArr[j + 1].date);
                swap(&sellingArr[j].selling, &sellingArr[j + 1].selling);
            }
        }
    }
    for(int i = 0; i < M; i++){
        infolist.books[i].date = sellingArr[i].date;
        infolist.books[i].selling = sellingArr[i].selling;
        strcpy(infolist.books[i].author, authorArr[getauthidx(authorArr, sellingArr[i].book_title, N)].author);
        strcpy(infolist.books[i].book_title, sellingArr[i].book_title);
    }
    return infolist;
}