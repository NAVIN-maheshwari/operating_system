#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
    int fd[2];

    int status = pipe(fd);

    if(status == -1)
    {
        printf("Faild to create pipe\n");
    }

    pid_t pid = fork();

    if(pid == 0)
    {
        /*Child process*/

        printf("Fds of child : %d  and %d\n",fd[0],fd[1]);
    }
    else {

        /*Parent process*/
        printf("Fds of parent : %d  and %d\n",fd[0],fd[1]);
    }
}