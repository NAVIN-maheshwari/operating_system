/*

setpgid :- create a new group

Syntax :- 
      int setpgid(pid , pgid)

      equivalent to:

      setpgrp() when setpid(0,0)

Return value :-

       -1 is error if unsuccessful
       0  if successful


*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int pid = fork();

    if(pid > 0)
    {
        wait(NULL);
        printf("parent pid : %d\n",getpid());
        printf("parent group id : %d\n",getpgrp());
    }
    else{

        printf("Child pid : %d\n",getpid());
        printf("Child group id Before setsid() : %d\n",getpgrp());

        setpgid(0,getpgrp());

        printf("Child group id After setsid() : %d\n",getpgrp());
    }
}
