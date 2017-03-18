# ThinkOS Ch9 Reading Questions

### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

Each thread has its own sequence of function calls and data that have to be stored separately.  This allows motion between threads, because the state of the stack for one thread will be saved.  You can also merge stacks to join threads.

2) What does the `gcc flag -lpthread` do?

This flag links in the pthread library to the compiler.

3) What does the argument of `pthread_exit` do?

The value of the argument gets passed to the thread that is joining with the exiting thread.

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

Any thread can join any other thread.

5) What goes wrong if several threads try to increment a shared integer at the same time?

The counter will increment more than wanted or a segmentation fault will be thrown if they are trying to access it at exactly the same time.

6) What does it mean to "lock a mutex"?

Locking a mutex bars all threads other than the current one from accessing a counter or shared variable.