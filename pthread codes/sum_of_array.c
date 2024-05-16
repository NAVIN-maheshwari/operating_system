#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int arr[10] = {1,2,3,4,5,6,7,8,9,10};


void* myfun(void*arg)
{
    int curr_sum = 0;
    int index = *(int*)arg;
 
    for (int i = 0; i < 5; i++)
    {
       curr_sum += arr[index];
       index++;
    }

    *(int*)arg = curr_sum;

    return arg;
}

int main()
{
    int totalsum =0;
    pthread_t th[10];

    for(int i = 0 ;i < 2 ; i++)
    {
      int*a = malloc(4);
      *a = i*5; 
        if(pthread_create(&th[i],NULL,&myfun,a))
        {
            perror("Faild to create thread\n");
            return 1;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        void *res;
         if(pthread_join(th[i],&res))
        {
            return 2;
        }

        totalsum += *(int*)res;
        free(res);  
    }

    printf("total sum will be %d \n",totalsum);
}
