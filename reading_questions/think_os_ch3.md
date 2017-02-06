# ThinkOS Ch3 Reading Questions

### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

3) What is the difference between "memory" and "storage" as defined in Think OS?

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

5) How does the virtual memory system help isolate processes from each other?

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

7) What Python data structure would you use to represent a sparse array?

8) What is a context switch?

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.
  
1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).  

2) Add a function that prints the address of a local variable, and check whether the stack grows down.  

3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.