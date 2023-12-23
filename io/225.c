#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#define N 10001
#define LEN 32
typedef struct {
    unsigned int id;
    char name[32];
} PERSON;
typedef struct {
    unsigned id1;
    unsigned id2;
} FRIENDS;
void getID(PERSON p[], int pcnt, int *id1, int *id2, char *name1, char *name2){
    for(int i = 0; i < pcnt && (*id1 == -1 || *id2 == -1); i++){
        if(!strcmp(p[i].name, name1)) *id1 = p[i].id;
        if(!strcmp(p[i].name, name2)) *id2 = p[i].id;
    }
    return;
}
int isf(int id1, int id2, FRIENDS f[], int fcnt){
    for(int i = 0; i < fcnt; i++){
        if((f[i].id1 == id1 && f[i].id2 == id2)
        || (f[i].id1 == id2 && f[i].id2 == id1))
            return 1;
    }
    return 0;
}
int main(){
    FILE *fp = fopen("friends", "rb");
    PERSON p[N];
    FRIENDS f[N]; 
    int pcnt; fread(&pcnt, sizeof(int), 1, fp);
    #ifdef debug
    printf("pcnt = %d\n", pcnt);
    #endif
    for(int i = 0; i < pcnt; i++){
        fread(&p[i], sizeof(PERSON), 1, fp);
    }
    int fcnt; fread(&fcnt, sizeof(int), 1, fp);
    #ifdef debug
    printf("fcnt = %d\n", fcnt);
    #endif
    for(int i = 0; i < fcnt; i++){
        fread(&f[i], sizeof(FRIENDS), 1, fp);
    }
    char p1[LEN], p2[LEN];
    while(scanf("%s", p1) == 1 && strcmp(p1, "end") != 0){
        scanf("%s", p2);
        int id1 = -1, id2 = -1;
        getID(p, pcnt, &id1, &id2, p1, p2);
        // assert(id1 != -1 && id2 != -1);
        (isf(id1, id2, f, fcnt)) ? printf("yes\n") : printf("no\n");
    }
    fclose(fp);
}