#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b,c,d,e,f;
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f); 
        int A = (d-b)*(d-b)+(c-a)*(c-a);
        int B = (f-b)*(f-b)+(e-a)*(e-a);
        int C = (d-f)*(d-f)+(c-e)*(c-e);
        if(A==B||B==C||A==C){
            printf("isosceles");
        }
        else{
            int max = (A>B)? A:B;
            if(C>max){
                max = C;
            }
            int p = A + B + C - max;
            if(p > max){
                printf("acute");
            }
            else if(p == max){
                printf("right");
            }
            else{
                printf("obtuse");
            }
        }
        if(n > 0) printf("\n");
    }
}

