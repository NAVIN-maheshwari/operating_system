#include<stdio.h>
#include<pthread.h>

pthread_barrier_t barrier;

void*fun()
{
    printf("Waiting for the barrier\n");

    pthread_barrier_wait(&barrier);

    printf("passed a barrier\n");
}

int main()
{
   pthread_t t[3];

   pthread_barrier_init(&barrier,NULL,3);
   
   for(int i = 0 ;i < 3 ; i++)
    {
      pthread_create(&t[i],NULL,&fun,NULL);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_join(t[i],NULL);
    }

   pthread_barrier_destroy(&barrier);
}
