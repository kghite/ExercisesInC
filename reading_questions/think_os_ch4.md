# ThinkOS Ch4 Reading Questions

### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

A file system is an abstraction of the behavior of persistent storage.  This includes operating as if the files were stored in contiguous memory, while the actual storage is implemented as blocks of memory acting as small, individual hard drives.  The file system reads the data in a one large chunk of memory, jumping between blocks as it processes the data stream.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

An 'OpenFileTableEntry' stores the current read position of the file, which is a reference to the last character in the file that was read.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

When accessing a block of memory from persistent storage, a process will be interrupted by another process so that the system is not stuck until the data is stored in memory.  Writing a file also has to access persistent memory, so when a memory block is changed, the data is buffered until there is an entire block to write to the disk.

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

The data was written to the main memory, but buffered and not yet stored in the drive.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

The File Allocation Table can be expanded to any needed size.  Linked lists also generally have good performance when accessing the first element and moving through the list, which is similar to the pointer system for a single file in the FAT system.

6) What is overhead?  What is fragmentation?

Overhead is the space required to keep track of the blocks in the allocation system.  Unused or partially used blocks compose the fragmentation in a system.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

The stream of bytes abstraction can be used to develop simple communication systems such as networking channels.  However, one potential disadvantage of using this concept could occur if bytes are lost or skipped in the read and write stream or if the system is more complex with multiple data streams being written to a single receiver.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).