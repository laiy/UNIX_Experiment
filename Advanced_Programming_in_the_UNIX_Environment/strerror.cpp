/*************************************************************************
	> File Name: strerror.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, February 06, 2015 AM11:44:01 HKT
 ************************************************************************/

#include "apue.h"
#include <errno.h>

int main(int argc, char *argv[]) {
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    exit(0);
}

