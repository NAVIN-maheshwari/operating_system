/*

Pause :- Pause the execution of current process

Syntax :- 
  
      int pause(void)

     

Return value :-

      -1 if error or faild to send signal
      No successful signal is specified   

Header file :-

       #include<unistd.h>

NOTE :-  

   After calling pause the pause it wait's for signal which is caught by signal catching function for pause

   after catching a signal task is performed according to signal is provided       

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>



int main() {
    pid_t pid = fork();

    if(pid > 0)
    {
        
        printf("parent process  \n");
    
    }
    else{
        printf("pausing child\n");
        pause();
        printf("Child process \n");
    }
    return 0;
}
