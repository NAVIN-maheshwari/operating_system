/*
Getpgid :-Return group id of calling process

Syntax :- 
     
       1. int getpgrp(pid)
       2. It is similar to => int getpgrp()  when "pid = 0"

Return value:-
  
       1.Return process group id of process with process id  = pid
       2.Return -1 if unsuccessful :
            1.Pid is not valid
            2.Pid is belong to another group , we don't have a permission for this

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
      printf("Parent pid : %d AND group id  : %d\n",getpid() , getpgid(getpid()));
    }
    else if(a > 0 && b == 0)
    {
       printf("Second child of main process pid : %d AND group id : %d\n",getpid(),getpgid(getpid()));
    }
    else if(a == 0 && b > 0)
    {
       printf("First child of main process pid : %d AND group id : %d\n",getpid(),getpgid(getpid()));
    }
    else if(a == 0 && b == 0)
    {
       printf("Child of child process id :%d AND Group id : %d\n",getpid(),getpgid(getpid()));
    }


}