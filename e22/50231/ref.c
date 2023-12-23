#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

#define MAXLAYER 105
#define HASHTSIZE MAXLAYER * MAXLAYER
#define CAPACITY 10
typedef struct exposed{
    int value;
    int layer;
    int row;
    int col;
} exposed;
//https://www.educative.io/answers/how-to-use-the-typedef-struct-in-c
int f(int k, int tableSize){
    return (77 * k + 2222) % tableSize;
}
void getTower(int layer, int tower[MAXLAYER][MAXLAYER][MAXLAYER]){
    for(int i = 0; i < layer; i++){
        for(int r = 0; r <= i; r++){
            for(int c = 0; c <= i; c++){
                scanf("%d", &tower[i][r][c]);
            }
        }
    }
}//getTower
bool compareExposes(exposed n1, exposed n2){
    return (n1.layer == n2.layer
    && n1.row == n2.row && n1.col == n2.col);
}
exposed findSame(exposed key, exposed hashT[HASHTSIZE][CAPACITY], int capacity, int hashVal){
    for(int i = 0; i < capacity; i++){
        if(hashT[hashVal][i].value == key.value
        && !compareExposes(key, hashT[hashVal][i]))
            return hashT[hashVal][i];
    }
    return (exposed){-1, -1, -1, -1};
}
void insert(exposed n, exposed hashT[HASHTSIZE][CAPACITY], int capacity, int hashVal){
    for(int i = 0; i < capacity; i++){
        if(!hashT[hashVal][i].value){
            hashT[hashVal][i] = n;
            return;
        }
    }
    assert(true);
}
void removeFromHashT(exposed n, exposed hashT[HASHTSIZE][CAPACITY], int hashVal){
    for(int i = 0; i < CAPACITY; i++){
        if(hashT[hashVal][i].value == n.value){
            hashT[hashVal][i] = (exposed){0, 0, 0, 0};
            return;
        }
    }

}
void removeFromTower(exposed n1, exposed n2, int tower[MAXLAYER][MAXLAYER][MAXLAYER]){
    tower[n1.layer][n1.row][n1.col] = 0;
    tower[n2.layer][n2.row][n2.col] = 0;
}
bool checkexposed(exposed n, int tower[MAXLAYER][MAXLAYER][MAXLAYER]){
    return((n.layer == 0 || tower[n.layer - 1][n.row][n.col] == 0) && n.value != 0);
}// checks whether a given exposed structure represents an exposed number in a tower.
void findRemove(exposed n, exposed hashT[HASHTSIZE][CAPACITY], int tower[MAXLAYER][MAXLAYER][MAXLAYER], 
int hashTSize, int capacity, int layerCount){
    if(!checkexposed(n, tower)) return;
    int hashVal = f(n.value, hashTSize);
    exposed same = findSame(n, hashT, capacity, hashVal);
    if(same.value != -1){
        printf("%d ", same.value);
        removeFromHashT(same, hashT, hashVal);
        removeFromTower(same, n, tower);
        if(n.layer + 1 < layerCount){
            exposed n1 = {tower[n.layer + 1][n.row][n.col], n.layer + 1, n.row, n.col};
            findRemove(n1, hashT, tower, hashTSize, capacity, layerCount);
        }
        if(same.layer + 1 < layerCount){
            exposed n2 = {tower[same.layer + 1][same.row][same.col], same.layer + 1, same.row, same.col};
            findRemove(n2, hashT, tower, hashTSize, capacity, layerCount);
        }
    }//found same val
    else{
        insert(n, hashT, capacity, hashVal);
    }
}
int main(){
    int layerCount, hashTSize, capacity;
    scanf("%d%d%d", &layerCount, &hashTSize, &capacity);
    exposed hashT[HASHTSIZE][CAPACITY] = {{(exposed){0, 0, 0, 0}}};
    int tower[MAXLAYER][MAXLAYER][MAXLAYER] = {{{0}}};
    getTower(layerCount, tower);

    for(int i = 0; i < layerCount; i++){
        for(int r = 0; r <= i; r++){
            for(int c = 0; c <= i; c++){
                exposed n = {tower[i][r][c], i, r, c};
                // printf("i, r, c = %d, %d, %d\n", i, r, c);
                findRemove(n, hashT, tower, hashTSize, capacity, layerCount);
            }
        }
    }
    return 0;
}