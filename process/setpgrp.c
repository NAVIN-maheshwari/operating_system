/*


Setgrp :- Create a new "Group"

Syntax :-
         #include<unistd.h>

         pid_t  setpgrp(void)
   
         1.Create a group , The leader  of this group is calling process
         2.Calling process must not be a leader of another group
         3.Process group id = pid 

Return value :-

         1. Group id if successful in creating a group
         2. -1 if faild         

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

        setpgrp();

        printf("Child group id After setsid() : %d\n",getpgrp());
    }
}
