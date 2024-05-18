#include<stdio.h>
#include<unistd.h>
#include<unistd.h>
#include<time.h>

int main()
{
    int fd[2];

    int status = pipe(fd);

    if(status == -1)
    {
        printf("Error\n");
    }

    int pid = fork();

    if(pid > 0)
    {
       
      int x= rand() % 100;

      write(fd[1],&x,sizeof(x));

      printf("written number parent : %d\n",x);

      int y;
      read(fd[0],&y,sizeof(y));

      printf("Readed content parent : %d\n",y);

    }
    else{

      int y;

      read(fd[0],&y,sizeof(y));

      printf("Readed content child : %d\n",y);

        int x = y*10;
      write(fd[1],&x,sizeof(x));
      printf("written number child : %d\n",x);
    }
}