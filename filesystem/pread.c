
/*  
  similar to read 
  but in this we can read from specific place

  if i want to read from 15th word then offset value is 15;
  
  in my file :- 
  
  "12345678912345hello i am reading"
  
  output :- hello i am

*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

char* buffer[10];
int main()
{
   const char*path = "C:\\Users\\Navin\\Desktop\\os\\filesystem\\abc.txt";

   int file_discriptor = open(path, O_RDWR|O_CREAT); 

   if(file_discriptor > 0 )
   {
       printf("file opened successfully\n");
       
       printf("Reading from file\n");

       int x = pread(file_discriptor,buffer,10,15);
       
       if(x == -1)
       {
            printf("error in reading into a file\n");
       }
       else
       {
            printf("Number of bytes are readed from file %d\n",x); 
            
            printf("Content readed : \n %s\n",buffer);
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