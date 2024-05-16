//This is a pefect example for explaining difference between signal and broadcast 


#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>


void* myfun2()
{
     printf("In Thread\n");
}

int main()
{
   pthread_t t[5];
   
   for (int i = 0; i < 5; i++)
   {
     
          pthread_create(&t[i],NULL,&myfun2,NULL);
      
   }
    // pthread_exit(0);

   for (int i = 0; i < 5; i++)
   {
            pthread_join(t[i],NULL);
   }


   printf("Main Thread\n");
   
}
