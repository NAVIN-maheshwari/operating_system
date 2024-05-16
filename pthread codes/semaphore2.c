//for ordering of thread

#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>

int *ptr;
sem_t semaphore;

void* fun1()
{
    *ptr+=50;
     printf("pointer is increamented %d\n",*ptr);
     sem_post(&semaphore);
}
int main(int argc, char const *argv[])
{

    pthread_t th[1];
    
     ptr = (int*)malloc(4);
     
     *ptr = 30;
    sem_init(&semaphore,0,0);
    
     for(int i = 0 ;i < 1 ; i++)
    {
       pthread_create(&th[i],NULL,&fun1,NULL);
    }

    sem_wait(&semaphore);
    
    printf("Pointer deallocated\n");

    free(ptr);
   
    for (int i = 0; i < 1; i++)
    {
        pthread_join(th[i],NULL);
    }

    sem_destroy(&semaphore);
   
    return 0;
}

