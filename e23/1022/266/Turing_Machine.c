void Turing_Machine(int *head, int K){
    int list[][4][3] = {{{0, 1, 2},{1, 1, 1}, {2, 1, 2}, {3, 1, 1}},
                        {{1, -1, 2}, {2, 1, 0}, {3, -1, 2}, {0, 1, 0}},
                        {{2, 0, 1}, {3, -1, 0}, {0, 1, 1}, {1, 0, 0}}};
    //cur state, tape val, write tape, move, next state
    int s = 0;
    //head is pointing at a tape val
    for(int k = 0; k < K; k++){
        int nowVal = *head;
        *head = list[s][nowVal][0];
        head += list[s][nowVal][1];
        s = list[s][nowVal][2];
    }
}