#include <stdio.h>
struct Rectangle{
    int length;
    int breadth;
};

struct Card
{
    int face;
    int shape;
    int color;
};

int main() {
    int A[5];
    int B[5] = {2, 9, 6, 8, 10};
    int i;
    int a = 10; // data variable
    int *p; //adress variable
    p = &a; 
    printf("%d\n", a);
    printf("%s\n", p);
    printf("%d\n", *p);


    // struct Card c = {1, 0, 0};
    // c.face = 1;
    // c.shape = 0;
    // c.color = 0;

    // struct Rectangle r;
    // struct Rectangle r = {10, 5};
    // r.length = 15;
    // r.breadth = 10;

    // printf("Area do retangulo é %d \n", r.length * r.breadth);


    // struct Card deck[52] = {{1,0,0}, {2, 0, 0}};

    // printf("%d\n", deck[0].face);
    // printf("%d\n", deck[0].shape);
}