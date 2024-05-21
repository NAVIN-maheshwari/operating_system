#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int no_of_philoshoper=5;
pthread_mutex_t chopstick[5];

int count=0;

void* myfun(void*arg)
{
    int i = *(int*)arg;
    pthread_mutex_lock(&chopstick[i]);

    // sleep(1); //<---------- if you uncomment this then all the thread stuck in a deadlock

    pthread_mutex_lock(&chopstick[(i+1)%5]);

    printf("rice eaten %d\n",i);
    count++;
    sleep(1);
    pthread_mutex_unlock(&chopstick[i]);
    pthread_mutex_unlock(&chopstick[(i+1)%5]);

    printf("Chopstic realesed %d\n",i);


}


int main()
{
   pthread_t th[no_of_philoshoper];



   for (int i = 0; i < no_of_philoshoper; i++)
   {
     pthread_mutex_init(&chopstick[i],NULL);
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


    for (int i = 0; i < no_of_philoshoper; i++)
   {
      pthread_mutex_destroy(&chopstick[i]);
   }
   
   
}