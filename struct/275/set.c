#include<stdio.h>
typedef unsigned long long Set;
void init(Set *set){
    *set = (Set)0;
}
void add(Set *set, int i){
    *set = *set | ((Set)1 << (63 - i));
}
void has(Set set, int i){
    //0 to 63, use a bit to present a number in the set
    (set & ((Set)1 << (63 - i))) ?
        printf("set has %d\n", i):
        printf("set does not have %d\n", i);
}
Set setUnion(Set a, Set b){
    return a | b;
}
Set setIntersect(Set a, Set b){
    return a & b;
}
Set setDifference(Set a, Set b){
    return a ^ b;
}