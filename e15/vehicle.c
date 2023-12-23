#include<stdio.h>
#include<stdlib.h>
// #define DEBUG
int main(){
    int a, b, c, d, e;
    int p, q, r, s;
    int x, y, F;
    int gold = 0, outx = -1, outy = -1;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    scanf("%d%d%d%d", &p, &q, &r, &s);//transporters
    scanf("%d%d%d", &x, &y, &F);
    int dir, trans = 0;// 0 1 2 3
    while(F){
        #ifdef DEBUG
        printf("fuel = %d, x = %d, y = %d\n", F, x, y);
        #endif
        if(!((x == r && y == s) || (x == p && y == q))){
            gold += abs(c * x + d * y) % e;
            #ifdef DEBUG
            printf("now gold = %d\n", gold);
            #endif

            dir = abs(a * x + b * y) % 4;
            #ifdef DEBUG
            printf("now dir = %d\n", dir);
            #endif
            if(dir == 0) y ++;
            else if(dir == 1) x ++;
            else if(dir == 2) y --;
            else x --;
            F --;
        }//not transport
        else if(((x == r && y == s) || (x == p && y == q)) && trans){
            dir = abs(a * x + b * y) % 4;
            #ifdef DEBUG
            printf("now dir = %d\n", dir);
            #endif
            if(dir == 0) y ++;
            else if(dir == 1) x ++;
            else if(dir == 2) y --;
            else x --;
            F --;
            trans = 0;
        }
        else if(x == r && y == s && !trans){
            x = p, y = q;
            trans = 1;
        }
        else if(x == p && y == q && !trans){
            x = r, y = s;
            trans = 1;
        }
        if(!F){
            outx = x, outy = y;
            if(outx == r && outy == s){
                outx = p, outy = q;
            }
            else if(outx == p && outy == q){
                outx = r, outy = s;
            }
            #ifdef DEBUG
            printf("(outx, outy) = (%d, %d)\n", outx, outy);
            #endif
            break;
        } 
        #ifdef DEBUG
        printf("\n");
        #endif
    }//while
    if(!((outx == r && outy == s) || (outx == p && outy == q))){
        gold += abs(c * outx + d * outy) % e;
        #ifdef DEBUG
        printf("now gold = %d\n", gold);
        #endif
    }

    printf("%d\n", gold);
    printf("%d %d\n", outx, outy);
    return 0;
}