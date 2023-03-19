#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    // Open the file
    close(STDOUT_FILENO); // redirection auf file in open
    int fd = open("p2.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (fd < 0)
    {
        fprintf(stderr, "open file failed\n");
        exit(EXIT_FAILURE);
    }

    // Fork the process
    int pid = fork();
    if (pid == 0)
    {
        // Child process: write to file
        printf("hello, world from child\n");
    }
    else if (pid > 0)
    {
        // Parent process: write to file
        printf("hello, world from parent\n");
    }
    else
    {
        // Fork failed
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
