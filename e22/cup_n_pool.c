#include<stdio.h>
int main(){
    int k;
    int cups_cap[20000];
    int cups_vol[20000];
    int i, j, ope;
 
    scanf("%d", &k);
    for(int c=0; c<k; c++){
        scanf("%d", &cups_cap[c]);
    }
    for(int c=0; c<k; c++){
        scanf("%d", &cups_vol[c]);
    }
 
    while(scanf("%d%d", &i, &j)==2){
        if(i==k){//fill the j-th cup from the pool.
            cups_vol[j]=cups_cap[j];
        }
        else if(j==k){// pour all water from th i-th cup into the pool.
            cups_vol[i]=0;
        }
        else{
            if(cups_vol[i]+cups_vol[j]>cups_cap[j]){
                //fill j-th
                cups_vol[i]-=(cups_cap[j]-cups_vol[j]);
                cups_vol[j]=cups_cap[j];
            }
            else{
                //empty i-th
                cups_vol[j]+=cups_vol[i];
                cups_vol[i]=0;
            }
            ope=1;
        }
 
        // for(int c=0; c<k; c++){
        //     (c<k-1)?printf("%d ",cups_vol[c]):printf("%d\n",cups_vol[c]);
        // }
 
    }//end of ope
 
    for(int c=0; c<k; c++){
        (c<k-1)?printf("%d ",cups_vol[c]):printf("%d",cups_vol[c]);
    }
    return 0;
}