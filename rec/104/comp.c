#include<stdio.h>
int make(int a, int b, int c,
int da, int db, int dc, 
int ea, int eb, int ec, 
int fa, int fb, int fc){
    if(!a && !b && !c)
        return 1;
    if(a < 0 || b < 0 || c < 0)
        return 0;
    return make(a - da, b - db, c - dc, da, db, dc, ea, eb, ec, fa, fb, fc)
    + make(a - ea, b - eb, c - ec, da, db, dc, ea, eb, ec, fa, fb, fc)
    + make(a - fa, b - fb, c - fc, da, db, dc, ea, eb, ec, fa, fb, fc);
}
void process(int n, 
int da, int db, int dc, 
int ea, int eb, int ec, 
int fa, int fb, int fc){
    if(!n)
        return;
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int success = make(a, b, c, da, db, dc, ea, eb, ec, fa, fb, fc);
    (success) ? printf("yes\n") : printf("no\n");
    process(n - 1, da, db, dc, ea, eb, ec, fa, fb, fc);
}
int main(){
    int da, db, dc;
    int ea, eb, ec;
    int fa, fb, fc;
    scanf("%d%d%d%d%d%d%d%d%d", &da, &db, &dc, &ea, &eb, &ec, &fa, &fb, &fc);
    int n;
    scanf("%d", &n);
    process(n, da, db, dc, ea, eb, ec, fa, fb, fc);
}