#include<stdio.h>
// #define DEBUG
void shuffle(int *deck[]){
    int idx = 0; int first;
    while(deck[idx] != NULL) idx ++;

    int *tmp[10000];
    if(idx){
        first = (idx % 2)? ((idx / 2) + 1 ): (idx / 2);
        #ifdef DEBUG
        printf("idx = %d, first = %d\n", idx, first);
        #endif
        int count = 0;
        for(int i = 0; i < idx; i++){
            if(i % 2){
                tmp[i] = deck[first];
                #ifdef DEBUG
                printf("tmp[%d] = deck[%d]\n", i, first);
                #endif
                first ++;
            }
            else{
                tmp[i] = deck[count];
                #ifdef DEBUG
                printf("tmp[%d] = deck[%d]\n", i, count);
                #endif
                count ++;
            }
        }//re-sorting elements
        for(int i = 0; i < idx; i++){
            deck[i] = tmp[i];
        }
    }
}
void print(int *deck[]){
    int idx = 0;
    while(deck[idx] != NULL){
        (idx == 0) ? printf("%d", *deck[idx]) : printf(" %d", *deck[idx]);
        idx ++;
    }
    if(idx) printf("\n");
}
// int main()
// {
//   int card[10000];
//   int *deck[10000];
//   int index = 0;
  
 
//   while (scanf("%d", &(card[index])) != EOF) {
//     deck[index] = &(card[index]);
//     index++;
//   }
//   deck[index] = NULL;
//   shuffle(deck);
//   print(deck);  
//   return 0;
// }