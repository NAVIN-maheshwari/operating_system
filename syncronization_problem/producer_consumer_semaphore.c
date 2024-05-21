#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<semaphore.h>

int buffer[10];
int count =0;

sem_t Full;  //counting semaphore
sem_t Empty; //counting semaphore
sem_t Lock;   //binary semaphore


void*produser()
{
    for (int i = 0; i < 10; i++)
    {
       
     sem_wait(&Empty); 
     sem_wait(&Lock);
       
       buffer[count] = 50;
       count++;
       printf("One item produced\n");
     

     sem_post(&Full);
     sem_post(&Lock);

     sleep(1);

    }
    
   
}

void*consumer()
{
     for (int i = 0; i < 10; i++)
    {
       
     sem_wait(&Full);
     sem_wait(&Lock);
       
      
       count--;
       printf("One item consumed\n");

     sem_post(&Empty);
     sem_post(&Lock);

     sleep(1);

    }
}


int main()
{
   pthread_t th[2];

   sem_init(&Empty,0,10);
   sem_init(&Full,0,0);
   sem_init(&Lock,0,1);

   for(int i = 0;i < 2;i++)
   {
          if(i==0)
          {
               pthread_create(&th[i],NULL,&produser,NULL);
          }
          else{
               pthread_create(&th[i],NULL,&consumer,NULL);
          }
   }

   for (int i = 0; i < 2; i++)
   {
    pthread_join(th[i],NULL);
   }

   sem_destroy(&Empty);
   sem_destroy(&Full);
   sem_destroy(&Lock);
   
}