#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAXN 10000
// #define debug
int max(int a, int b){
    return (a > b) * a + (a <= b) * b;
}
int min(int a, int b){
    return (a < b) * a + (a >= b) * b;
}
int distSum(int s, int e, int distance[]){
    int len = 0;
    int start = min(s, e), end = max(s, e);
    #ifdef debug
    printf("%d to %d\n", start, end);
    #endif
    for(int i = start - 1; i < end - 1; i++){
        len += distance[i];
        #ifdef debug
        printf("distance[%d] = %d\n", i, distance[i]);
        printf("tmp len = %d\n", len);
        #endif
    }
    return len;
}
int stationDistance(int R_distance[],int G_distance[],int B_distance[],int G_origin,int G_destination,int startStation[],int endStation[]){
    int sum = 0;
    int x2 = endStation[0], x1 = startStation[0];
    int y2 = endStation[1], y1 = startStation[1];
    int lenG = 0; while(G_distance[lenG]) lenG ++;
    lenG ++;
    #ifdef debug
    printf("lenG = %d\n", lenG);
    printf("x2 = %d, x1 = %d\n", x2, x1);
    printf("y2 = %d, y1 = %d\n", y2, y1);
    #endif
    if(x1 == x2){
        if(x1 == 0)
            sum = distSum(y1, y2, R_distance);
        else if(x1 == 1)
            sum = distSum(y1, y2, G_distance);
        else
            sum = distSum(y1, y2, B_distance);
    }//same line
    else if(abs(x1 - x2) == 1 && x1 + x2 < 3){
        if(x1 == 0){
            sum += distSum(y1, G_origin, R_distance);
            #ifdef debug
            printf("\n");
            #endif
            sum += distSum(1, y2, G_distance);
        }//r -> g
        else{
            sum += distSum(1, y1, G_distance);
            #ifdef debug
            printf("\n");
            #endif
            sum += distSum(y2, G_origin, R_distance);
        }
    }//(r & g)
    else if(abs(x1 - x2) == 1 && x1 + x2 == 3){
        if(x1 == 2){
            sum += distSum(y1, G_destination, B_distance);
            #ifdef debug
            printf("\n");
            #endif
            sum += distSum(lenG, y2, G_distance);
        }//r -> g
        else{
            sum += distSum(lenG, y1, G_distance);
            #ifdef debug
            printf("\n");
            #endif
            sum += distSum(y2, G_destination, B_distance);
        }
    }//(g & b)
    else{
        if(x1 == 0){
            sum += distSum(y1, G_origin, R_distance);
            #ifdef debug
            printf("\n");
            #endif
            sum += distSum(1, lenG, G_distance);
            #ifdef debug
            printf("\n");
            #endif
            sum += distSum(y2, G_destination, B_distance);
        }//r -> b
        else{
            sum += distSum(y2, G_origin, R_distance);
            #ifdef debug
            printf("\n");
            #endif
            sum += distSum(1, lenG, G_distance);
            #ifdef debug
            printf("\n");
            #endif
            sum += distSum(y1, G_destination, B_distance);
        }
    }
    return sum;
}
int main(){
    int R_distance[MAXN]={0};
    //R_distance[0] is the distance between R1 and R2. 
    //All these arrays end with 0
    int G_distance[MAXN]={0};
    int B_distance[MAXN]={0};
    int G_origin,G_destination;
    //G_origin is the index of the station of R line at the intersection of R and G lines. 
    //For example, G_origin = 3 means R3 is G1
    //G_destination is the index of the station of B line at the intersection of G and B lines
    int startStation[2],endStation[2];
 
    int Rindex,Gindex,Bindex;
    Rindex =0; 
    while(scanf("%d",&R_distance[Rindex])){
        if( R_distance[Rindex]==0){
            break;
        }
        Rindex++;
    }
    Gindex=0;
    while(scanf("%d",&G_distance[Gindex])){
        if( G_distance[Gindex]==0){
            break;
        }
        Gindex++;
    }    
    Bindex=0;
    while(scanf("%d",&B_distance[Bindex])){
        if( B_distance[Bindex]==0)
            break;
        Bindex++;
    }
    scanf("%d%d",&G_origin,&G_destination);//The fourth line has two numbers a,b . 
    //a is the index of the station on R at the intersection of R and G lines. b is the index of the station on B at the intersection of B and G lines. 
    
    scanf("%d%d",&startStation[0],&startStation[1]);
    //X could be 0,1 or 2, and it represents R,G or B line. 
    //Y is the station index of the line. 
    scanf("%d%d",&endStation[0],&endStation[1]);
    int distanceSum =stationDistance(R_distance,G_distance,B_distance,G_origin,G_destination,startStation,endStation);
    printf("%d\n",distanceSum );
}