#include <stdio.h>
#include <stdlib.h>

class Rectangle {
private:    
    int length;
    int breadth;
    
public:
    int area(){
        return length * breadth;
    }

    void changeLenght(struct Rectangle *r, int l) {
        length = l;
    }

    void initialize(int l, int b) {
        length = l;
        breadth = b;
    }

};


int main() {
    Rectangle r;

    r.initialize(0, 5); // call by address
    r.area(); // call by value
    r.changeLenght(20); // call by address
    r.area();
}