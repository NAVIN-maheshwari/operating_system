
#include<stdio.h>
#include<fcntl.h>

int main()
{
   const char*path = "C:\\Users\\Navin\\Desktop\\os\\filesystem\\example.txt";

// int file_discriptor = creat(path, S_IRUSR|S_IWUSR|S_IXUSR);  // any mode can be specified here

   int file_discriptor = creat(path, O_RDONLY|O_WRONLY|O_APPEND); //FOR windows

   if(file_discriptor > 0 )
   {
    printf("file created successfully\n");
   }
   else{
    perror("not created\n");
   }

}