
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
   const char*path = "C:\\Users\\Navin\\Desktop\\os\\filesystem\\abc.txt";

   int file_discriptor = open(path, O_RDWR|O_CREAT|O_APPEND); 

   if(file_discriptor > 0 )
   {
       printf("file opened successfully %d \n",file_discriptor);
       
       int copied_fd = 7;
       
       int return_value  = dup2(file_discriptor,copied_fd);  
       
       // Similar to => fcntl(file_discriptor,F_DUPFD,copied_fd);
       
       if(copied_fd > 0 )
       {
           printf("copied_fd : %d and return_value : %d \n",copied_fd,return_value);
       }
       else
       {
           printf("Faild to create a copy\n");
       }
   }
   else
   {
       perror("not opened\n");
   }

   if(close(file_discriptor) == 0)
   {
    printf("file closed successfully");
   }
   else{
     printf("Not closed or error\n");
   }
}
