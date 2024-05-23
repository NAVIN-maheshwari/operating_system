#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t read_lock;
pthread_mutex_t write_lock;

int read_count = 0;
int count = 0;
void *writer()
{
  for (int i = 0; i < 10; i++)
  {
    pthread_mutex_lock(&write_lock);

    printf("Writer entered\n");
    count++;
    printf("Write content\n");
    sleep(1);

    pthread_mutex_unlock(&write_lock);

    printf("Writer exit\n");
  }
}
void *reader()
{
  for (int i = 0; i < 10; i++)
  {

    pthread_mutex_lock(&read_lock);
    read_count++;
    if (read_count == 1)
    {
      pthread_mutex_lock(&write_lock);
    }
    pthread_mutex_unlock(&read_lock);

    printf("Reader entered\n");
  
    sleep(1);

    printf("Read content\n");


    pthread_mutex_lock(&read_lock);
    read_count--;
    if (read_count == 0)
    {
      pthread_mutex_unlock(&write_lock);
    }
    pthread_mutex_unlock(&read_lock);   
    printf("Reader exit\n");
  }
}

int main()
{
  pthread_t th[5];

  // Creating a 5 thread 2 reader 3 writer

  pthread_mutex_init(&read_lock, NULL);
  pthread_mutex_init(&write_lock,NULL);

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

  pthread_mutex_destroy(&read_lock);
  pthread_mutex_destroy(&write_lock);
}
