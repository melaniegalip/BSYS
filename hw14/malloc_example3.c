#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = (int *)malloc(10 * sizeof(int));
    free(arr);
    printf("%d\n", arr[4]);
    return 0;
}
