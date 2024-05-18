/*
1.Syntax :-
    
     int mkdir(const char *path, modes)

     Create a directory

     header file : - #include <sys/stat.h>

     return value:-

            0 if success
            -1 if error
*/

#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>

int main()
{

    const char*path = "C:\\Users\\Navin\\Desktop\\os\\filesystem\\";

    int status = mkdir(path,S_IRUSR|S_IWUSR|S_IXUSR |S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH);

    if(status == 0)
    {
        printf("directory created successfully\n");
    }
    else{
        printf("faild to create directory\n");
    }
}