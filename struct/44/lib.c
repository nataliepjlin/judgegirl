#include "book.h"
#include "date.h"
#include<stdio.h>
// #define debug
int isleap(int y){
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}
int dayCount(struct Date date){
    int n = date.year - 800 - 1;
    static int dm[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    return 365 * n + ((n / 4) - (n / 100) + (n / 400)) + dm[date.month] + (date.month > 2 && isleap(date.year)) + date.day;
}
int diff(struct Date date_borrowed, struct Date date_returned){
    int d = dayCount(date_returned) - dayCount(date_borrowed) + 1;
    #ifdef debug
    printf("d = %d\n", d);
    #endif
    return d;
}
int getDist(unsigned int importance){
    int dist = 0;
    unsigned int mask = 1;
    while((importance & mask) != 1){
        importance >>= 1;
    }
    importance >>= 1;
    while((importance & mask) != 1){
        dist ++;
        importance >>= 1;
    }
    #ifdef debug
    printf("dist = %d\n", dist);
    #endif
    return dist;
}
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned){
    int d = diff(date_borrowed, date_returned);
    int table[] = {90, 10, 100, 5};
    d -= table[book.type];
    if(d <= 0)
        return 0;
    int fine = getDist(book.importance) * d;
    return fine;
}