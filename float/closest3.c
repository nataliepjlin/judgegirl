#include<stdio.h>
// #define DEBUG
int main(){
    int n;
    scanf("%d", &n);
    double x, y, z;

    scanf("%lf%lf%lf", &x, &y, &z);
    int idx1 = 0, idx3 = 0;
    double m1 = x * x + y * y + z * z;
    double m3 = x * x + y * y + z * z;
    double sum = 0.0;
    
    for(int i = 1; i < 3; i++){
        scanf("%lf%lf%lf", &x, &y, &z);
        double dist = x * x + y * y + z * z;
        sum += dist;
        if(dist > m3){
            idx3 = i;
            m3 = dist;
        }
        if(dist < m1){
            idx1 = i;
            m1 = dist;
        }
    }
    double m2 = sum - m1 - m3;
    int idx2 = 3 - idx1 - idx3;
    #ifdef DEBUG
    printf("idx1 = %d, m1 = %f\n", idx1, m1);
    printf("idx2 = %d, m2 = %f\n", idx2, m2);
    printf("idx3 = %d, m3 = %f\n", idx3, m3);
    #endif
    for(int i = 3; i < n; i++){
        scanf("%lf%lf%lf", &x, &y, &z);
        double dist = x * x + y * y + z * z;
        if(dist < m1){
            m3 = m2;
            idx3 = idx2;
            m2 = m1;
            idx2 = idx1;
            m1 = dist;
            idx1 = i;
        }
        else if(dist < m2){
            m3 = m2;
            idx3 = idx2;
            m2 = dist;
            idx2 = i;
        }
        else if(dist < m3){
            m3 = dist;
            idx3 = i;
        }
        #ifdef DEBUG
        printf("\ni = %d\n", i);
        printf("idx1 = %d, m1 = %f\n", idx1, m1);
        printf("idx2 = %d, m2 = %f\n", idx2, m2);
        printf("idx3 = %d, m3 = %f\n", idx3, m3);
        #endif
    }
    printf("%d\n", idx3 + 1);
    return 0;
}