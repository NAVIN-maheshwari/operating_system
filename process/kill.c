/*

Kill :- sends a signal to a process or a group of processes 

Syntax :- 
  
      int kill(pid , signal)

      pid > 0    =>  Signal is sent to process specified in pid
      pid = 0    =>  Signal is sent to all process whose group id = sender group id
      pid = -1   =>  Signal is sent to all process for which sender has a pemission
      pid < -1   =>  Signal is sent to all process whose group id = absolute value of pid

Return value :-

      -1 if error or faild to send signal
      0  if successful    


*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<signal.h>



int main() {
    pid_t pid = fork();

    if(pid > 0)
    {
        printf("parent process sending a signal \n");
        kill(pid,SIGKILL);
    }
    else{
        sleep(1);
        printf("Child process \n");
    }
    return 0;
}