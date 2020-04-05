#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    system("./main2_1\n");
    system("./main2_2\n");
    system("./main2_3\n");
    sleep(20);
    system("pstree | grep myDaemon /var/log/syslog");
    return 0;
}