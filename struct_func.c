#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
    int length;
    int breadth;
};

int area(struct Rectangle r1){ //a DIFFERENT Rectangle "object" with the same values (passing by VALUE)
    return r1.length * r1.breadth;
}

void changeLenght(struct Rectangle *r, int l) {
    r->length = l;
}

void initialize(struct Rectangle *r, int l, int b) {
    r->length = l;
    r->breadth = b;
}

int main() {
    struct Rectangle r;

    initialize(&r, 10, 5); // call by address
    area(r); // call by value
    changeLenght(&r, 20); // call by address
    area(r);
}