#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 0;
    int max_size = 15;
    int *data = malloc(sizeof(int) * max_size);

    for (int i = 0; i < 30; i++)
    {
        if (size == max_size)
        {
            max_size *= 2;
            data = realloc(data, sizeof(int) * max_size);
        }
        data[size] = i;
        size++;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    free(data);

    return 0;
}
