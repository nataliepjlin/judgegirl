#include<stdio.h>
#include<string.h>
#define MAXN 101
#define MAXI 11
#define MAXCHAR 65
// #define debug
int main(){
    int n;
    char names[MAXN][MAXCHAR];
    char ingredients[MAXN][MAXI][MAXCHAR];
    int I[MAXN];
    scanf("%d", &n);
    for(int ni = 0; ni < n; ni++){
        scanf("%s%d", names[ni], &I[ni]);
        #ifdef debug
        printf("\nnames[%d] = %s, I[%d] = %d\n", ni, names[ni], ni, I[ni]);
        #endif
        for(int i = 0; i < I[ni]; i++){
            scanf("%s", ingredients[ni][i]);
            #ifdef debug
            printf("ingredients[%d][%d] = %s\n", ni, i, ingredients[ni][i]);
            #endif
        }
    }
    int m;
    scanf("%d", &m);
    char out[MAXI][MAXCHAR];
    for(int round = 0; round < m; round++){
        int outidx = 0;
        memset(out, '\0', sizeof(out));
        #ifdef debug
        printf("\n%dth round\n", round);
        #endif
        char name1[MAXCHAR], name2[MAXCHAR];
        int i1 = -1, i2 = -1;
        scanf("%s%s", name1, name2);
        for(int ni = 0; ni < n && (i1 == -1 || i2 == -1); ni++){
            if(strcmp(name1, names[ni]) == 0) i1 = ni;
            if(strcmp(name2, names[ni]) == 0) i2 = ni;
        }
        #ifdef debug
        printf("name1 = %s, name2 = %s\n", name1, name2);
        printf("names[%d] = %s, names[%d] = %s\n", i1, names[i1], i2, names[i2]);
        #endif
        for(int j = 0; j < I[i1]; j++){
            for(int k = 0; k < I[i2]; k++){
                if(strcmp(ingredients[i1][j], ingredients[i2][k]) == 0){
                    // int noSame = 1;
                    // for(int o = 0; o < outidx && noSame; o++){
                    //     noSame = (strcmp(ingredients[i1][j], out[o]));
                    // }
                    // if(noSame){
                        strcpy(out[outidx], ingredients[i1][j]); 
                        outidx ++;
                    // }
                }
            }
        }

        if(!outidx) printf("nothing\n");
        else{
            for(int i = 0; i < outidx; i++){
                for(int j = 0; j < outidx - i - 1; j++){
                    if(strcmp(out[j], out[j + 1]) > 0){
                        char tmp[MAXCHAR]; memset(tmp, '\0', sizeof(tmp));
                        strcpy(tmp, out[j]);
                        strcpy(out[j], out[j + 1]);
                        strcpy(out[j + 1], tmp);
                    }
                }
            }
            for(int i = 0; i < outidx; i++){
                printf("%s%c", out[i], " \n"[i == outidx - 1]);
            }
        }
        
    }

    return 0;
}