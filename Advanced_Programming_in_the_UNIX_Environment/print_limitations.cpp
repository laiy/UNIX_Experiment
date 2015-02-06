/*************************************************************************
	> File Name: print_limitations.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, February 06, 2015 PM03:03:43 HKT
 ************************************************************************/

#include "apue.h"
#include <errno.h>
#include <limits.h>

static void pr_sysconf(char *, int);
static void pr_pathconf(char *, char *, int);

int main(int argc, char *argv[]) {
    if (argc != 2)
        err_quit("usage: a.out<dirname>");

    #ifdef ARG_MAX
        printf("ARG_MAX defined to be %ld\n", (long)ARG_MAX + 0);
    #else
        printf("no symbol for ARG_MAX\n");
    #endif
    #ifdef _SC_ARG_MAX
        pr_sysconf((char *)"ARG_MAX =", _SC_ARG_MAX);
    #else
        printf("no symbol for _SC_ARG_MAX\n");
    #endif

    #ifdef MAX_CANON
        printf("MAX_CANON defined to be %ld\n", (long)MAX_CANON + 0);
    #else
        printf("no symbol for MAX_CANON\n");
    #endif
    #ifdef _PC_MAX_CANON
        pr_pathconf((char *)"MAX_CANON =", argv[1], _PC_MAX_CANON);
    #else
        printf("no symbol for _PC_MAX_CANON\n");
    #endif

    exit(0);
}

static void pr_sysconf(char *mesg, int name) {
    long val;

    fputs(mesg, stdout);
    errno = 0;
    if ((val = sysconf(name)) < 0) {
        if (errno != 0) {
            if (errno == EINVAL)
                fputs(" (not supported)\n", stdout);
            else
                err_sys("sysconf error");
        } else {
            fputs(" (no limit)\n", stdout);
        }
    } else {
        printf(" %ld\n", val);
    }
}

static void pr_pathconf(char *mesg, char *path, int name) {
    long val;

    fputs(mesg, stdout);
    errno = 0;
    if ((val = pathconf(path, name)) < 0) {
        if (errno != 0) {
            if (errno == EINVAL)
                fputs(" (not supported)\n", stdout);
            else
                err_sys("pathconf error, path = %s", path);
        } else {
            fputs(" (no limit)\n", stdout);
        }
    } else {
        printf(" %ld\n", val);
    }
}

