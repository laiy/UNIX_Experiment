/*************************************************************************
	> File Name: copy_standard_input_to_standard_output.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Wednesday, February 04, 2015 PM04:26:30 HKT
 ************************************************************************/

#include "apue.h"

int main(int argc, char *argv[]) {
    int c;

    while ((c = getc(stdin)) != EOF)
        if (putc(c, stdout) == EOF)
            err_sys("output error");

    if (ferror(stdin))
        err_sys("input error");

    exit(0);
}

