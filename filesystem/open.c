
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
   const char*path = "C:\\Users\\Navin\\Desktop\\os\\filesystem\\abc.txt";

   int file_discriptor = open(path, O_RDWR|O_CREAT|O_APPEND); 

   if(file_discriptor > 0 )
   {
    printf("file opened successfully\n");
   }
   else{
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