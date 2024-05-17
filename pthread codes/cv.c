#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>

int count =0;

pthread_cond_t cv;
pthread_mutex_t mutex;
void*myfun1()
{
   for(int i =0 ;i < 10;i++)
   {
       pthread_mutex_lock(&mutex);
       
       count++; 
       printf("prodused item %d\n \n",count);
       pthread_cond_signal(&cv);
       // pthread_cond_broadcast(&cv);
        
       pthread_mutex_unlock(&mutex);
       
       sleep(1);
   }
}

void*myfun2()
{
    for(int i =0 ;i < 5;i++)
   {
       pthread_mutex_lock(&mutex);
       
       while(count < 3)
       {
           printf("waiting %d\n \n",count);
           pthread_cond_wait(&cv,&mutex);
           
       }
       count--;
       printf("consumed item %d\n \n",count);
       pthread_mutex_unlock(&mutex);
       sleep(1);
   }
}
int main()
{
    pthread_t t1,t2;
    
    pthread_cond_init(&cv,NULL);
    pthread_mutex_init(&mutex,NULL);
    
    pthread_create(&t1,NULL,&myfun1,NULL);
    pthread_create(&t2,NULL,&myfun2,NULL);

    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    
    printf("%d",count);
    pthread_cond_destroy(&cv);
    pthread_mutex_destroy(&mutex);
    
}





// pthread_cond_wait(&cv,&mutex);

// pthread_cond_signal(&cv);

// pthread_cond_broadcast(&cv);

