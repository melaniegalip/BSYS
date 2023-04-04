#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array = (int *)malloc(6 * sizeof(int));
    int *m = &array[3]; // Zeiger auf mittleres Element von array
    free(m);
    return 0;
}
