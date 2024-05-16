#include<stdio.h>
#include<sys/types.h>

// headerfile required for this :-

#include<unistd.h>

/*

1.stntax:-
2.pid_t getpid(void)
3.return value :- return process id of calling process
4.NOTE :- The getpid() and getppid() function shall always be successful and no return value is reserved to indicate an error.
5.pid_t getppid(void)
6.return parent process id of calling process
7.NO ERROR in both

*/

int main()
{
   pid_t pid = fork();

   if(pid > 0)
   {
      printf("main process id = %d \n",getpid());
      printf("main process parent id = %d\n",getppid());
   }
   else{

      printf("child process id = %d\n",getpid());
      printf("child process parent id = %d\n",getppid());

   }
}


/* SOMETHING INTERSTING IF NEEDED;

 if you execute a program directly from the command line,
 the parent process of the main process is usually the shell process. 
 If you run a program from a graphical user interface, 
 the parent process could be the desktop environment or the window manager

*/