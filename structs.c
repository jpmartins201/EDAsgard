#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
    int length;
    int breadth;
};

int main(){ 
    
    // struct Rectangle r = {10,5};
    struct Rectangle *p;

    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p->length = 10;
    p->breadth = 5;
    // (*p).length = 20; //método de acesso alternativo
    // p->length = 20; //método + comum
}