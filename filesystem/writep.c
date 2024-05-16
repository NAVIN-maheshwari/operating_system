
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

char* buffer = "i am a student of delhi university";
int main()
{
   const char*path = "C:\\Users\\Navin\\Desktop\\os\\filesystem\\abc.txt";

   int file_discriptor = open(path, O_RDWR|O_CREAT|O_APPEND); 

   if(file_discriptor > 0 )
   {
       printf("file opened successfully\n");
       
       printf("Writing in a file\n");

       int x = pwrite(file_discriptor,buffer,34,15);
       
       if(x == -1)
       {
            printf("error in writing in a file\n");
       }
       else
       {
            printf("Number of bytes are written in file %d\n",x); 
       }
     
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