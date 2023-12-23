#include<stdio.h>
int gcd(int a,int b){
    //printf("%d %d\n",a,b);
    int temp;
    while(b!=0){
        temp = a;
        a = b;
        b = temp%b;
    }
    //printf("%d\n",a);
    return a;
}
int main(){
    int n;
    scanf("%d",&n);
    int p[n+1][n+1][2];
    for(int i=0;i<n+1;i++)
        for(int j=0;j<n+1;j++){
            p[i][j][0] = 0;
            p[i][j][1] = 1;
        }
    p[0][0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int x,y;
            scanf("%d%d",&x,&y);
            int x0 = x,y0 = y;
            int div;
            div = gcd(x0,x0+y0);
            x /= div;
            div = gcd(y0,x0+y0);
            y /= div;
 
            int nume = p[i][j][0]*x;
            int denom = p[i][j][1]*(x+y);
            div = gcd(nume,denom);
            nume /= div;
            denom /= div;
            printf("f %d %d\n",nume,denom);
            p[i+1][j][0] = p[i+1][j][0]*denom+nume*p[i+1][j][1];
            p[i+1][j][1] = p[i+1][j][1]*denom;
            div = gcd(p[i+1][j][0],p[i+1][j][1]);
            p[i+1][j][0] /= div;
            p[i+1][j][1] /= div;//left child
 
            nume = p[i][j][0]*y;
            denom = p[i][j][1]*(x+y);
            div = gcd(nume,denom);
            nume /= div;
            denom /= div;//right child
            printf("f %d %d\n",nume,denom);
            p[i+1][j+1][0] = p[i+1][j+1][0]*denom+nume*p[i+1][j+1][1];
            p[i+1][j+1][1] = p[i+1][j+1][1]*denom;
 
            div = gcd(p[i+1][j+1][0],p[i+1][j+1][1]);
            p[i+1][j+1][0] /= div;
            p[i+1][j+1][1] /= div;
            printf("%d/%d %d/%d\n",p[i+1][j][0],p[i+1][j][1],p[i+1][j+1][0],p[i+1][j+1][1]);
        }
    }
    for(int i=0;i<=n;i++){
        printf("%d/%d\n",p[n][i][0],p[n][i][1]);
    }
    return 0;
}