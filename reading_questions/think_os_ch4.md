# ThinkOS Ch4 Reading Questions

### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

A file system is an abstraction of the behavior of persistent storage.  This includes operating as if the files were stored in contiguous memory, while the actual storage is implemented as blocks of memory acting as small, individual hard drives.  The file system reads the data in a one large chunk of memory, jumping between blocks as it processes the data stream.

2) What information do you imagine is stored in an `OpenFileTableEntry`?



3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

6) What is overhead?  What is fragmentation?

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).