#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>



void*myfun()
{
   for(int i =0 ;i < 10;i++)
   {
      if(i==5)
      {
          int *x = (int*)malloc(4);
          *x = 5;
          
          
          void*y = (void*)x;
          pthread_exit(y);
      }
      
      printf("i am in thread\n");
   }
}
int main()
{
    pthread_t t1;
    
   
    
    pthread_create(&t1,NULL,&myfun,NULL);
   
    void * x = 0;
    pthread_join(t1,&x); 
   
   
   int *y = (int*)x;
    printf("%d",*y);
    
    
}

