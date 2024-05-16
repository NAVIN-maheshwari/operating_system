#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<semaphore.h>
#include<stdlib.h>

sem_t semaphore;

void* fun1(void *arg)
{

   printf("( %d ) Waiting for login\n",*(int*)arg);
   sem_wait(&semaphore);
   printf("( %d ) Logged in\n", *(int*)arg);
   sleep(1);
   sem_post(&semaphore);
   printf("( %d ) Logged out\n", *(int*)arg );
   
   free(arg);
   
}
int main(int argc, char const *argv[])
{

    pthread_t th[16];

    sem_init(&semaphore,0,4);
     for(int i = 0 ;i < 16 ; i++)
    {
        int *x = (int*)malloc(4);
        *x =i;
       pthread_create(&th[i],NULL,&fun1,x);
    }

    for (int i = 0; i < 16; i++)
    {
        pthread_join(th[i],NULL);
    }

    sem_destroy(&semaphore);
   
    return 0;
}

