## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

Converting an unsigned number to 16 bits would involve adding 0s to the front of the 8-bit representation.  If sign extension was accidentally applied, 1s would be added to the front instead of 0s, because in 2's compliment the initial 1 of the 8-bit representation of 128 would indicate a negative number.  This also indicates that there is no positive 128 value in a signed 8-bit representation, and only negative 128 can be stored.

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

12 -> 1100
-12 in 2's compliment -> 10100

```
    0000 1100
  ^ 1111 1111
  -----------
    1111 0011
  + 0000 0001
  -----------
    1111 0100


#include <stdio.h>
#include <stdint.h>

int main()
{
    int8_t negTwelve = (INT8_MAX ^ 12) + 1;
    printf("%i\n", negTwelve);
    
    return 0;
}
```

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

Storing the exponent as a biased integer allows two numbers to be compared to eachother as smaller numbers will be less than larger numbers lexicographically without any conversions.

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

```
s = 1
q = 10000010
c = 10100000000000000000000

-13 = 11000001010100000000000000000000
```

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.

Use XOR on the lower case ASCII bonery representation of the character and a bot mask with the sixth digit from the right set to 1.
