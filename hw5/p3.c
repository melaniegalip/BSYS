#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int fd[2];

    // Create a pipe to communicate between the parent and child processes
    if (pipe(fd) < 0)
    {
        fprintf(stderr, "pipe create failed\n");
        exit(EXIT_FAILURE);
    }

    // Create the child process
    int pid = fork();
    if (pid == 0)
    {
        // Child process: print "hello" and write to pipe
        printf("hello\n");
        write(fd[1], "x", 1);
        exit(EXIT_SUCCESS);
    }
    else if (pid > 0)
    {
        // Parent process: wait for input from pipe and print "goodbye"
        char buf;
        read(fd[0], &buf, 1);
        printf("goodbye\n");
    }
    else
    {
        // Fork failed
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
