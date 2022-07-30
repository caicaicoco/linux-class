/*
僵尸进程是当子进程比父进程先结束，而父进程又没有回收子进程，释放子进程占用的资源，
此时子进程将成为一个僵尸进程。如果父进程先退出 ，子进程被init接管，子进程退出后
init会回收其占用的相关资源
危害：导致系统不能产生新的进程
解决方式：可用kill-SIGKILL父进程ID来解决
*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {

    // 创建子进程
    pid_t pid = fork();

    // 判断是父进程还是子进程
    if(pid > 0) {
        while(1) {
            printf("i am parent process, pid : %d, ppid : %d\n", getpid(), getppid());
            sleep(1);
        }

    } else if(pid == 0) {
        // 当前是子进程
        printf("i am child process, pid : %d, ppid : %d\n", getpid(),getppid());
       
    }

    // for循环
    for(int i = 0; i < 3; i++) {
        printf("i : %d , pid : %d\n", i , getpid());
    }

    return 0;
}