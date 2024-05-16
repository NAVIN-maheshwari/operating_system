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
    //  don't run guss first the output


    if (fork() && fork())
    {
       printf("hello 1 \n");
    }
    else 
    {
        printf("Hello 2\n");
    }

}