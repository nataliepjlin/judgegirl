void intersection(int map[100][100], int result[4]){
    for(int i = 0; i < 4; i++){
        result[i] = 0;
    }
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(map[i][j] == 0) continue;
 
            int left = 0, right = 0, up = 0, down = 0;
            if(i > 0 && map[i - 1][j]) up = 1;
            if(i < 100 - 1 && map[i + 1][j]) down = 1;
            if(j > 0 && map[i][j - 1]) left = 1;
            if(j < 100 - 1 && map[i][j + 1]) right = 1;
 
            if(left && right && up && down) result[0] ++;
            else if(left + right + up + down == 3) result[1] ++;
            else if((left && up) || (left && down) || (right && up) || (right && down)) result[2] ++;
            else if(left + right + up + down == 1) result[3] ++;
        }
    }
}
