# Reflection 1

## Sprint Reflection
### Personal Learning Goals

* Gain proficiency in C
* Understand the fundamental structure and implementation of an OS
* Understand and implement threading in C (write OS side on Arduino for project)


### Reflection
In the sprint 0 retrospective, the main concern that I identified was ensuring that and the rest of my team and I gained enough background knowledge on threading topics to make meaningful decisions about the scope and goals of our project.  In response to that, we focused during the first part of this sprint on gaining a mutual understanding of the concepts and implementation behind threading, allowing us to set reasonable project goals.

During this sprint, we continued using the eduScrum model as before, updating our Trello board to keep track of our goals, deadlines, and progress.  Because everyone kept up to date on the readings, we were well prepared for the sprint review.  

We have been building our knowledge of the libraries and topics that we need to finish implementing our MVP during the latter half of the sprint and are planning to put all of our inidividual components together during the first few days of spirnt 2.  This is slightly behind where we had planned to be at the end of sprint 1, but we focused on ensuring that every team member has an in depth understanding of all areas of the project material.  We also gained a better understanding of how memory and compilation is implemented on the Arduino.


## Links to HFC Solutions
[Chapter 1](https://github.com/kghite/ExercisesInC/tree/master/exercises/ex01)

[Chapter 2](https://github.com/kghite/ExercisesInC/tree/master/exercises/ex02) 


## ThinkOS Reading Questions
[Chapter 1](../reading_questions/think_os_ch1.md)

[Chapter 2](../reading_questions/think_os_ch2.md)

[Chapter 3](../reading_questions/think_os_ch3.md)


## Exam Question
### Question
Based off of ThinkOS Chapter 2 areas not covered by the reading questions:

What are two unwanted interactions that could occur if procceses were not isolated in a system? What are three capabilities found in an operating system with isolated processes?

### Solution

If processes are not isolated, problems could include errors when writing to the same memory address or security risks when a process can access the data of another process with different permissions.  Operating systems control the interaction between processes with multitasking, virtual memory, and device abstraction. 