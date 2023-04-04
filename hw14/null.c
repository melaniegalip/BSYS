#include <stdio.h>

int main()
{
    int *pointer = NULL;

    printf("Der Wert von pointer ist %p\n", pointer);
    printf("Der Wert, auf den der Zeiger zeigt, ist %d\n", *pointer);

    return 0;
}
