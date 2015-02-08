/*************************************************************************
	> File Name: test_lseek_for_stdin.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Sunday, February 08, 2015 PM09:11:08 HKT
 ************************************************************************/

#include "apue.h"

int main(int argc, char *argv[]) {
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek\n");
    else
        printf("seek OK\n");
    exit(0);
}

