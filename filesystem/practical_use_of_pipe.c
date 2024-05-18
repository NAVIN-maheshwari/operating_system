#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int start, end;

    int sum = 0;
    int arrSize = sizeof(arr) / sizeof(int);
    // fd[0] - read
    // fd[1] - write
    int fd[2];

    int status = pipe(fd);

    if (status == -1)
    {
        printf("Faild to create pipe\n");
    }

    pid_t pid = fork();

    if (pid == 0)
    {
        /*Child process*/
        start = 0;
        end = arrSize / 2;

        for (int i = start; i < end; i++)
        {
            sum += arr[i];
        }

        close(fd[0]);

        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
        exit(0);
    }
    else
    {
        /*Parent process*/

        start = arrSize / 2;
        end = arrSize;
         close(fd[1]);
        for (int i = start; i < end; i++)
        {
            sum += arr[i];
        }

        int get_from_child;
        read(fd[0], &get_from_child, sizeof(get_from_child));

        sum += get_from_child;

        close(fd[0]);
    }

    printf("sum is %d\n", sum);
}
