#include<stdio.h>
#include<string.h>
#define MAX 10001
void type12(char word[], int len, int i, int syllables[][2]){
    for(int k = 0; k < len; k++){
        if(syllables[i][0] <= k && k <= syllables[i][1]) printf("%c", word[k]);
        else printf("+");
    }
    printf("\n");
}
int main(){
    char word[MAX];
    char vowels[] = "aeiouAEIOU";
    while(scanf("%s", word) == 1){
        int syllables[MAX][2] = {{0}}, h = 0;
        int len = strlen(word);
        for(int i = 0; i < len; i++){
            if(strchr(vowels, word[i]) != NULL){
                syllables[h][1] = i;
                syllables[h + 1][0] = i + 1;
                h++;
            }
        }
        int i, j;
        scanf("%d%d", &i, &j);
        type12(word, len, i, syllables);
        type12(word, len, j, syllables);
        for(int k = 0; k < len; k++){
            if(!(syllables[i][0] <= k && k <= syllables[i][1] ||
                syllables[j][0] <= k && k <= syllables[j][1])) printf("%c", word[k]);
            else printf("+");
        }
        printf("\n");
    }
}