#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee{
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
};
typedef struct employee Employee;
 
void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.
 
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}
Employee* find_employee_by_id( Employee *set, int n, int id ){
    for(int i = 0; i < n; i++){
        if(set[i].id == id)
            return &set[i];
    }
}
Employee* find_employee_by_name( Employee *set, int n, const char *first_name, const char *last_name ){
    for(int i = 0; i < n; i++){
        if(!strcmp(set[i].first_name, first_name))
            return &set[i];
    }
}
Employee* find_root_boss( Employee *set, int n, Employee *employee ){
    for(int i = 0; i < n; i++){
        if(set[i].id == employee->boss_id)
            return &set[i];
    }
}
int check_relationship(Employee *set, int n, Employee *A, Employee *B){
    Employee *pa = A, *pb = B;
    while(pa->id != pa->boss_id){
        if(pa->boss_id == B->id){
            return 1;
        }
        pa = find_root_boss(set, n, pa);
    }
    while(pb->id != pb->boss_id){
        if(pb->boss_id == A->id){
            return 2;
        }
        pb = find_root_boss(set, n, pb);
    }
    if(pa->boss_id == pb->boss_id)
        return 3;
    return 4;
}