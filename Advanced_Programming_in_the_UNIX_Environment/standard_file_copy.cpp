/*************************************************************************
	> File Name: standard_file_copy.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Wednesday, February 04, 2015 PM04:00:25 HKT
 ************************************************************************/

#include "apue.h"

#define BUFFSIZE 4096

int main(int argc, char *argv[]) {
    int n;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");

    if (n < 0)
        err_sys("read error");

    exit(0);
}

