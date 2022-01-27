# מערכות הפעלה
# מטלה 1
## compiler, shared libraries and processes
Due date – 15/4/2020, 11:59pm


## part A (50%) – compilation and libraries
Intro: when we write a “normal” C application, we have all the source code files.
We compile and link them to a single executable file.
We can also compile our code to a library that can be included to other projects statically or
dynamically.
In this task you are requested to produce a simple C executable, and a shared library that can
be used by this executable. You are also requested to provide a Make file, that will help to
utilize each of the sub tasks.
## Subtask 1
1.1 write a “hello Ariel” program,in a separate file named “hello_Ariel” file (c and
h).
1.2 write a short main “main1_1” that will include “hello_Ariel”, and use it.
1.3 write a make file to compile the code.


## Subtask 2
2.1 compile “hello_ariel” as a shared object (.so) library
2.2 write a short main “main1_2” that will use this library
2.3 compile to a single executable and update the make file.


## Subtask 3
3.1 write a short main “main1_3”, that will load the lib file from subtask 2 in
runtime.
3.2 compile the main and alter the make file.


## Subtask 4
4.1 practice with tools (which functions exist, which libs are used)
4.2 alter the make file to have default build, and clean options.


## part B (50%) – Processes
You are requested to implement a aunching app, that will start a few processes.
## Subtask 1
Start 2 processes as nested childs of the main app.
Like this: App -> process1 -> process 2.

## Subtask 2
Start 2 processes with the same shared memory (like threads).
Like this: 3*App


## Subtask 3
Start a daemon process


## Subtask 4
Modify your app, to have all the above subtasks together.
Show the relevant processes tree that will reflect the tasks result.


to run main1_2 write in the terminal(including the '.'): 
	export LD_LIBRARY_PATH=.

output on terminal when typing pstree 'pid' in main2_1 is: 
	bash───main2_1───main2_1───main2_1

output on terminal when typing pstree 'pid' in main2_2 is: 
	bash───3*[main2_2]

output on terminal when typing pstree grep myDaemon /var/log/syslog in main2_3 is: 
	'date and computer name' myDaemon[8927]: First daemon started. 
	'date and computer name' myDaemon[8927]: First daemon is working. 
	'date and computer name' myDaemon[8927]: First daemon finished and terminated.

output on terminal in main2_4 is all the programs above including process tree at the end.
![image](https://github.com/spyroy/OS_task1/blob/master/photos/Screenshot%20from%202020-04-10%2016-28-16.png)
![image](https://github.com/spyroy/OS_task1/blob/master/photos/Screenshot%20from%202020-04-10%2016-30-33.png)

OS_task1
operating system assignment 


