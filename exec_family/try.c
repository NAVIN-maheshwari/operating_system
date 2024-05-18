#include<stdio.h>
#include<unistd.h>

int main(void) {
    char *file = "C:\\Users\\Navin\\Desktop\\os\\exec_family\\abc.txt";
    char *arg1 = "Hello world!";
	
    execl(file, file, arg1, NULL);

    return 0;
}