/*************************************************************************
	> File Name: get_pid.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Wednesday, February 04, 2015 PM04:30:36 HKT
 ************************************************************************/

#include "apue.h"

int main(int argc, char *argv[]) {
    printf("hello world from process ID %ld\n", (long)getpid());
    exit(0);
}

