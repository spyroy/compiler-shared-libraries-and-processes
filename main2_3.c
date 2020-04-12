#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>


/*
    output on terminal when typing pstree| grep myDaemon /var/log/syslog is:
    'date and computer name' myDaemon['Deamon pid']: First daemon started.
    'date and computer name' myDaemon['Deamon pid']: First daemon is working.
    'date and computer name' myDaemon['Deamon pid']: First daemon finished and terminated.
*/
int main(){
    pid_t pid;
    printf("starting daemon\n");
    pid = fork();
    if (pid < 0)
        exit(EXIT_FAILURE);
    if (pid > 0)
        exit(EXIT_SUCCESS);
    if(pid == 0){
        chdir("/");
        setsid();
        close(stdout);
        close(stdin);
        close(stderr);
        openlog("myDaemon", LOG_PID, LOG_DAEMON);
        syslog (LOG_NOTICE, "First daemon started.");
        while (1){
            sleep (10);
            break;
        } 
        syslog (LOG_NOTICE, "First daemon is working.");
        while (1){
            sleep (10);
            break;
        }
        syslog (LOG_NOTICE, "First daemon finished and terminated.");
        closelog();
    }
    else{
        printf("daemon PID %d\n",pid);
    }         
}
