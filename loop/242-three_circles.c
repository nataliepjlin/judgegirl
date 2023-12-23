//remember to add "-lm" when compiling
#include<stdio.h>
#include<math.h>
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int x1, y1, r1;
        int x2, y2, r2;
        int x3, y3, r3;
        scanf("%d%d%d", &x1, &y1, &r1);
        scanf("%d%d%d", &x2, &y2, &r2);
        scanf("%d%d%d", &x3, &y3, &r3);

        int count = 0;
        for(int x = x1 - r1; x <= x1 + r1; x++){
            for(int y = y1 - r1; y <= y1 + r1; y++){
                count += (pow(x - x1, 2) + pow(y - y1, 2) <= pow(r1, 2))
                        && !((pow(x - x2, 2) + pow(y - y2, 2) <= pow(r2, 2))
                        ^ (pow(x - x3, 2) + pow(y - y3, 2) <= pow(r3, 2)));
                // 1 && !(0^0) ->1
                // 1 && !(1^1) ->1
            }
        }
        for(int x = x2 - r2; x <= x2 + r2; x++){
            for(int y = y2 - r2; y <= y2 + r2; y++){
                count += (pow(x - x1, 2) + pow(y - y1, 2) > pow(r1, 2))
                        && (pow(x - x2, 2) + pow(y - y2, 2) <= pow(r2, 2))
                        && (pow(x - x3, 2) + pow(y - y3, 2) > pow(r3, 2));
            }
        }
        for(int x = x3 - r3; x <= x3 + r3; x++){
            for(int y = y3 - r3; y <= y3 + r3; y++){
                count += (pow(x - x1, 2) + pow(y - y1, 2) > pow(r1, 2))
                        && (pow(x - x2, 2) + pow(y - y2, 2) > pow(r2, 2))
                        && (pow(x - x3, 2) + pow(y - y3, 2) <= pow(r3, 2));
            }
        }

       printf("%d\n", count);
    }
    return 0;
}