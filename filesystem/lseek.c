/*
 1.syntax:-

            int lseek(int file discriptor, int offset, int whence)  

            offset :- Number of byte (left,right) shift the cursor based on the value of whence

            whence :- 

                1.SEEK_SET :-  the file cursor shall be set to offset bytes.

                2.SEEK_CUR :- the file cursor shall be set to its current location plus offset.

                3.SEEK_END :- the file cursor shall be set to the size of the file plus offset     
           
          2. Return value:-

               offset value from the bigning  
              -1 if error
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

       int return_val = lseek(file_discriptor,10,SEEK_SET);
       int x = read(file_discriptor,buffer,10);
       
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