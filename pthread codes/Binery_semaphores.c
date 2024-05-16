/*
semaphore:-

1.Semaphore declearation:-
     
    sem_t sem1;

2.semaphore initialization :-
    
    sem_init(&sem1 , first,second);

    first = if first = 0 then this semaphore can not be shared with other process (Single process but multithreaded)
            if first = 1 then this semaphore can be shareable with other process

    second = any integer (initial value of semaphore)       

3.Semaphore destroy:-

    sem_destroy(&sem1)

4.Wait on semaphore:-

     sem_wait(&sem1)

     if the value of semaphore is 0 then the new thread wait for signal on "sem1"  or (locked on sem1)   

     else decrease the value of semaphore

5.Release the semaphore:-

      sem_post(&sem1)  

      Increase the value of semaphore    

*/

#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<semaphore.h>

sem_t semaphore;  //declearation
int count = 0;
void* fun1()
{
     for (int i = 0; i < 10000000; i++)
     {
      sem_wait(&semaphore);  //locking
       count++;
      sem_post(&semaphore);  //unlocking
     }
     
     
}
int main(int argc, char const *argv[])
{
  /* I created 2 Thread*/
    pthread_t th[2];

    sem_init(&semaphore,0,1);  //initialization

    
     for(int i = 0 ;i < 2 ; i++)
    {
       pthread_create(&th[i],NULL,&fun1,NULL); // Thread initialization
    }

   
    for (int i = 0; i < 2; i++)
    {
        pthread_join(th[i],NULL); //Thread join
    }

     printf("The value of count is %d\n",count);
    
    sem_destroy(&semaphore); //destroy
   
    return 0;
}

