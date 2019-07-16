 #include <stdio.h>
 #include <stdlib.h>

//      formal parameters
int add(int a, int b) //prototype of function or header or signature; declaration of function
{
    int c;
    c = a + b;
    return c;
}//definition of function

void swap(int x, int y){ // passagem por valor
    // x=10, y=20 
    int temp;
    temp = x; // x = 10, y = 20, temp = 10;
    x = y; // x = 20, y = 20, temp = 10;
    y = temp; // x= 20, y = 10, temp = 10;
}

void swap2(int *x, int *y){ // passagem por endereço
    // x=200, y=202
    // *x = valor de a; *y = valor de b
    int temp;
    temp = *x; // x/*x = 200/10, y/*y = 202/20, temp = 10;
    *x = *y; // *x = 20, *y = 20
    *y = temp; // x= 20, y = 10, temp = 10;
}

int * fun(int n) {
    int *p;
    p = (int *)malloc(n*sizeof(int));
    return p;
}

struct Rectangle {
    int length;
    int breadth;
};

struct Test {
    int A[5];
    int n;
};

int area(struct Rectangle r1){ //a DIFFERENT Rectangle "object" with the same values (passing by VALUE)
    return r1.length * r1.breadth;
}

void changeLenght(struct Rectangle *p, int l) {
    p->length = l;
}

void funct(struct Test t1){ 
    // it creates a "copy" of the content of the struct, and all changes made here will remain here (not affecting
    //the struct content in main(). The array inside the struct its passed by value (although an array must always be passed by reference);
    t1.A[0] = 10;
    t1.A[1] = 9;
}

int main()
{
    int x,y,z;
    x = 10;
    y = 5;

    z = add(x,y); // function call
    printf("Soma é %d\n", z);

    int a, b;
    a = 10;
    b = 20;
    swap(a, b);
    printf("1 - %d %d\n", a, b); 
    swap2(&a, &b);
    printf("2 - %d %d\n", a, b);

    int *A;
    A = fun(5);
    printf("Endereço %p\n", A);

    struct Rectangle r={10,5}; //Rectangle "object" with 10 and 5

    changeLenght(&r, 20);
    
    printf("%d\n", area(r));

    struct Test t = {{2,4,5,8,10}, 5};

    funct(t);
}