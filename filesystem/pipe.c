#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    
    //fd[0] - read
    //fd[1] - write
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

       close(fd[0]);

       char* buffer;
       printf("Write into a pipe\n");
       scanf("%s",&buffer);

      int c= write(fd[1],&buffer,sizeof(buffer));
        
       close(fd[1]);

       exit(c);
    }
    else {

        /*Parent process*/
        int size;
        wait(&size);
        close(fd[1]);
        char *buffer[size/(256)];
       
      
        read(fd[0],&buffer,size/256);
      
        printf("%s\n",buffer);
       
        
        close(fd[0]);
    }
}
