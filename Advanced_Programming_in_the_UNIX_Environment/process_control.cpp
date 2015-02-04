/*************************************************************************
	> File Name: process_control.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Wednesday, February 04, 2015 PM05:36:36 HKT
 ************************************************************************/

#include "apue.h"
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;

        if ((pid = fork()) < 0)
            err_sys("fork error");
        else if (pid == 0) { /* child */
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");
        printf("%% ");
    }
    exit(0);
}

