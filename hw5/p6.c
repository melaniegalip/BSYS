#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();

    if (pid == -1)
    {
        printf("Fork failed\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        // Child process
        printf("Child process\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        printf("Child process exited with status %d\n", status);
    }

    return 0;
}
