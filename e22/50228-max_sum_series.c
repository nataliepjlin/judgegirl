#include<stdio.h>
int main(){
    int max_sum = -1, max_count = 0, max_first = -1;
    int sum, count, first, diff;
    int n, input;
    int prev = -1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &input);
        // printf("input = %d\n", input);
        if(i == 0){
            max_sum = input;
            max_count = 1;
            max_first = input;
        }
        else if(i == 1){
            max_sum = sum = input + prev;
            max_count = count = 2;
            max_first = first = prev;
            diff = input - prev;
        }
        else{
            if(diff == input - prev){
                sum += input;
                count ++;
                // printf("first = %d, now sum = %d\n", first, sum);
            }
            else if(diff == -1){//setting a new series
                diff = input - prev;
                sum = input + prev;
                first = prev;
                count = 2;
            }
            else{
                if((sum > max_sum) || ((sum == max_sum) && (max_count < count)) || ((sum == max_sum) && (max_count == count) && (max_first < first))){
                    max_sum = sum;
                    max_count = count;
                    max_first = first;
                    sum = count = first = 0;
                }
                diff = -1;//restart a new series
            }
        }
        prev = input;
    }

    if((sum > max_sum) || ((sum == max_sum) && (max_count < count)) || ((sum == max_sum) && (max_count == count) && (max_first < first))){
        max_sum = sum;
        max_count = count;
        max_first = first;
    }

    printf("%d %d %d", max_sum, max_count, max_first);
    return 0;
}