#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int arr[10] = {1,2,3,4,5,6,7,8,9,10};

//  ------------Wrong way to pass argument --------------//

/*
void* myfun(void*arg)
{
 
     sleep(1);
     int *x = (int*)arg;

     printf("%d  ",arr[*x]);
    
}

int main()
{
    pthread_t th[10];

    for(int i = 0 ;i < 10 ; i++)
    {
      
        if(pthread_create(th+i,NULL,&myfun,&i))
        {
            perror("Faild to create thread\n");
            return 1;
        }
    }

    for (int i = 0; i < 10; i++)
    {
         if(pthread_join(th[i],NULL))
        {
            return 2;
        }
    }
}

*/

//------------ Correct way -----------------//

void* myfun(void*arg)
{
 
     sleep(1);
     int *x = (int*)arg;

     printf("%d  ",arr[*x]);

     free(arg);
    
}

int main()
{
    pthread_t th[10];

    for(int i = 0 ;i < 10 ; i++)
    {
      int*a = malloc(4);
      *a = i; 
        if(pthread_create(th+i,NULL,&myfun,a))
        {
            perror("Faild to create thread\n");
            return 1;
        }
    }

    for (int i = 0; i < 10; i++)
    {
         if(pthread_join(th[i],NULL))
        {
            return 2;
        }
    }
}