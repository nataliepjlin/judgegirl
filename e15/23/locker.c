#include "locker.h"
#include<stdio.h>
void init(Lock *lock){
    lock->isLocked = 0;
}
int lock(Lock *lock, int combination){
    if(lock->isLocked)
        return -1;
    if(combination < 0 || combination > 9999)
        return 10000;
    lock->pwd = combination; 
    lock->isLocked = 1;
    return combination;
}
int unlock(Lock *lock, int combination){
    if(!lock->isLocked)
        return -1;
    if(lock->pwd == combination){
        lock->isLocked = 0;
        return 0;
    }
    return 1;
}
int isLocked(Lock *lock){
    return lock->isLocked;
}