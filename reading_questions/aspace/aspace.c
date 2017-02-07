/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

void printLocal(int *local) {
	printf ("Address of local is %p\n", &local);
	printf ("Address of printLocal is %p\n", printLocal);
}

int main ()
{
    int local = 5;
    void *p = malloc(128);
    void *q = malloc(128);

    void *a = malloc(5);
    void *b = malloc(5);

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local is %p\n", &local);
    printf ("Address of p is %p\n", p);
    printf ("Address of q is %p\n", q);
    printf ("Address of a is %p\n", a);
    printf ("Address of b is %p\n", b);

    printLocal(&local);
    
    return 0;
}
