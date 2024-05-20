

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t a = fork();
    pid_t b = fork();
    int exitStatus ;

    if (a > 0 && b > 0) {
        printf("Parent process P1: %d\n", getpid());
        printf("parent of parent : %d\n",getppid());
    }

    else if (a > 0 && b == 0) {
        printf("Child process C2: %d\n", getpid());
        printf("parent of c2 : %d\n",getppid());
    }

    else if (a == 0 && b > 0) {
        printf("Child process C1: %d\n", getpid());
        printf("parent of c1 : %d\n",getppid());
    }

    else {
        printf("Child process C21: %d\n", getpid());
        printf("parent of  c21 : %d\n",getppid());
    }

    return 0;
}