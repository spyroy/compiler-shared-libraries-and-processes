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

OS_task1
operating system assignment
