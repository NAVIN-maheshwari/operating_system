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

       close(fd[1]);

       int x;
       printf("Write into a pipe\n");
       scanf("%d",&x);

       write(fd[0],&x,sizeof(int));

       close(fd[0]);
    }
    else {

        /*Parent process*/
        close(fd[0]);
        int y;
        read(fd[1],&y,sizeof(int));

        printf("Got from child %d\n",y);
    }
}