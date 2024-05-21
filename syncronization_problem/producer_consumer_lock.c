#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>

int buffer[10];
int count =0;

int Full=0;  
int Empty=10; 

pthread_mutex_t lock;

void*produser()
{
    for (int i = 0; i < 10; i++)
    {
     pthread_mutex_lock(&lock);
       
     while(Empty == 0)
     {
        printf("Waiting for empty slot\n");
        sleep(1);
     }
     
       
       buffer[count] = 50;
       count++;
       printf("One item produced\n");
       Empty--;
       Full++;

     pthread_mutex_unlock(&lock);

     sleep(1);

    }
    
   
}

void*consumer()
{
    sleep(1);  // <---------- Remove this and see the problem with locks
     for (int i = 0; i < 10; i++)
    {
       
     pthread_mutex_lock(&lock);

     while(Full == 0)
     {
        printf("Waiting for item produced\n");
        sleep(1);
     }
     

       count--;
       printf("One item consumed\n");
       Empty++;
       Full--;

     pthread_mutex_unlock(&lock);

     sleep(1);

    }
}

/*
Note there is a problem with lock in while loop if there is no item produced and if the consumer first entered in
 a critical section then there is lock for infinite if produser wants to produce item but there is a lock
 
 the solution is to use a condition variable
 see the condition variable code
 */


int main()
{
   pthread_t th[2];

  pthread_mutex_init(&lock,NULL);

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

   pthread_mutex_destroy(&lock);
   
}