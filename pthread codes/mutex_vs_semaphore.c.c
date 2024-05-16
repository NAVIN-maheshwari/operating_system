#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>

int count = 0;
pthread_mutex_t mutex;
sem_t semaphore;
void* myfun1()
{
    for (int i = 0; i < 1000; i++)
    {
       sem_wait(&semaphore);
       count++;
       printf("count is increamented to %d\n",count);
    }
    
}

void* myfun2()
{
   for(int i = 0;i < 1000;i++)
   {
        sem_post(&semaphore);
        usleep(50000);
   }
    
}

int main()
{
   pthread_t t[2];
   
//    pthread_mutex_init(&mutex,NULL);

   sem_init(&semaphore,0,1);

   for (int i = 0; i < 2; i++)
   {
      if(i==0)
      {
        pthread_create(&t[i],NULL,&myfun1,NULL);
      }
      else{
          pthread_create(&t[i],NULL,&myfun2,NULL);
      }
   }

   for (int i = 0; i < 2; i++)
   {
            pthread_join(t[i],NULL);
   }
   

    printf("the value of count = %d\n",count);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&semaphore);
}
