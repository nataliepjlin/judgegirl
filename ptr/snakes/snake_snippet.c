if(*ptr_array[j] > *ptr_array[j + 1]){
    int *tmp = ptr_array[j];
    ptr_array[j] = ptr_array[j + 1];
    ptr_array[j + 1] = tmp;
}


for(int c = 0; c < m; c++){
        for(int i = 0; i < m; i++){
            for(int r = 0; r < m - i - 1; r++){
                if(*ptr_array[r][c] > *ptr_array[r + 1][c]){
                    int *tmp = ptr_array[r][c];
                    #ifdef DEBUG
                    printf("tmp = %p, ptr_arr[r][c] = %p\n", tmp, ptr_array[r][c]);
                    #endif
                    ptr_array[r][c] = ptr_array[r + 1][c];
                    ptr_array[r + 1][c] = tmp;
                }
            }
        }
    }
    #ifdef DEBUG
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            printf("%d%c", *ptr_array[i][j], " \n"[j == m-1]);
        }
    }
    #endif

    for(int r = 0; r < m; r++){
        if(r % 2 == 0){
            for(int i = 0; i < m; i++){
                for(int c = 0; c < m - i - 1; c++){
                    if(*ptr_array[r][c] > *ptr_array[r][c + 1]){
                        int *tmp = ptr_array[r][c];
                        #ifdef DEBUG
                        printf("tmp = %p, ptr_arr[r][c] = %p\n", tmp, ptr_array[r][c]);
                        #endif
                        ptr_array[r][c] = ptr_array[r][c + 1];
                        ptr_array[r][c + 1] = tmp;
                    }
                }
            }
        }
        else{
            for(int i = 0; i < m; i++){
                for(int c = 0; c < m - i - 1; c++){
                    if(*ptr_array[r][c] < *ptr_array[r][c + 1]){
                        int *tmp = ptr_array[r][c];
                        #ifdef DEBUG
                        printf("tmp = %p, ptr_arr[r][c] = %p\n", tmp, ptr_array[r][c]);
                        #endif
                        ptr_array[r][c] = ptr_array[r][c + 1];
                        ptr_array[r][c + 1] = tmp;
                    }
                }
            }
        }
    }