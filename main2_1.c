#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

 /*
    output on terminal when typing pstree 'pid' is:
    bash───main2_1───main2_1───main2_1
*/
int main(){
    pid_t pid;
    /*creating child*/
    pid = fork();
    if(pid < 0){
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0){

        pid_t pid_child;
        /*creating grandchild*/
        pid_child = fork();
        if(pid_child < 0){
            fprintf(stderr, "Fork Failed");
            return 1;
        }
        else if(pid_child == 0){
            printf("this is grandchild \n");
            usleep(9000000);
        }
        else{
            wait(NULL);
            printf("this is child, grandchild completed \n");
            usleep(9000000);
        }
    }
    else{
        wait(NULL);
        printf("this is parent, child completed \n");
    }
    return 0;
}