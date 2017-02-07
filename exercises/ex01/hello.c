#include <stdio.h>

// Optimization replaces variable names with the value of the variable, 
// even in complex cases of assignment and math operations.  THis makes 
// the assembly code more efficient but could cause difficulties when 
// debugging, because all of the operations are done by the compiler and 
// the results could be inconsistent.

int main()
{
	int x = 5;
	int y = x + 1;
	printf("%i\n", y);
}