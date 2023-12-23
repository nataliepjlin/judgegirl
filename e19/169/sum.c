#include <stdio.h>
#include <stdlib.h>
// #define debug
void sumOfIntegers(const int *ptrArray[], int answer[], int *numberOfBlocks){
    *numberOfBlocks = 0;
    int i = 0, sum = 0;
    while(1){
        if(ptrArray[i] == NULL){
            answer[*numberOfBlocks] = sum;
            sum = 0;
            *numberOfBlocks += 1;
            #ifdef debug
            printf("i = %d, numberOfBlocks++\n", i);
            #endif
            if(ptrArray[i + 1] == NULL){
                #ifdef debug
                printf("i = %d, i + 1 = %d, end sum, numberOfBlocks = %d\n", i, i + 1, *numberOfBlocks);
                #endif
                break;
            }
        }
        else{
            int same = 0;
            for(int j = i - 1; j >= 0; j--){
                if(ptrArray[j] == NULL) break;
                else if(ptrArray[i] == ptrArray[j]){
                    same = 1;
                    break;
                }
            }
            if(!same){
                sum += *ptrArray[i];
                #ifdef debug
                printf("i = %d, now sum = %d\n", i, sum);
                #endif
            } 
        }
        i ++;
    }
}
 
int main(int argc, char const *argv[])
{
    int a, b, c, d, number = 0;
    int *numberOfBlocks = &number;
    const int *ptrArray[16];
    int answer[16] = {0};
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ptrArray[0] = &b;
    ptrArray[1] = &a;
    ptrArray[2] = &a;
    ptrArray[3] = NULL;
    ptrArray[4] = &d;
    ptrArray[5] = &a;
    ptrArray[6] = &b;
    ptrArray[7] = &b;
    ptrArray[8] = NULL;
    ptrArray[9] = &c;
    ptrArray[10] = NULL;
    ptrArray[11] = NULL;
    sumOfIntegers(ptrArray, answer, numberOfBlocks);
    for(int index = 0; index < *numberOfBlocks; index++) {
        printf("%d ", answer[index]);
    }
    return 0;
}