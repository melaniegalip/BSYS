#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd[2];
    int pid1, pid2;
    const char *message = "Hello from child 1\n";

    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid1 == 0)
    {
        // Child 1 process
        close(fd[0]);               // close read end of pipe
        dup2(fd[1], STDOUT_FILENO); // redirect stdout to write end of pipe
        close(fd[1]);               // close original write end of pipe

        printf(message);
        exit(EXIT_SUCCESS);
    }
    else
    {
        pid2 = fork();
        if (pid2 == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid2 == 0)
        {
            // Child 2 process
            close(fd[1]);              // close write end of pipe
            dup2(fd[0], STDIN_FILENO); // redirect stdin to read end of pipe
            close(fd[0]);              // close original read end of pipe

            char *buf = (char *)malloc(strlen(message) * sizeof(char));
            read(STDIN_FILENO, buf, strlen(message) * sizeof(char));
            printf("Child 2 received: %s", buf);
            exit(EXIT_SUCCESS);
        }
        else
        {
            // Parent process
            int status1, status2;
            waitpid(pid1, &status1, 0);
            waitpid(pid2, &status2, 0);
            printf("Child 1 exited with status %d\n", status1);
            printf("Child 2 exited with status %d\n", status2);
        }
    }

    return 0;
}
