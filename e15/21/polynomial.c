#include "polynomial.h"
#include<stdio.h>
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
void init(Polynomial *poly, int coefficient[], int n){
    poly->size = n;
    for(int i = SIZE - 1; i >= 0; i--){
        poly->coes[i] = (i <= n - 1) ? (coefficient[i]) : 0;
    }
}
Polynomial add(Polynomial *poly1, Polynomial *poly2){
    int n = max(poly1->size, poly2->size);
    Polynomial pol;
    pol.size = n;
    for(int i = n - 1; i >= 0; i--){
        pol.coes[i] = poly1->coes[i] + poly2->coes[i];
    }
    return pol;
}
Polynomial multiply(Polynomial *poly1, Polynomial *poly2){
    Polynomial pol;
    pol.size = poly1->size + poly2->size;
    for(int i = pol.size - 1; i >= 0; i--){
        pol.coes[i] = 0;
    }
    for(int i = poly1->size - 1; i >= 0; i--){
        for(int j = poly2->size - 1; j >= 0; j--){
            pol.coes[i + j] += poly1->coes[i] * poly2->coes[j];
        }
    }
    return pol;
}
void print(Polynomial *poly){
    for(int i = (poly->size - 1); i >= 0; i--){
        if(poly->coes[i] != 0){
            printf("%+d", poly->coes[i]);
            (i > 0 && printf("x"));
            (i > 1 && printf("^%d", i));
        }
    }
    printf("\n");
}