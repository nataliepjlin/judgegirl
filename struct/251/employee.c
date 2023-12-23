#include "employee.h"
#include<stdio.h>
#include<string.h>
// #define debug
int relation(Employee *employee1, Employee *employee2) {
    Employee *e1 = employee1;
    while(e1 != e1->boss){
        #ifdef debug
        printf("e1 = %s\n", e1->first_name);
        #endif
        if(e1->boss == employee2)
            return 1;
        e1 = e1->boss;
    }
    #ifdef debug
    printf("final e1 = %s\n", e1->first_name);
    #endif
    Employee *e2 = employee2;
    while(e2 != e2->boss){
        #ifdef debug
        printf("e2 = %s\n", e2->first_name);
        #endif
        if(e2->boss == employee1)
            return 2;
        e2 = e2->boss;
    }
    #ifdef debug
    printf("final e2 = %s\n", e2->first_name);
    #endif
    if(e1 == e2)
        return 3;
    return 4;
}