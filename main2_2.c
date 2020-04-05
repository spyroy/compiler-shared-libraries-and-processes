#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZESTACK (1024*1024)
char stack[SIZESTACK+1];

 /*
    output on terminal when typing pstree 'pid' is:
    bash───3*[main2_2]
*/

int child_proc(const char *arg){
    for(int i = 0; i < 10; i++){
        printf("child process arg = %s\n", arg);
        usleep(500000);
    }
    return 0;
}

int first_child(void *params){
    child_proc("first child process");
}

int second_child(void *params){
    child_proc("second child process");
}

int main(int argc, char *argv[]){
    pid_t pid1;
    pid_t pid2;
    pid1 = clone(first_child, stack + SIZESTACK, CLONE_PARENT, 0);
    pid2 = clone(second_child, stack + SIZESTACK, CLONE_PARENT, 0);
    if(pid1 == -1 || pid2 == -1){
        fprintf(stderr, "unable to clone\n");
        exit(1);
    }
    usleep(10000000);
    printf("Done!\n");
    return 0;
}
