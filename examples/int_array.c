#include <stdio.h>
#include "../dyarr.h"

int main()
{
    int *arr = NULL; // Dynamic array of integers, initially NULL

    // Append integers 1 to 10 to the dynamic array
    arrpush(arr, 1);
    arrpush(arr, 2, 3 , 4, 5);

    // Print the contents of the dynamic array
    for (size_t i = 0; i < arrlen(arr); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamic array
    arrfree(arr);

    return 0;
}
