#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include<sys/stat.h>

int main()
{
   int status = mkfifo("path",O_RDWR);
}
