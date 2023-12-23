#include<stdio.h>
#define SIZE 1001
typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;
 
void traversal(Node *root, int N, int command[]){
    int layer = 0;
    Node *nodes[SIZE];
    nodes[0] = root;
    Node *l, *r, *p;
    for(int i = 0; i < N; i++){
        switch(command[i]){
            case 0:
                printf("%d\n", nodes[layer]->label);
                return;
            case 1:
                printf("%d\n", nodes[layer]->label);
                break;
            case 2:
                layer--;
                break;
            case 3:
                l = nodes[layer]->left;
                if(l == NULL){
                    printf("%d\n", nodes[layer]->label);
                    return;
                }
                else{
                    layer++;
                    nodes[layer] = l;
                }
                break;
            case 4:
                r = nodes[layer]->right;
                if(r == NULL){
                    printf("%d\n", nodes[layer]->label);
                    return;
                }
                else{
                    layer++;
                    nodes[layer] = r;
                }
                break;
            case 5:
                if(nodes[layer - 1]->left == nodes[layer]){
                    //left
                    if(nodes[layer - 1]->right == NULL){
                        printf("%d\n", nodes[layer]->label);
                        return;
                    }
                    else{
                        nodes[layer] = nodes[layer - 1]->right;
                    }
                }
                else if(nodes[layer - 1]->right == nodes[layer]){
                    //left
                    if(nodes[layer - 1]->left == NULL){
                        printf("%d\n", nodes[layer]->label);
                        return;
                    }
                    else{
                        nodes[layer] = nodes[layer - 1]->left;
                    }
                }
                else{
                    printf("%d\n", nodes[layer]->label);
                    return;
                }
                break;
            default:
                printf("%d\n", nodes[layer]->label);
                return;
        }//switch
    }//for
}