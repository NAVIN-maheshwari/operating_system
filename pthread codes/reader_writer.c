#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>

pthread_rwlock_t lock;
int count = 0;
void* writer()
{
    for (int i = 0; i < 10; i++)
    {
       pthread_rwlock_wrlock(&lock);

       printf("Writer entered\n"); 
       count++;
       printf("Write content\n");
       sleep(1);
       pthread_rwlock_unlock(&lock);

       printf("Writer exit\n");
    
    }
}
void* reader()
{
    for (int i = 0; i < 10; i++)
    {
       pthread_rwlock_rdlock(&lock);

       printf("Reader entered\n"); 
    
       printf("Read content\n");
         sleep(1);
       pthread_rwlock_unlock(&lock);

       printf("Reader exit\n");
    }
}

int main()
{
    pthread_t th[4];


  //Creating a 5 thread 2 reader 3 writer

    pthread_rwlock_init(&lock,NULL);
 
    for(int i = 0 ;i < 4 ; i++)
    {
        if(i <= 1)
        {
          pthread_create(&th[i],NULL,&writer,NULL);
        }
        else{
            pthread_create(th+i,NULL,&reader,NULL);

        }
    }

    for (int i = 0; i < 4; i++)
    {
         pthread_join(th[i],NULL);
    }
   
      pthread_rwlock_destroy(&lock);
}
