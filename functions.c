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
    printf("%p", A);
}