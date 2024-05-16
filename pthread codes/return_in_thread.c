#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

void* fun1()
{
    printf("i am a thread\n");
    printf("Thread end\n");

    int *x = (int*)malloc(4);

    *x =5;

    return (void*)x;
}
int main(int argc, char const *argv[])
{
   void*x = 0;
     pthread_t t1;
   
    pthread_create(&t1,NULL,&fun1,NULL);
       
    pthread_join(t1,&x);

    int *y = (int*)x;

    printf("%d\n",*y); 
      

    return 0;
}

