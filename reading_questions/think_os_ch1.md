# ThinkOS Ch1 Reading Questions

### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Interpreted languages commonly support dynamic typing, but compiled languages rarely do.

2) Name two advantages of static typing over dynamic typing.

In compiled languages, static typing allows the compiler to store memory addresses at rather than variables names in the compiled program, saving memory.  Static typing also makes error checking more officient, because type mismatches are caught before runtime.

3) Give an example of a static semantic error.

A static semantic error would occur when you use an identifier or variable name that was never initialized and doesn't exist.

4) What are two reasons you might want to turn off code optimization?

Debugging can be difficult when there are a lot of optimizations going on in the background because bugs could be inconsistent.  Compilation with optimization also takes longer.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

The -S flag generates assembly code from the compiled code, which is different for different system architectures.  This means the assembly file will look the same on computers with the same architecture but different on others.

6) If you spell a variable name wrong, or if you spell a function name wrong, 
the error messages you get might look very different.  Why?

Spelling a function name wrong would produce an undefined reference error from the linker, while spelling a variable name wrong would result in an error during parsing.  These are from different parts of the compilation process and thus would look different.

7) What is a segmentation fault?

Segmentation faults are an error caused when a program attempts to read or write to a memory address that either does not exist or is not accessible. 