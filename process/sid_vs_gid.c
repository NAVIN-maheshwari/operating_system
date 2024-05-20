/*

getsid :- Returns the session id of process specified in pid

Syntax :- 
  
         int getsid(pid);

NOTE :- 
      
Session id is different from groupid.
Groups comes under session       

*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
    int pid = fork();

    if(pid > 0)
    {
        wait(NULL);
        printf("parent pid : %d\n",getpid());
        printf("parent group id : %d\n",getpgrp());
        printf("parent session id : %d\n",getsid(getpid()));
        
    }
    else{

        printf("Child pid : %d\n",getpid());
        printf("Child group id Before setsid() : %d\n",getpgrp());

        setpgrp();

        printf("Child group id After setsid() : %d\n",getpgrp());
        printf("Child session id After setsid() : %d\n",getsid(getpid()));

    }
}
