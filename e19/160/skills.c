#include<stdio.h>
// #define debug
int min(int a, int b){
    return (a < b) ? (a) : (b);
}
int main(){
    int rounds;//30
    scanf("%d", &rounds);
    int health, restoreH;//20, 1(g)
    scanf("%d%d", &health, &restoreH);
    int initH = health;
    int b[4], e[4], c[4], lastR[4] = {-1, -1, -1, -1};//base damage, extra damage, cooldown
    //we can use a special attack at round r only if r−r′ is at least its cool down c, 
    //where r′ is the last round we used that special attack.
    scanf("%d%d%d", &b[0], &e[0], &c[0]);
    scanf("%d%d%d", &b[1], &e[1], &c[1]);
    scanf("%d%d%d", &b[2], &e[2], &c[2]);
    scanf("%d", &b[3]); e[3] = 0, c[3] = 0;

    for(int r = 0; r < rounds; r++){
        #ifdef debug
        printf("%dth round\n", r);
        #endif
        int max = 0, maxidx = -1;
        for(int aidx = 0; aidx < 4; aidx++){
            if(lastR[aidx] == -1 &&
            (r <= c[aidx]) && 
            (b[aidx]> max)){
                #ifdef debug
                printf("1st type\n");
                #endif
                max = b[aidx];
                maxidx = aidx;
            }
            else if(lastR[aidx] == -1
            && r > c[aidx] 
            && b[aidx] + e[aidx] * (r - c[aidx]) > max){
                max = b[aidx] + e[aidx] * (r - c[aidx]);
                maxidx = aidx;
            }

            else if(b[aidx] + (e[aidx] * (r - lastR[aidx] - c[aidx])) > max
                && (r - lastR[aidx] >= c[aidx])
                && lastR[aidx] != -1){
                #ifdef debug
                printf("3rd type\n");
                #endif
                max = b[aidx] + e[aidx] * (r - lastR[aidx] - c[aidx]);
                maxidx = aidx;
            }
            #ifdef debug
            printf("now maxidx = %d, max = %d\n", maxidx, max);
            #endif
        }//finding attack type

        #ifdef debug
        printf("maxidx = %d, max = %d\n", maxidx, max);
        #endif
        //start attack
        health -= max;
        lastR[maxidx] = r;
        (r == 0) ? printf("%d", health): printf(" %d", health);
        if(health <= 0){
            printf("\n");
            break;
        } 
        health += restoreH;
        health = min(health, initH);
        #ifdef debug
        printf("after restore, health = %d\n", health);
        #endif
        //end attack
    }

    return 0;
}