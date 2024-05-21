#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

int buffer[10];
int count = 0;

int Full = 0;
int Empty = 10;

pthread_mutex_t lock;
pthread_cond_t cv_for_producer;
pthread_cond_t cv_for_consumer;

void *produser()
{
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&lock);

        while (Empty == 0)
        {
            printf("Waiting for empty slot\n");
            pthread_cond_wait(&cv_for_producer, &lock);
            sleep(1);
        }

        buffer[count] = 50;
        count++;
        printf("One item produced\n");
        Empty--;
        Full++;

        pthread_cond_signal(&cv_for_consumer);

        pthread_mutex_unlock(&lock);

        sleep(1);
    }
}

void *consumer()
{

    for (int i = 0; i < 10; i++)
    {

        pthread_mutex_lock(&lock);

        while (Full == 0)
        {
            printf("Waiting for item produced\n");
            pthread_cond_wait(&cv_for_consumer, &lock);
            sleep(1);
        }

        count--;
        printf("One item consumed\n");
        Empty++;
        Full--;
        pthread_cond_signal(&cv_for_producer);

        pthread_mutex_unlock(&lock);

        sleep(1);
    }
}

int main()
{
    pthread_t th[2];

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cv_for_producer, NULL);
    pthread_cond_init(&cv_for_consumer, NULL);

    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            pthread_create(&th[i], NULL, &produser, NULL);
        }
        else
        {
            pthread_create(&th[i], NULL, &consumer, NULL);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        pthread_join(th[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cv_for_producer);
    pthread_cond_destroy(&cv_for_consumer);
}