## Chapter 6


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

mallod: Takes constant time because it simply creates pointer to some memory space.

calloc: Takes time proportional to the size of the allocated memory because it has to access all of the memory to set every byte to 0.

free: Takes contant time because it is deallocating a pointer and does not need to access all of the memory.

realloc: Takes proportional time because it has to copy over all of the old data to the newly allocated space.

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

This could trigger a segmentation fault at runtime if detected, but might just read a previously stored value.

b) Writing to unallocated memory.

This action will not be detected until a read attempt at the memory location.  The size may not have been available and other values could have been overwritten.  These other value could potentially include the data structures required for malloc or free.

c) Reading from a freed chunk.

The memory is released to be allocated but the initial values could still be present.  It is not certain at any given read whether the values were overwritten by a new allocation.

d) Writing to a freed chunk.

You could end up with multiple pointers to the same memory.

e) Failing to free a chunk that is no longer needed.

This could cause a memory leak which can slow processes or cause the system to physically run out of memory.

3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

Firefox and Sublime Text are currently taking the most memory on my system, which makes sense given the complexity of the applications and the number of processes that they are running.

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

If a large number of small memory chunks are allocated, there could be enough physical memory space for a process, but it might be segmented so as to be unavailable for malloc.  If the heap becomes too fragmented, you could defragment it by referencing the boundary tags to reallocate the memory chunks to contiguous space.  This would free up a larger, continous space for future allocation.

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
