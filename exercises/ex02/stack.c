/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

// Question 1.  The file is supposed to create and array with 5 elements, then 
// place 42 at each index.  The ouput will be the printed array.
//
// Question 2. Output is warning: function returns address of local variable.  This 
// means that a function returns the address of a variable that is local to the 
// fucntion.
//
// Question 3. I get the following line: 9146 segmentation fault (core dumped)  ./stack.
//
// Question 4.  The code prints the addresses of the arrays before throwing the 
// segmentation fault when the lines are uncommented, and just throws the fault otherwise.
// The two pointers are going to the same memory address, causing the main loop
// to print values that are not allocated to the arrays after foo and bar have both run.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
	printf("%d\n", array[i]);
    }

    return 0;
}
