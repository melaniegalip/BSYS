#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    int *x = malloc(sizeof(int));
    assert(x != NULL);
    *x = 100;
    printf("(pid:%d), init value of x: %d\n", (int)getpid(), *x);
    int rc = fork();
    if (rc < 0)
    {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child (new process)
        printf("hello, I am child (pid:%d), x: %d\n", (int)getpid(), *x);
        *x = 200;
        printf("new value of x in child process: %d\n", *x);
    }
    else
    {
        printf("hello, I am parent of %d (pid:%d), x: %d\n", rc, (int)getpid(), *x);
        *x = 300;
        printf("new value of x in parent process, x: %d\n", *x);
    }
    return 0;
}