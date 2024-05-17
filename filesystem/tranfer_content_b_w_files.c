#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    char*path = "C:\\Users\\Navin\\Desktop\\os\\filesystem\\abc.txt";


    char*path2="C:\\Users\\Navin\\Desktop\\os\\filesystem\\";

    int fd1 = open(path,O_RDWR);
    int fd2 = open(path2,O_RDWR|O_APPEND|O_CREAT); 



    /*  lseek  set the cursor to end of the content and return the current value of cursor*/

    int content_size_in_file1 = lseek(fd1,0,SEEK_END);
    
    /*  again cursor is set to the start of the file*/

    lseek(fd1,0,SEEK_SET);
    

    /*buffer created of size = content of file1*/

    char*buffer[content_size_in_file1];
     
     /*  Content readed from file 1*/

     read(fd1,buffer,content_size_in_file1);
     

     /*content writed in file 2*/
     write(fd2,buffer,content_size_in_file1);


}