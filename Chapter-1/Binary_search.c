#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *, int, int, int);

int main()
{
    int n, value;
    printf("Enter number of array elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n); // Allocating n integers
    for (int i = 0; i < n; i++)
    {
        printf("Enter elements %d ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter search value: ");
    scanf("%d", &value);
    int result = binarySearch(arr, 0, n - 1, value);
    printf("The position: %d", result);
    free(arr);
    return 0;
}

int binarySearch(int *arr, int low, int high, int value)
{
    if (low > high)
    {
        printf("Element not found\n");
        return -1;
    }
    int mid = (low + high) / 2;
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
