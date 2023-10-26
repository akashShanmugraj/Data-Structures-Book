#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *, int, int, int);

int main()
{
    int n, value, *arr, result, i;
    printf("Enter number of array elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n); // Allocating n integers
    for (i = 0; i < n; i++)
    {
        printf("Enter elements %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter search value: ");
    scanf("%d", &value);
    result = binarySearch(arr, 0, n - 1, value);
    printf("The position: %d", result);
    free(arr); // Deallocate memory
    return 0;
}

int binarySearch(int *arr, int low, int high, int value)
{
    int mid;
    if (low > high)
    {
        printf("Element not found\n");
        return -1;
    }
    mid = (low + high) / 2;
    if (arr[mid] == value) // Target found at mid
    {
        printf("Element found in the array\n");
        return mid;
    }
    else if (arr[mid] > value) // Target lesser than mid's value
    {
        binarySearch(arr, low, mid - 1, value);
    }
    else // Target greater than mid's value
    {
        binarySearch(arr, mid + 1, high, value);
    }
}
