#include <stdio.h>


int main(int argc, char *argv[])
{
    int a, b, c;
    // declare a pointer variable and assign it to address of e.g. a
    int* p;
    p = &a;

    a = 11;

    printf("%d\n", a);
    printf("%d\n", *p);

    *p = 13;

    printf("%d\n", a);
    printf("%d\n", *p);

    printf("Address of a: %p \n", &a);
    printf("Address of a trough p: %p \n", p);
    printf("Address of p: %p \n", &p);

    /*int& s=a; ---> doesn't work, why?

    s -= 2;

    printf("s = %d\n", s);
    printf("a = %d\n", a); */
    
 
    // Evaluate expressions using both the original and the pointer variable
    // and investigate the value / value pointed to

    return 0;
}
