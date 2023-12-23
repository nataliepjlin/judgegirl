#include<stdio.h>
#define SIZE 128
#define debug
int main(){
    int arr[SIZE], n = 0;
    while(scanf("%d", &arr[n]) == 1)
        n++;
    int pal[SIZE];
    pal[n - 1] = n - 1;
    int head = -1, tail = -1;
    for(int start = n - 2; start >= 0; start--){
        for(int end = start; end < n; end++){
            int valid = 1;
            for(int i = 0; start + i <= end - i && valid; i++){
                valid = (arr[start + i] == arr[end - i]);
            }
            if(valid){
                // printf("(%d, %d)\n" , start, end);
                pal[start] = end;
                if(end < n - 1 && pal[end + 1] - start > tail - head){
                    tail = pal[end + 1];
                    head = start;
                }
                else if(end - start > tail - head){
                    tail = end;
                    head = start;
                }
            }
        }
    }
    for(int i = head; i <= tail; i++){
        printf("%d%c", arr[i], " \n"[i == tail]);
    }
}