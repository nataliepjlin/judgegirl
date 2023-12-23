#include<stdio.h>
#define DEBUG
int main(){
    int arr[105],len=0;
    while(scanf("%d", &arr[len++])!=EOF){
    }
    len--;
    #ifdef DEBUG
    printf("len = %d\n", len);
    #endif
    int b[105];
    b[len-1] = len-1;
    #ifdef DEBUG
    printf("b[%d] = %d\n", len - 1, b[len-1]);
    #endif
    int l=len-1, r=len-1;
 
    for(int i=len-2;i>=0;i--){//start from 2nd last
        for(int j=i;j<len;j++){//end
            int flag=1;
            for(int k=0;i+k<=j-k;k++){
                #ifdef DEBUG
                printf("i = %d, j = %d, k = %d\n", i, j, k);
                #endif
                if(arr[i+k]!=arr[j-k]){
                    flag=0;
                    break;
                }
            }//k, finding palindrome
            if(flag==1){
                b[i] = j;
                #ifdef DEBUG
                printf("b[%d] = %d\n", i, j);//i: start idx, j: end idx
                #endif
                if(j!=len-1){
                    if(b[j+1]-i>r-l){
                        l = i;
                        r = b[j+1];
                    }
                }// extending palindrome to double
                else if(j-i>r-l){//j can't be extend (can also be written as "else if ((len - 1) - i > r - l)")
                    l = i;
                    r = j;
                }
            }
        }
        #ifdef DEBUG
        printf("l = %d, r = %d\n",l,r);
        #endif
    }
    
    printf("%d", arr[l]);
    for(int i=l+1;i<=r;i++){
        printf(" %d", arr[i]);
    }
    printf("\n");
}