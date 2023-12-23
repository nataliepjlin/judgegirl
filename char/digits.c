#include<stdio.h>
int main(){
    char nums[10];
    int width, height, d[10], count = 0;
    while(scanf("%s%d%d", nums, &width, &height) != EOF){
        char *digit = nums;
        count = 0;
        while(*digit != '\0'){
            d[count] = *digit - 48;
            count ++;
            digit += 1;
        }
        for(int h = 0; h < height; h++){
            for(int i = 0; i < count; i++){
                if(h == 0 ){
                    printf(" ");
                    if(d[i] == 1 || d[i] == 4){
                        for(int w = 0; w < width - 3; w++){
                            printf(" ");
                        }
                    }
                    else{
                        for(int w = 0; w < width - 3; w++){
                            printf("%d", d[i]);
                        }
                    }
                    printf("  ");
                }//1st
                else if(h == height - 1){
                    printf(" ");
                    if(d[i] == 1 || d[i] == 4 || d[i] == 7 || d[i] == 9){
                        for(int w = 0; w < width - 3; w++){
                            printf(" ");
                        }
                    }
                    else{
                        for(int w = 0; w < width - 3; w++){
                            printf("%d", d[i]);
                        }
                    }
                    printf("  ");
                }
                else if(h == height / 2){
                    printf(" ");
                    if(d[i] == 0 || d[i] == 1 || d[i] == 7){
                        for(int w = 0; w < width - 3; w++){
                            printf(" ");
                        }
                    }
                    else{
                        for(int w = 0; w < width - 3; w++){
                            printf("%d", d[i]);
                        }
                    }
                    printf("  ");
                }//mid line
                else if(h < height / 2){
                    if(d[i] == 1 || d[i] == 2 || d[i] == 3) printf(" ");
                    else printf("%d", d[i]);

                    for(int w = 0; w < width - 3; w++){
                        printf(" ");
                    }

                    if(d[i] == 5 || d[i] == 6) printf(" ");
                    else printf("%d", d[i]);

                    printf(" ");
                }//upper
                else{
                    if(d[i] == 1 || d[i] == 3 || d[i] == 4 || d[i] == 5 || d[i] == 7 || d[i] == 9) printf(" ");
                    else printf("%d", d[i]);

                    for(int w = 0; w < width - 3; w++){
                        printf(" ");
                    }

                    if(d[i] == 2) printf(" ");
                    else printf("%d", d[i]);

                    printf(" ");
                }
            }
            printf("\n");
        }
    }//scanf input
    return 0;
}