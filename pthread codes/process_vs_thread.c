#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
  


int x = 3;       // This x is different for both the processes
int main()
{
     int p = fork();

    if(p == 0)
    {
        x++;       
        printf("child %d\n",x);  
    }
    else{
        wait(NULL);

        printf("parent %d\n",x);
    }
}