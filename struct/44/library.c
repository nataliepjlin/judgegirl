#include "book.h"
#include "date.h"
#include<stdio.h>
// #define debug
int isleap(int y){
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}
int dayInMonth(int y, int m){
    switch(m){
        case 1 : case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isleap(y) ?  29: 28;
        default:
            return -1;
    }
}
int countWithBase(struct Date date, int by){
    int c = 0;
    for(int y = by; y < date.year; y++){
        for(int m = 1; m <= 12; m++){
            c += dayInMonth(y, m);
        }
    }
    for(int m = 1; m < date.month; m++){
        c += dayInMonth(date.year, m);
    }
    c += date.day;
    return c;
}
int diff(struct Date date_borrowed, struct Date date_returned){
    int d = countWithBase(date_returned, date_borrowed.year) - countWithBase(date_borrowed, date_borrowed.year) + 1;
    return d;
}
int getDist(unsigned int importance){
    int dist = 0;
    int prev = -1;
    for(int i = 0; importance > 0; i++){
        if(importance % 2){
            dist += ((prev != -1) * (i - prev - 1));
            #ifdef debug
            printf("i = %d, prev = %d, nowdist = %d\n", i, prev, dist);
            #endif
            prev = i;
        }
        importance /= 2;
    }
    #ifdef debug
    printf("dist = %d\n", dist);
    #endif
    return dist;
}
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned){
    int d = diff(date_borrowed, date_returned);
    d -= (90 * (book.type == NOVEL) + 10 * (book.type == COMICS) + 
    100 * (book.type == MANUAL) + 5 * (book.type == TEXTBOOK));
    if(d <= 0)
        return 0;
    int fine = getDist(book.importance) * d;
    return fine;
}