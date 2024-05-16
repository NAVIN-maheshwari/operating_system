#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>

int count = 0;
pthread_mutex_t mutex;
void* myfun()
{
    for (int i = 0; i < 10000000; i++)
    {
        // pthread_mutex_lock(&mutex);
       count++;
    //    pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t th[4];

    pthread_mutex_init(&mutex,NULL);
 
    //---->This is wrong way to create multiple thread this will execute thread sequently<-----

    // for(int i = 0 ;i < 4 ; i++)
    // {
    //     printf("thread %d is started\n",i);
    //     if(pthread_create(th+i,NULL,&myfun,NULL))
    //     {
    //         perror("Faild to create thread\n");
    //         return 1;
    //     }
    //     if(pthread_join(th[i],NULL))
    //     {
    //         return 2;
    //     }

    //     printf("thread %d is finished\n",i);
    // }


    //---------- Right way to create multiple thread-------------//

    for(int i = 0 ;i < 4 ; i++)
    {
        printf("thread %d is started\n",i);
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
            return 2;
        }

        printf("thread %d is finished\n",i);
    }
   
   printf("the value of count = %d\n",count);
    pthread_mutex_destroy(&mutex);
}