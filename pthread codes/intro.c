#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/syscall.h>

void* fun1()
{
    printf("i am a thread %ld\n" , pthread_self());
    
    sleep(2);
    
    printf("Thread end %ld\n",syscall(SYS_gettid));  //for thread id (diff b/w pthread_self and syscall)
}
int main(int argc, char const *argv[])
{
     int x = 3;
     pthread_t t1, t2;
    if(pthread_create(&t1,NULL,&fun1,NULL) !=0){
        x++;
        return 1;
    }
    if(pthread_create(&t2,NULL,&fun1,NULL) !=0){
        x++;
        return 2;
    }
    if(pthread_join(t1,NULL) !=0){
        return 3;
    }
    if(pthread_join(t2,NULL)!=0){
        return 4;
    }


   printf("%d",x);

    


    return 0;
}

