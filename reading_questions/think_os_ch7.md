# ThinkOS Ch7 Reading Questions

### Caching

1) What happens if a program writes a new value into the program counter?

The next instruction to be executed will be updated to the instruction at the new address in the program counter.

2) What is the fundamental problem caches are meant to solve?

A memory bottleneck is created during instruction cycles because the CPU can initiate instructions faster than data can be transferred to and from memory.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

The access time of a program can be found using 

`(hitRate * cacheAccess) + (missRate * memoryAccess)`

For a hit rate of 50%:

`0.5(1ns) + 0.5(10ns) = **5.5ns**`

For a hit rate of 90%:

`0.9(1ns) + 0.1(10ns) = **1.9ns**`

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

A data structure like a linked list that is connected by memory addresses rather than sequential placement would have decresed spatial locality.  A program that breaks large data sets into smaller pieces to work with would have better locality because the smaller parts would fit in the cache. 

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

By refactoring the program to improve locality, you potentially increase the hit rate, but it does not have directly read knowledge of the contents of the cache.  Because of this, the program would not be cache aware. 

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

The Intel i7-6700k 4.0GHz CPU with 6MB of cache can be purchased for $350.  Increasing the cache to 15MB costs an extra $100, meaning that the cache increase costs about $11 per MB.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

Policies can be complex at the bottom of the memory hierarchy because the memory access time is slower and there is more time to make decisions.  There is also a larger amount of memory to organize, and efficient storage can significantly improve access time and program performance.

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

If thrashing is detected from the increase in paging, the process currently accessing a page could be allowed to finish before swapping continues.

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer? 8MB cache