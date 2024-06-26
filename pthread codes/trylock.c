/*
  Trylock only try if there is already lock then not lock and not wait for unlocking , 
  execute remaining code

// trylock return 0 if it is successful in locking  else return errno

//in case of lock:- if there is already locked then lock wait for unlocking

//if you want to understand the working of lock then replace lock with trylock

*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

pthread_mutex_t mutex;



void* myfun()
{

    /*Locking here*/
    if(pthread_mutex_trylock(&mutex)==0)
    {
        printf("locked successfully\n");
        sleep(5);

        /*Unlocking here*/
        pthread_mutex_unlock(&mutex);
    } 
    else{
        printf("failed in lock\n");
    } 
}

int main()
{

    /* Four process are created here */
    pthread_t th[4];

    pthread_mutex_init(&mutex,NULL);

    for(int i = 0 ;i < 4 ; i++)
    {
     
        if(pthread_create(th+i,NULL,&myfun,NULL))
        {
            perror("Faild to create thread\n");
            return 1;
        }
    }

    for (int i = 0; i < 4; i++)
    {
         if(pthread_join(th[i],NULL))
        {
            perror("Faild to join thread\n");
            return 2;
        }
    }

     pthread_mutex_destroy(&mutex);
}