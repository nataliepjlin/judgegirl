#include<stdio.h>
int main(){
    int h, w, k;
    int arr[200][200];
    scanf("%d%d%d", &h, &w, &k);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j ++){
            scanf("%d", &arr[i][j]);
        }
    }

    int ridx = 2 * k - 1;
    int count = 0;
    int maxsum = 0;
    while(ridx <= h){
        // printf("\n###ridx = %d###\n", ridx);
        int r = (k - 1) + count, c = 0;
        int cidx = 2 * k - 1;
        while(cidx <= w){
            int sum = 0;
            // printf("cidx = %d\n", cidx);
            // printf("init r = %d, c = %d\n", r, c);
            int ci = c;

            for(c = c; c < k + ci; c ++){
                sum += arr[r][c];
                // printf("r = %d, c = %d\n", r, c);
                r --;
            }

            // printf("\n");
            ci = c; r += 2;
            for(c = ci; c < k + ci - 1; c ++){
                sum += arr[r][c];
                // printf("r = %d, c = %d\n", r, c);
                r ++;
            }

            // printf("\n");
            ci = c - 2;
            for(c = ci; c > ci - (k - 1); c --){
                sum += arr[r][c];
                // printf("r = %d, c = %d\n", r, c);
                r ++;
            }

            // printf("\n");
            ci = c; r -= 2;
            for(c = ci; c > ci - (k - 1) + 1; c --){
                sum += arr[r][c];
                // printf("r = %d, c = %d\n", r, c);
                r --;
            }
            cidx ++;
            c ++;
            if(maxsum < sum) maxsum = sum;
        }//cidx
        ridx ++;
        count ++;
    }
    
    printf("%d\n", maxsum);
    return 0;
}