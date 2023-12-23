#include <stdio.h>
#define MAXN 20000
// #define debug
double payment(int itemID[], double price[], int orderItemID[], int orderQuantity[], int onSaleItemID[]){
    double pay = 0.0;
    for(int i = 0; i <= MAXN + 1; i++){
        if(!orderItemID[i]) break;
        #ifdef debug
        printf("orderItemID[%d] = %d\n", i, orderItemID[i]);
        #endif
        for(int j = 0; j <= MAXN + 1; j++){
            if(itemID[j] == orderItemID[i]){
                int onSale = 0;
                for(int k = 0; k <= MAXN + 1; k++){
                    if(!onSaleItemID[k]) break;
                    if(onSaleItemID[k] == orderItemID[i]){
                        onSale = 1;
                        break;
                    }
                }
                pay += (onSale) ? (price[j] * orderQuantity[i] * 0.8)
                 : (price[j] * orderQuantity[i]);
                #ifdef debug
                printf("onSale = %d, now pay = %f\n", onSale, pay);
                #endif
            }
        }
    }
    if(pay < 490) pay += 80;
    return pay;
}
int main(int argc, char const *argv[]){
  int itemID[MAXN+1], orderItemID[MAXN+1], orderQuantity[MAXN+1], onSaleItemID[MAXN+1];
  double price[MAXN+1];
  int itemCnt, orderCnt, onSaleCnt;
  scanf("%d%d%d", &itemCnt, &orderCnt, &onSaleCnt);
 
  for(int i = 0; i < itemCnt; i++) {
    scanf("%d%lf", &itemID[i], &price[i]);
  }
  itemID[itemCnt] = 0, price[itemCnt] = 0;
 
  for(int i = 0; i < orderCnt; i++) {
    scanf("%d%d", &orderItemID[i], &orderQuantity[i]);
  }
  orderItemID[orderCnt] = 0, orderQuantity[orderCnt] = 0;
 
  for(int i = 0; i < onSaleCnt; i++) {
    scanf("%d", &onSaleItemID[i]);
  }
  onSaleItemID[onSaleCnt] = 0;
 
  double pay = payment(itemID, price, orderItemID, orderQuantity, onSaleItemID);
  printf("%.1lf\n", pay);
 
  return 0;
}