#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // printf("pid:%d\n", getpid());
    if (argc != 3)
    {
        fprintf(stderr, "usage: ./memory-user <memory in MB> <time in seconds>\n");
        exit(1);
    }

    int memCount, timeCount;
    sscanf(argv[1], "%d", &memCount);
    sscanf(argv[2], "%d", &timeCount);

    int meg = 250000; // sizeof(int) == 4
    if (sizeof(int) == 8)
    {
        meg = 125000;
    }

    int *arr = malloc(memCount * meg * sizeof(int));
    if (arr == NULL)
    {
        printf("could not allocate %dMB of memory\n", memCount);
        exit(1);
    }

    printf("running with %dMB for %d seconds...\n", memCount, timeCount);
    time_t start = time(NULL);
    while (time(NULL) - start < timeCount)
    {
        for (int i = 0; i < (memCount * meg); i++)
        {
            arr[i] = 1;
        }
    }

    free(arr);
    printf("done\n");
    return 0;
}
