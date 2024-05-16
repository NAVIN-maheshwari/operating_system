#include<fcntl.h>
#include<sys/type.h>
// #include<sys/state.h>
int main()
{
    int fd;
    fd = creat("file.txt",S_IWUSR/S_IRUSR)
    if(fd==-1)
    {
        printf("error\n");
    }
    else 
    {
        printf("file created\n");
    }
    close(fd);
}