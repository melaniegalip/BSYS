#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;

    pid = fork();
    if (pid == 0)
    {
        // Child process
        printf("Calling execl()...\n");
        execl("/bin/ls", "ls", "-l", NULL);

        printf("execl() failed\n");
    }

    pid = fork();
    if (pid == 0)
    {
        // Child process
        printf("Calling execle()...\n");
        char *envp[] = {"PATH=/usr/bin", NULL};
        execle("/bin/ls", "ls", "-l", NULL, envp);

        printf("execle() failed\n");
    }

    pid = fork();
    if (pid == 0)
    {
        // Child process
        printf("Calling execlp()...\n");
        execlp("ls", "ls", "-l", NULL);

        printf("execlp() failed\n");
    }

    pid = fork();
    if (pid == 0)
    {
        // Child process
        printf("Calling execv()...\n");
        char *argv[] = {"ls", "-l", NULL};
        execv("/bin/ls", argv);

        printf("execv() failed\n");
    }

    pid = fork();
    if (pid == 0)
    {
        // Child process
        printf("Calling execvp()...\n");
        char *argv[] = {"ls", "-l", NULL};
        execvp("ls", argv);

        printf("execvp() failed\n");
    }

    pid = fork();
    if (pid == 0)
    {
        // Child process
        printf("Calling execvpe()...\n");
        char *envp[] = {"PATH=/usr/bin", NULL};
        char *argv[] = {"ls", "-l", NULL};
        execvpe("ls", argv, envp);

        printf("execvpe() failed\n");
    }

    return 0;
}
