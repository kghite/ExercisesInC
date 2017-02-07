# ThinkOS Ch2 Reading Questions

### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

Research and academic publishing seems like an example real-world virtualization in that each individual research lab contains a set of people with specialized knowledge and discoveries.  However, you can access missing skill sets or knowledge in an area via the publications of another research group.  What appears to be an independent group is operating in parallel with many others with virtual memory connections.

2) What is the difference between a program and a process?

A process is the software object encompassing a program to prevent multiple programs from interecting in unpredictable ways.  The text, data, and state of the program are all contained withing the process.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?

The process abstraction creates the illusion of separation between programs and the memory chunks used by processes, so that interactions with the hardware do not create errors between processes.

4) What is the kernel?

The kernal is a portion of the operating system that provides threading and other operating system capabilities.

5) What is a daemon?

A daemon is a type of process running in the kernal that provides the operating services in the background.