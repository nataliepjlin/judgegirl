#include<stdio.h>
typedef struct{
    int a, b;
}frac;
int gcd(int a, int b){
    if(a % b) return gcd(b, a % b);
    else return b;
}
frac mul(frac x, frac y){
    int a, b, g;
    a = x.a * y.a;
    b = x.b * y.b;
    g = gcd(a, b);
    a /= g;
    b /= g;

    frac z;
    z.a = a, z.b = b;
    return z;
}
frac add(frac x, frac y){
    int a, b, g;
    a = x.a * y.b + y.a * x.b;
    b = x.b * y.b;
    g = gcd(a, b);
    a /= g;
    b /= g;

    frac z;
    z.a = a, z.b = b;
    return z;
}
frac sub(frac x, frac y){
    int a, b, g;
    a = x.a * y.b - y.a * x.b;
    b = x.b * y.b;
    g = gcd(a, b);
    a /= g;
    b /= g;

    frac z;
    z.a = a, z.b = b;
    return z;
}

int main(){
    int n;
    scanf("%d", &n);

    frac initp[128][128];
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            int a, b;
            scanf("%d%d", &a, &b);
            b = a + b;
            int g = gcd(a, b);
            a /= g;
            b /= g;
            initp[i][j].a = a, initp[i][j].b = b;
            // printf("i=%d, j=%d, initp[i][j].a=%d, initp[i][j].b=%d\n", i, j, initp[i][j].a, initp[i][j].b);
        }
    }

    frac finalp[128][128];

    frac f0, f1;
    f0.a = 0, f0.b = 1;
    f1.a = 1, f1.b = 1;
    for(int i = 0; i < 128; i++){
        for(int j = 0; j < 128; j++){
            finalp[i][j] = f0;
        }
    }
    finalp[0][0] = f1;

    for(int r = 0; r < n; r++){
        for(int c = 0; c <= r; c++){
            printf("r=%d, c=%d, initp[r][c]=%d/%d\n", r, c, initp[r][c].a, initp[r][c].b);
            finalp[r + 1][c] = add(finalp[r + 1][c], mul(finalp[r][c], initp[r][c]));
            finalp[r + 1][c + 1] = add(finalp[r + 1][c + 1], mul(finalp[r][c], sub(f1, initp[r][c])));
        }
    }

    for(int i = 0; i <= n; i++){
        printf("%d/%d\n", finalp[n][i].a, finalp[n][i].b);
    }
    return 0;
}
