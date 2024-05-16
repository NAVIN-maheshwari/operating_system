#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int count = 0;
pthread_mutex_t mutex;
pthread_cond_t  condition_var;
void* myfun1()
{
    for (int i = 0; i < 10; i++)
    {
     pthread_mutex_lock(&mutex);
     count++;
     printf("The value of count is increamented %d\n",count);
     pthread_mutex_unlock(&mutex);
     pthread_cond_signal(&condition_var);
     sleep(1);
    }
    
}

void* myfun2()
{
     pthread_mutex_lock(&mutex);   
    
    for(int i = 0 ; i < 3 ; i++){
        
     while(count <= 2)                 //this locks both t1 and t2 thread infinitly if we are not using cv
     {
        printf("waiting count is %d\n",count);
        pthread_cond_wait(&condition_var,&mutex);
     }
     count-=2;
     printf("count is decreamented %d\n",count);
     pthread_mutex_unlock(&mutex);
        
    }
}

int main()
{
   pthread_t t[2];
   
   pthread_mutex_init(&mutex,NULL);

   pthread_cond_init(&condition_var,NULL);

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
    pthread_cond_destroy(&condition_var);
}
