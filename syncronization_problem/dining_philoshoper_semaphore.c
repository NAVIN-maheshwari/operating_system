#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>

int no_of_philoshoper=5;
sem_t chopstick[5];

int count=0;

void* myfun(void*arg)
{
    int i = *(int*)arg;
    sem_wait(&chopstick[i]);

    //sleep(1) //<---------- if you uncomment this then all the thread stuck in a deadlock 
    
    sem_wait(&chopstick[(i+1)%5]);

    printf("rice eaten %d\n",i);
    count++;
    sleep(1);
    sem_post(&chopstick[i]);
    sem_post(&chopstick[(i+1)%5]);

    printf("Chopstic realesed %d\n",i);


}


int main()
{
   pthread_t th[no_of_philoshoper];


/*   Semaphore initialization */

   for (int i = 0; i < no_of_philoshoper; i++)
   {
      sem_init(&chopstick[i],0,1);
   }

/* Thread creation */

   for (int i = 0; i < no_of_philoshoper; i++)
   {
       int *x = malloc(4);
       *x = i;
       pthread_create(&th[i],NULL,&myfun,x);
   }

/*Thread join*/

   for (int i = 0; i < no_of_philoshoper; i++)
   {
      pthread_join(th[i],NULL);
   }

/* Semaphore destroy*/
    for (int i = 0; i < no_of_philoshoper; i++)
   {
      sem_destroy(&chopstick[i]);
   }
   
   
}