#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<process.h>
/*

if we want to replace this program to other program then we use "exec" family function :-

examle:-

char*argv[] = {./abc.exe , NULL}; 

char*environment = {}

_exacl(char* path , argv[0] , argv[1] ....  argv[n-1]);

_exacv(char*path , argv);

_exacvp(char*path , argv);

_execve(const char *path, argv, environment);

_execlp(const char *filename, argv[0] ,argv[1]... argv[n-1] );

_execvp(const char *filename,argv);

_fexecve(int fd, argv, environment); 

p = pathname or path

l = list  (pass array element one by one => arr[0], arr[1], ..... arr[n-1])

e = environment variable (pass environment variable array)

v = vector (pass whole array once) 

*/
int main(int argc, char const *argv[],char*envp[])
{
   const  char* arr[] = {"./redix_sort.exe",NULL};

   const char* env[] = {"PATH = /bin" , NULL};

//   _execl("C:\\Users\\Navin\\Desktop\\codes\\sorting_algos\\redix_sort.exe", arr[0] , arr[1]);
  
//   _execv("C:\\Users\\Navin\\Desktop\\codes\\sorting_algos\\redix_sort.exe",arr);

//   _execvp("C:\\Users\\Navin\\Desktop\\codes\\sorting_algos\\redix_sort.exe",arr);

//   _execve("C:\\Users\\Navin\\Desktop\\codes\\sorting_algos\\redix_sort.exe",arr,env);

//   _execvpe("C:\\Users\\Navin\\Desktop\\codes\\sorting_algos\\redix_sort.exe",arr,env)>>;

//   _execlpe("C:\\Users\\Navin\\Desktop\\codes\\sorting_algos\\redix_sort.exe",arr[0],arr[1],env)>>;

//   _execlp("C:\\Users\\Navin\\Desktop\\codes\\sorting_algos\\redix_sort.exe",arr[0],arr[1]);



        printf("Executed successfully\n");

     
    return 0;
}
