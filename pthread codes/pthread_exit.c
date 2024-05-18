//This is a pefect example for explaining difference between signal and broadcast 


#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>


void* myfun2()
{
    
    for(int i =0;i < 5 ;i++)
    {
        if(i > 2)
        {
            int*x = (int*)malloc(4);
            *x =5;
            pthread_exit((void*)x);
        }
        printf("i am thread\n");
    }
    
}

int main()
{
   pthread_t t[1];
    void*status = 0;
   
   for (int i = 0; i < 1; i++)
   {
     
          pthread_create(&t[i],NULL,&myfun2,NULL);
      
   }
    // pthread_exit(0);

   for (int i = 0; i < 1; i++)
   {
            pthread_join(t[i],&status);
   }




   printf("Main Thread and status = %d\n",*(int*)status);
   
   free(status);
   
}

