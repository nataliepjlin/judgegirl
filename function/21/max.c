int max(int array[5][5]){
    int max_val = -1;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if (array[i][j] > max_val) max_val = array[i][j];
        }
    }
    return max_val;
}