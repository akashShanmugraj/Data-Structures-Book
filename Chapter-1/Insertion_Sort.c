// Insertion Sort Algorithm
#include <stdio.h>
#include <stdlib.h>
void InsertionSort(int *arr, int size)
{
    int temp, j, i;
    for (i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int size, i;
    printf("Enter the size of the array:");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        printf("Enter the element[%d]:", i + 1);
        scanf("%d", &arr[i]);
    }
    InsertionSort(arr, size);
    printf("Sorted Array:");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
