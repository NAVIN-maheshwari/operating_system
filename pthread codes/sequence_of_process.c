#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include<semaphore.h>



/*  Our sequence of process t4 -> t3 -> t2 -> t1 */


sem_t s1, s2, s3;

void *myfun1()
{
    sem_wait(&s3);
    printf("I am t1\n");
}
void *myfun2()
{
    sem_wait(&s2);
    printf("I am t2\n");
    sem_post(&s3);
}
void *myfun3()
{

    sem_wait(&s1);
    printf("I am t3\n");
    sem_post(&s2);
}
void *myfun4()
{

    printf("I am t4\n");
    sem_post(&s1);
}

int main()
{
    pthread_t t1, t2, t3, t4;

    sem_init(&s1, 0, 0);
    sem_init(&s2, 0, 0);
    sem_init(&s3, 0, 0);

    pthread_create(&t1, NULL, &myfun1, NULL);
    pthread_create(&t2, NULL, &myfun2, NULL);
    pthread_create(&t3, NULL, &myfun3, NULL);
    pthread_create(&t4, NULL, &myfun4, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    sem_destroy(&s1);
    sem_destroy(&s2);
    sem_destroy(&s3);
}
