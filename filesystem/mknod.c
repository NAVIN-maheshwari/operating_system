/*
1.Syntax :-
    
     int mknod(const char *path, int mode, dev_t dev)

     Create a directory , special file like fifo file , or regular file

     dev = device name used in special case , it's value is 0 for others

     header file : - #include <sys/stat.h>

     return value:-

            0 if success
            -1 if error
*/

#include<stdio.h>
#include<sys/stat.h>

int main()
{

    const char*path = "C:\\Users\\Navin\\Desktop\\os\\filesystem\\";

    int status = mknod(path,S_IRUSR|S_IWUSR|S_IXUSR |S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH,0);

    if(status == 0)
    {
        printf("File created successfully\n");
    }
    else{
        printf("faild to create file\n");
    }
}