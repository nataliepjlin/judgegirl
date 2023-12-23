#include<stdio.h>
#include<math.h>
#define MAXN 250
// #define debug
int main(){
    //ax+by+c=0
    int n;
    scanf("%d", &n);
    double eq[MAXN][3] = {{0}};
    double points[MAXN][2] = {{0}};
    for(int i = 0; i < n; i++){
        scanf("%lf%lf%lf", &eq[i][0], &eq[i][1], &eq[i][2]);
    }
    for(int i = 0; i < n; i++){
        points[i][1] = ((-eq[(i + 1) % n][0] * eq[i][2]) + (eq[i][0] * eq[(i + 1) % n][2])) \
                    /((eq[(i + 1) % n][0] * eq[i][1]) - (eq[i][0] * eq[(i + 1) % n][1]));
        points[i][0] = ((-eq[(i + 1) % n][1] * eq[i][2]) + (eq[i][1] * eq[(i + 1) % n][2])) \
                    /((eq[i][0] * eq[(i + 1) % n][1]) - (eq[(i + 1) % n][0] * eq[i][1]));
        #ifdef debug
        printf("x%d = %.3lf, ", i, points[i][0]);
        printf("y%d = %.3lf\n", i, points[i][1]);
        #endif
    }
    double sum = 0.0;
    for(int i = 0; i < n; i++){
        sum += sqrt(pow(points[i][0] - points[(i + 1) % n][0], 2) \
            + pow(points[i][1] - points[(i + 1) % n][1], 2));
    }
    printf("%.3lf\n", sum);
    return 0;
}