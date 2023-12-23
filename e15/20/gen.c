#include<gen.h>
void init(ARRAY *a,  int left, int right){
    a -> data-> set = 0;
    a -> l = left, a -> r = right;
}
int set(ARRAY *a, int index, int value);
int get(ARRAY *a, int index);
void print(ARRAY *a);
void sort(ARRAY *a);