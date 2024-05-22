#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include<stdlib.h>

pthread_mutex_t read;
pthread_mutex_t write;

int read_count = 0;
int count = 0;
void *writer()
{
  for (int i = 0; i < 10; i++)
  {
    pthread_mutex_lock(&write);

    printf("Writer entered\n");
    count++;
    printf("Write content\n");
    sleep(1);

    pthread_mutex_unlock(&write);

    printf("Writer exit\n");
  }
}
void *reader()
{
  for (int i = 0; i < 10; i++)
  {

    pthread_mutex_lock(&read);
    read_count++;
    if (read_count == 1)
    {
      pthread_mutex_lock(&write);
    }
    pthread_mutex_unlock(&read);

    printf("Reader entered\n");
  
    sleep(1);

    printf("Read content\n");


    pthread_mutex_lock(&read);
    read_count--;
    if (read_count == 0)
    {
      pthread_mutex_unlock(&write);
    }
    pthread_mutex_unlock(&read);   
    printf("Reader exit\n");
  }
}

int main()
{
  pthread_t th[5];

  // Creating a 5 thread 2 reader 3 writer

  pthread_mutex_init(&read, NULL);
  pthread_mutex_init(&write,NULL);

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

  pthread_mutex_destroy(&read);
  pthread_mutex_destroy(&write);
}
