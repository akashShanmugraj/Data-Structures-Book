#include <stdio.h>
#include <stdlib.h>

int Linear_Search(int *, int, int);

int main()
{
    int n, i, element, *arr, result;
    printf("Enter size of array: ");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n); // Allocating n integers
    for (i = 0; i < n; i++)
    {
        printf("Element :");
        scanf("%d", &arr[i]);
    }
    printf("Enter Search Element: ");
    scanf("%d", &element);
    result = Linear_Search(arr, element, n);
    if (result != -1) // If search element  found
    {
        printf("The search element is found at the %d th position in the array", result);
    }
    else // If search element not found
    {
        printf("The element search was not found");
    }
    free(arr); // Deallocate memory
    return 0;
}
int Linear_Search(int *arr, int element, int n)
{
    int i, index = -1; // Initialize index at -1
    for (i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            index = i; 
            break;
        }
    }
    return index; // Returns -1  if search element is not found
}
