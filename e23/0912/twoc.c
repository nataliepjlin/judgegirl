#include<stdio.h>
int main(){
    int xa, ya, xb, yb, ra, rb;
    scanf("%d%d%d%d%d%d", &xa, &ya, &ra, &xb, &yb, &rb);

    int xi, yi;
    while(scanf("%d%d", &xi, &yi) == 2){
        int dist_a = (xi - xa) * (xi - xa) + (yi - ya) * (yi - ya);
        int dist_b = (xi - xb) * (xi - xb) + (yi - yb) * (yi - yb);
        if(dist_a == ra * ra || dist_b == rb * rb){
            printf("On\n");
        }
        else if(dist_a < ra * ra || dist_b < rb * rb){
            printf("In\n");
        }
        else{
            printf("Out\n");
        }
    }
    return 0;
}