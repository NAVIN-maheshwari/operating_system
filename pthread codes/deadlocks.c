#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t mutex;

pthread_mutex_t mutex2;
int count = 50;
int count2 = 50;
void*myfun(void*arg)
{  
    
    int*x = (int*)arg;
    //blocking the same thread twice is a deadlock

    // pthread_mutex_lock(&mutex);
    
    if(*x == 0 )
    {
      pthread_mutex_lock(&mutex);
      printf("i locked mutex\n");
      sleep(1);
      pthread_mutex_lock(&mutex2);

    }
    else
    {
      pthread_mutex_lock(&mutex2);
      printf("i locked mutex2\n");
      sleep(1);
      pthread_mutex_lock(&mutex);
        
    }
   
     count++;
     count2++;
    printf("Count is increamented %d count2 is %d\n",count,count2);
    pthread_mutex_unlock(&mutex);
    pthread_mutex_unlock(&mutex2);
}
int main()
{
    pthread_t th[2];

    pthread_mutex_init(&mutex,NULL);
     pthread_mutex_init(&mutex2,NULL);

    for(int i =0 ;i < 2;i++)
    {
        int *x = (int*)malloc(4);
        
        *x = i;
        pthread_create(&th[i],NULL,&myfun,x);
    }

    for (int i = 0; i < 2; i++)
    {
        pthread_join(th[i],NULL);
    }
  
    printf("The Value of count is %d\n",count);
    printf("The value of count2 is %d\n",count2);
    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&mutex2);
    
}