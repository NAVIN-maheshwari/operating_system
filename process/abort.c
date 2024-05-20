#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int pid = fork();

    if(pid > 0)
    {
        printf("forcefully terminating a parent process\n")
        abort();
        printf("parent process \n");
    }
    else{
        printf("Child process\n");
    }
}