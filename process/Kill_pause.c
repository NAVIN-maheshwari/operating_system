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

SIGCONT = continue the stopped process      

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include<signal.h>

void signal_catching_function(int sig)
{
    printf("Signal is handeled %d\n",sig);  //step4 :- in signal catching function
}

int main() {

    signal(SIGCONT,signal_catching_function);  //step 3 signal is handeled
    pid_t pid = fork();

    if(pid > 0)
    {
        sleep(1);
        
        printf("parent process  \n");
        kill(pid,SIGCONT);  // step2:- signal is sent
    
    }
    else{
        printf("pausing child\n");

        pause();                        //step1 :- process is stopped

        //step5 :- continue the process;

        
        printf("Continue Child process \n");
    }
    return 0;
}
