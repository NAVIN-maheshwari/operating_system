#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include<stdlib.h>
#include<semaphore.h>

sem_t read;
sem_t write;
int read_count=0;

int count = 0;
void *writer()
{
  for (int i = 0; i < 10; i++)
  {
    sem_wait(&write);

    printf("Writer entered\n");
    
    
    count++;
    
    
    printf("Write content\n");
    sleep(1);

    sem_post(&write);

    printf("Writer exit\n");
  }
}

void *reader()
{
  for (int i = 0; i < 10; i++)
  {

    sem_wait(&read);
    read_count++;
    if (read_count == 1)
    {
      sem_wait(&write);
    }
    sem_post(&read);

    printf("Reader entered\n");

    sleep(1);

    printf("Read content\n");

    sem_wait(&read);
    read_count--;
    if (read_count == 0)
    {
      sem_post(&write);
    }
    sem_post(&read);

    printf("Reader exit\n");
  }
}

int main()
{
  pthread_t th[5];

  // Creating a 5 thread 2 reader 3 writer

  sem_init(&read, 0 , 1);
  sem_init(&write,0 , 1);

  for (int i = 0; i < 5; i++)
  {
    if (i <= 1)
    {
      pthread_create(&th[i], NULL, &writer, NULL);
    }
    else
    {
      pthread_create(th + i, NULL, &reader, NULL);
    }
  }

  for (int i = 0; i < 5; i++)
  {
    pthread_join(th[i], NULL);
  }

  sem_destroy(&read);
  sem_destroy(&write);
}
