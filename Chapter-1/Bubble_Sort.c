// Bubble Sort Algorithm
#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *arr, int size)
{
    int flag, temp, i, j;
    for (i = 0; i < size; i++)
    {
        flag = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

int main()
{
    int size, i;
    printf("Enter the number of elements:");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        printf("Enter the element[%d]:", i + 1);
        scanf("%d", &arr[i]);
    }
    BubbleSort(arr, size);
    printf("Sorted Array:");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
