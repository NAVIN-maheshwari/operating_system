#include<stdio.h>
#include<sys/types.h>

// Headerfile needed:-

#include<unistd.h>

/*
 1.syntax :- pid_t fork(void)
 2.work :-  Create a new process
 3.return type :-
    -1 if error 
     0 to child process
     pid of child to parent process

 4.fork fails when :- Insufficient storage space is available.

 5.  Number of fork = n
     Then total process = 2^n
     total child process = 2^n-1

*/

int main()
{
   pid_t a = fork();
   pid_t b = fork();

    if(a > 0 && b > 0)
    {
      printf("Parent process \n");
    }
    else if(a > 0 && b == 0)
    {
       printf("Second child of main process\n");
    }
    else if(a == 0 && b > 0)
    {
       printf("First child of main process\n");
    }
    else if(a == 0 && b == 0)
    {
       printf("Child of child process\n");
    }


}