#include<stdio.h>
// #define debug
void sumOfIntegers(const int *ptrArray[], int answer[], int *numberOfBlocks){
    *numberOfBlocks = 0;
    int i = 0;
    answer[*numberOfBlocks] = 0;
    while(1){
        if(ptrArray[i] != NULL){
            int found = 0;
            for(int j = i - 1; j >= 0 && ptrArray[j] != NULL && !found; j--){
                found = (ptrArray[i] == ptrArray[j]);
            }
            if(!found)
                answer[*numberOfBlocks] += *ptrArray[i];
        }
        else{
            *numberOfBlocks += 1;
            if(ptrArray[i + 1] == NULL)
                break;
            else{
                answer[*numberOfBlocks] = 0;
            }
        }
        i++;
    }
}