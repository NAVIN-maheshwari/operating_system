
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

char* buffer[50];
int main()
{
   const char*path = "C:\\Users\\Navin\\Desktop\\os\\filesystem\\abc.txt";

   int file_discriptor = open(path, O_RDWR|O_CREAT|O_APPEND); 

   if(file_discriptor > 0 )
   {
       printf("file opened successfully\n");
       
       printf("Reading from file\n");

       int x = read(file_discriptor,buffer,50);
       
       if(x == -1)
       {
            printf("error in Reading from file\n");
       }
       else
       {
            printf("Number of bytes readed from file %d\n",x); 
            
            
            buffer[x] = "\0";
            
            printf("Content readed :- \n %s \n",buffer);
            
            printf("\n");
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