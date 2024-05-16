
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
   const char*path1 = "C:\\Users\\Navin\\Desktop\\os\\filesystem\\abc.txt";
   const char*path2 = "C:\\Users\\Navin\\Desktop\\os\\filesystem\\abc.txt";

   int file_discriptor = open(path1, O_RDWR|O_CREAT|O_APPEND); 

   if(file_discriptor > 0 )
   {
       printf("file opened successfully %d \n",file_discriptor);
       
       int copied_path  = link(path1,path2);
       
       if(copied_path == 0 )
       {
           printf("path is dupliceted \n");
       }
       else
       {
           printf("Faild to duplicate the path\n");
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