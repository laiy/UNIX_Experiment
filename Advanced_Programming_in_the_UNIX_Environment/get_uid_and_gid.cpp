/*************************************************************************
	> File Name: get_uid_and_gid.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, February 06, 2015 AM11:47:33 HKT
 ************************************************************************/

#include "apue.h"

int main(int argc, char *argv[]) {
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    exit(0);
}

