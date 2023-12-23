struct hanoi{
    int cnt[3];
    int arr[3][10];
};
void initialize(struct hanoi *hn, int n);
void moveHanoi(struct hanoi *hn, int src, int dst);
void printHanoi(struct hanoi *hn);