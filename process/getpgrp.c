/*
Getpgrp :-Return group id of calling process

Syntax :- 
     
       1. int getpgrp(void)
       2. it is similar to =>  int getpgid(0)

Return value:-
  
       1.Return process group id of current process
       2.no error is specified

*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
   pid_t a = fork();
   pid_t b = fork();

    if(a > 0 && b > 0)
    {
      printf("Parent pid : %d AND group id  : %d\n",getpid() , getpgrp());
    }
    else if(a > 0 && b == 0)
    {
       printf("Second child of main process pid : %d AND group id : %d\n",getpid(),getpgrp());
    }
    else if(a == 0 && b > 0)
    {
       printf("First child of main process pid : %d AND group id : %d\n",getpid(),getpgrp());
    }
    else if(a == 0 && b == 0)
    {
       printf("Child of child process id :%d AND Group id : %d\n",getpid(),getpgrp());
    }


}