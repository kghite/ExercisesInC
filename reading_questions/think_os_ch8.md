# ThinkOS Ch8 Reading Questions

### Multitasking

1) What is the kernel's most basic task?

The kernal handles interrupts so that the system can effectively multitask.

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

The contents of the registers that are used by the interrupted process

3) What is the difference between an interrupt and a context switch?

A context switch resumes to a different process after the interrupt, which requires the entire hardware state to be saved.

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

A network communication or disk read

5) Why might a scheduler want to give higher priority to an I/O bound process?

This type of process might take longer and could also provide data necessary for other processes.