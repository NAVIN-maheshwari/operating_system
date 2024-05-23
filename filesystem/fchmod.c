/*

chmod:- Set permission to User ,Group, and Other Based on the modes


Syntax:-

    #include <sys/stat.h>
    int chmod(const char *path, mode_t mode);

    mode :- 
      
         1.For particular "USER" :-
             S_IRUSR :-  Set USER read Permission
             S_IWUSR :-  Set USER write Permission
             S_IXUSR :-  Set USER execute Permission

        2.For "GROUP" :-
             S_IRGRP :-  Set GROUP read Permission
             S_IWGRP :-  Set GROUP write Permission
             S_IXGRP :-  Set GROUP execute Permission

        3.For "OTHER" :-
             S_IROTH :-  Set OTHER read Permission
             S_IWOTH :-  Set OTHER write Permission
             S_IXOTH :-  Set OTHER execute  Permission  

Return :-
       
       0 if successfull
       -1 if unsuccessfull



NOTE :- If once the mode is changed then next time chmod can't change the mode.    

*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{
    const char*path = "C:\\Users\\Navin\\Desktop\\os\\filesystem\\abc.txt";
    int fd = open(path, O_RDWR|O_CREAT|O_APPEND);
   
    

   if(fd >= 0 )
   {
    printf("file opened successfully\n");

      int status = fchmod(fd,S_IXUSR |S_IRUSR |S_IWUSR |S_IXGRP |S_IRGRP |S_IWGRP |S_IXOTH |S_IROTH |S_IWOTH );

      if(status == 0)
      {
          printf("Permission changed successfully\n");
      }
      else{
        printf("Error in change mode\n");
      }
   }
   else{
      printf("not opened\n");
   }

   if(close(fd) == 0)
   {
    printf("file closed successfully");
   }
   else{
     printf("Not closed or error\n");
   }

}