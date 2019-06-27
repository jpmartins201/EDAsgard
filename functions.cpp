#include <stdio.h>
#include <stdlib.h>

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

void swap3(int &x, int &y){ // passagem por referência
    // x e y são referências de a e b (respectivamente) -> 'alias' das variáveis da main
    int temp;
    temp = x; // x/*x = 200/10, y/*y = 202/20, temp = 10;
    x = y; // *x = 20, *y = 20
    y = temp; // x= 20, y = 10, temp = 10;
}

struct Rectangle {
    int length;
    int breadth;
};

int area(struct Rectangle &r1){ //pass by reference, creating an ALIAS for r (that from main)
    return r1.length * r1.breadth;
}



int main()
{
    int a, b;
    a = 10;
    b = 20;
    swap(a, b);
    printf("Por valor - %d %d\n", a, b); //passagem por valor não é útil para função swap
    swap2(&a, &b);
    printf("Por endereço - %d %d\n", a, b); 
    swap3(a, b);
    printf("Por referência - %d, %d\n", a, b);

    struct Rectangle r={10,5};

    printf("%d", area(r));
}