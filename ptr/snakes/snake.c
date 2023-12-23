#include <stdio.h>
#include <assert.h>
#include<stdlib.h>
// #define DEBUG
void snake(const int *ptr_array[100][100], int m) {
    int *tmp[10000];
    // for (int i = 0; i < 10000; i++) {
    //     tmp[i] = (int *)malloc(sizeof(int));
    // }
    for (int i = 0; i < m * m; i++) {
        tmp[i] = ptr_array[i / m][i % m];
    }

    for(int i = 0; i < m * m; i ++){
        for(int j = 0; j < m * m - i - 1; j++){
            if(*tmp[j] > *tmp[j + 1]){
                int *p = tmp[j];
                tmp[j] = tmp[j + 1];
                tmp[j + 1] = p;
            }
        }
    }
    #ifdef DEBUG
    for(int i = 0; i < m * m; i++){
        printf("%d%c", *tmp[i], " \n"[i == m * m -1]);
    }
    #endif
    for(int r = 0; r < m; r ++){
        for(int c = 0; c < m; c++){
            if(r % 2) ptr_array[r][(m - 1) - c] = tmp[r * m + c];
            else ptr_array[r][c] = tmp[r * m + c];
        }
    }
}

int main()
{
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int i, j, m;
 
  scanf("%d", &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }
 
  snake(ptr_array, m);
 
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      assert(check[i][j] == array[i][j]);
      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }
 
  return 0;
}