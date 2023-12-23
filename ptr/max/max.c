// #include <stdio.h>
// #define DEBUG
int max(int *iptr[], int n){
    int max_val = -1;
    for(int i = 0; i < n; i++){
        if(*iptr[i] > max_val){
            max_val = *iptr[i];
            #ifdef DEBUG
            printf("maxval change to %d\n",max_val);
            #endif
        }
    }
    return max_val;
}
// int main() {
//     int n, i;
//     int array[100];
//     int *iptr[100];
//     scanf("%d", &n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &(array[(i + 3) % n]));
//         #ifdef DEBUG
//         printf("arr[%d] = %d\n", (i + 3) % n, array[(i + 3) % n]);
//         #endif
//         iptr[i] = &(array[(i + 3) % n]);
//     }
//     printf("%d\n", max(iptr, n));
//     return 0;
// }